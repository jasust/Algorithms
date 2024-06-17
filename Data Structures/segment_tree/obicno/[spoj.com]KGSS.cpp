/*
  Dat je niz brojeva i upiti dva tipa.
  Upit prvog tipa je oblika i, x, i oznacava
  da treba postaviti vrednost i-tog clana niza
  na x. Drugi upit je oblika x, y, i treba naci
  maksimalnu sumu dva razlicita clana niza koja
  se nalaze izmedju indeksa x i y.
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int MaxN = 1e5 + 20;
const int offset = 131072 + 20;

struct node
{
  int prvi, drugi, sum;
} tree[ offset * 2 ];

struct binarnoDrvece
{
  void update( int idx, int l, int r, int pos, int val )
  {
    if ( l == r )
    {
      tree[ idx ].prvi = 0;
      tree[ idx ].drugi = val;
      tree[ idx ].sum = val;
      return;
    }
    int mid = ( l + r ) / 2;
    if ( pos <= mid ) update( 2 * idx, l, mid, pos, val );
    else update( 2 * idx + 1, mid + 1, r, pos, val );
    int t[ 4 ];
    t[ 0 ] = tree[ 2 * idx ].prvi;
    t[ 1 ] = tree[ 2 * idx ].drugi;
    t[ 2 ] = tree[ 2 * idx + 1 ].prvi;
    t[ 3 ] = tree[ 2 * idx + 1 ].drugi;
    sort( t, t + 4 );
    tree[ idx ].prvi = t[ 3 ];
    tree[ idx ].drugi = t[ 2 ];
    tree[ idx ].sum = t[ 3 ] + t[ 2 ];
  }
  node query( int idx, int l, int r, int levo, int desno )
  {
    if ( levo <= l && r <= desno ) return tree[ idx ];
    int mid = ( l + r ) / 2;
    if ( desno <= mid ) return query( 2 * idx, l, mid, levo, desno );
    if ( levo > mid ) return query( 2 * idx + 1, mid + 1, r, levo, desno );
    node tempL = query( 2 * idx, l, mid, levo, desno );
    node tempR = query( 2 * idx + 1, mid + 1, r, levo, desno );
    node ret;
    int t[ 4 ];
    t[ 0 ] = tempL.prvi;
    t[ 1 ] = tempL.drugi;
    t[ 2 ] = tempR.prvi;
    t[ 3 ] = tempR.drugi;
    sort( t, t + 4 );
    ret.prvi = t[ 3 ];
    ret.drugi = t[ 2 ];
    ret.sum = t[ 3 ] + t[ 2 ];
    return ret;
  }
} segment_tree;

int main()
{
  int n, q;
  scanf( "%d", &n );
  for ( int i = 0; i < n; i++ )
  {
    int x;
    scanf( "%d", &x );
    segment_tree.update( 1, 0, n - 1, i, x );
  }
  scanf( "%d", &q );
  while ( q-- )
  {
    char c[ 3 ];
    int x, y;
    scanf( "%s %d %d", &c, &x, &y );
    if ( c[ 0 ] == 'U' ) segment_tree.update( 1, 0, n - 1, --x, y );
    else printf( "%d\n", segment_tree.query( 1, 0, n - 1, --x, --y ).sum );
  }
  return 0;
}
