/*
  Dat je niz brojeva sortiranih neopadajuce.
  Svaki od upita nad nizom zahteva da se ispise
  koja se vrednost najvise puta pojavljuje od
  i do j, gde su i i j zadati za svaki upit
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int MaxN = 1e5 + 200;
const int offset = 131072 + 100;
const int oo = 1e9;

struct drvo
{
  struct node
  {
    int lVal, lCnt, Cnt, rVal, rCnt;
  } tree[ offset * 2 ];
  void update( int idx, int l, int r, int pos, int val )
  {
    if ( l == r )
    {
      tree[ idx ].lVal = val;
      tree[ idx ].lCnt = 1;
      tree[ idx ].Cnt = 1;
      tree[ idx ].rVal = val;
      tree[ idx ].rCnt = 1;
      return;
    }
    int mid = ( l + r ) / 2;
    if ( pos <= mid ) update( 2 * idx, l, mid, pos, val );
    else update( 2 * idx + 1, mid + 1, r, pos, val );
    if ( tree[ 2 * idx ].lVal == tree[ 2 * idx + 1 ].lVal ) tree[ idx ].lCnt = tree[ 2 * idx ].lCnt + tree[ 2 * idx + 1 ].lCnt;
    else tree[ idx ].lCnt = tree[ 2 * idx ].lCnt;
    tree[ idx ].lVal = tree[ 2 * idx ].lVal;
    if ( tree[ 2 * idx ].rVal == tree[ 2 * idx + 1 ].rVal ) tree[ idx ].rCnt = tree[ 2 * idx ].rCnt + tree[ 2 * idx + 1 ].rCnt;
    else tree[ idx ].rCnt = tree[ 2 * idx + 1 ].rCnt;
    tree[ idx ].rVal = tree[ 2 * idx + 1 ].rVal;
    tree[ idx ].Cnt = max( tree[ 2 * idx ].Cnt, tree[ 2 * idx + 1 ].Cnt );
    if ( tree[ 2 * idx ].rVal == tree[ 2 * idx + 1 ].lVal ) tree[ idx ].Cnt = max( tree[ idx ].Cnt, tree[ 2 * idx ].rCnt + tree[ 2 * idx + 1 ].lCnt );
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
    if ( tempL.lVal == tempR.lVal ) ret.lCnt = tempL.lCnt + tempR.lCnt;
    else ret.lCnt = tempL.lCnt;
    ret.lVal = tempL.lVal;
    if ( tempL.rVal == tempR.rVal ) ret.rCnt = tempL.rCnt + tempR.rCnt;
    else ret.rCnt = tempR.rCnt;
    ret.rVal = tempR.rVal;
    ret.Cnt = max( tempL.Cnt, tempR.Cnt );
    if ( tempL.rVal == tempR.lVal ) ret.Cnt = max( ret.Cnt, tempL.rCnt + tempR.lCnt );
    return ret;
  }
} segment_tree;

int main()
{
  int n, q;
  while ( 1 )
  {
    scanf( "%d", &n );
    if ( n == 0 ) break;
    scanf( "%d", &q );
    for ( int i = 0; i < n; i++ )
    {
      int x;
      scanf( "%d", &x );
      segment_tree.update( 1, 0, n - 1, i, x );
    }
    while ( q-- )
    {
      int x, y;
      scanf( "%d %d", &x, &y );
      printf( "%d\n", segment_tree.query( 1, 0, n - 1, --x, --y ).Cnt );
    }
  }
  return 0;
}
