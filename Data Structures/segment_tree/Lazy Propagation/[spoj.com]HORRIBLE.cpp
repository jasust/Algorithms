/*
  Dat je niz brojeva i upiti dva tipa.
  Prvi upit zahteva da se na sve clanove
  niza u intervalu od l do r doda vrednost d.
  Drugi upit zahteva da se ispise suma svih elemenata
  od l do r.
*/

#include <cstdio>
#include <cstring>

const int MaxN = 1e5 + 20;
const int offset = 131072 + 20;

struct S_Tree
{
  struct node
  {
    long long add, sum;
  } tree[ 2 * offset ];
  void clear()
  {
    memset( tree, 0, sizeof( tree ) );
  }
  void update( int idx, int l, int r, int levo, int desno, int val )
  {
    if ( levo <= l && r <= desno )
    {
      tree[ idx ].add += val;
      tree[ idx ].sum += 1LL * ( r - l + 1 ) * val;
      return;
    }
    int mid = ( l + r ) / 2;
    if ( levo <= mid ) update( 2 * idx, l, mid, levo, desno, val );
    if ( desno > mid ) update( 2 * idx + 1, mid + 1, r, levo, desno, val );
    tree[ idx ].sum = 1LL * ( r - l + 1 ) * tree[ idx ].add + tree[ 2 * idx ].sum + tree[ 2 * idx + 1 ].sum;
  }
  long long query( int idx, int l, int r, int levo, int desno, long long pokupljeno )
  {
    if ( levo <= l && r <= desno ) return pokupljeno * ( r - l + 1 ) + tree[ idx ].sum;
    int mid = ( l + r ) / 2;
    if ( desno <= mid ) return query( 2 * idx, l, mid, levo, desno, pokupljeno + tree[ idx ].add );
    if ( levo > mid ) return query( 2 * idx + 1, mid + 1, r, levo, desno, pokupljeno + tree[ idx ].add );
    return query( 2 * idx, l, mid, levo, desno, pokupljeno + tree[ idx ].add ) + query( 2 * idx + 1, mid + 1, r, levo, desno, pokupljeno + tree[ idx ].add );
  }
} segment_tree;

int main()
{
  int tests;
  scanf( "%d", &tests );
  while ( tests-- )
  {
    int n, q;
    scanf( "%d %d", &n, &q );
    segment_tree.clear();
    while ( q-- )
    {
      int tip, x, y, z;
      scanf( "%d", &tip );
      if ( tip )
      {
        scanf( "%d %d", &x, &y );
        printf( "%lld\n", segment_tree.query( 1, 0, n - 1, --x, --y, 0 ) );
      }
      else
      {
        scanf( "%d %d %d", &x, &y, &z );
        segment_tree.update( 1, 0, n - 1, --x, --y, z );
      }
    }
  }
  return 0;
}
