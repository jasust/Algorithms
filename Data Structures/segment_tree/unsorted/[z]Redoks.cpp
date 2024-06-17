#include <cstdio>
#include <iostream>

using namespace std;

const int MaxN = 3e5;
const int offset = 524288;

struct segment_tree
{
  struct node
  {
    int cnt[ 10 ], add;
  } tree[ 2 * offset ];
  void init( int idx, int l, int r, int pos, int val )
  {
    if ( l == r )
    {
      tree[ idx ].cnt[ val ]++;
      return;
    }
    int mid = ( l + r ) / 2;
    if ( pos <= mid ) init( 2 * idx, l, mid, pos, val );
    else init( 2 * idx + 1, mid + 1, r, pos, val );
    for ( int i = 0; i < 10; i++ ) tree[ idx ].cnt[ i ] = tree[ 2 * idx ].cnt[ i ] + tree[ 2 * idx + 1 ].cnt[ i ];
  }
  void update( int idx, int l, int r, int levo, int desno )
  {
    if ( levo <= l && r <= desno )
    {
      tree[ idx ].add++;
      if ( tree[ idx ].add >= 10 ) tree[ idx ].add -= 10;
      int temp[ 10 ];
      for ( int i = 0; i < 10; i++ ) temp[ i ] = tree[ idx ].cnt[ ( i + 9 ) % 10 ];
      for ( int i = 0; i < 10; i++ ) tree[ idx ].cnt[ i ] = temp[ i ];
      return;
    }
    int mid = ( l + r ) / 2;
    if ( levo <= mid ) update( 2 * idx, l, mid, levo, desno );
    if ( desno > mid ) update( 2 * idx + 1, mid + 1, r, levo, desno );
    for ( int i = 0; i < 10; i++ ) tree[ idx ].cnt[ i ] = tree[ 2 * idx ].cnt[ i ] + tree[ 2 * idx + 1 ].cnt[ i ];
    int temp[ 10 ];
    for ( int i = 0; i < 10; i++ ) temp[ i ] = tree[ idx ].cnt[ ( i + 10 - tree[ idx ].add ) % 10 ];
    for ( int i = 0; i < 10; i++ ) tree[ idx ].cnt[ i ] = temp[ i ];
  }
  int query( int idx, int l, int r, int levo, int desno, int pokupljeno )
  {
    if ( levo <= l && r <= desno )
    {
      int ret = 0;
      pokupljeno %= 10;
      for ( int i = 0; i < 10; i++ ) ret += ( i + pokupljeno ) % 10 * tree[ idx ].cnt[ i ];
      return ret;
    }
    int mid = ( l + r ) / 2;
    int retL = ( levo <= mid ) ? query( 2 * idx, l, mid, levo, desno, pokupljeno + tree[ idx ].add ) : 0;
    int retR = ( desno > mid ) ? query( 2 * idx + 1, mid + 1, r, levo, desno, pokupljeno + tree[ idx ].add ) : 0;
    return retL + retR;
  }
} dials;

int main()
{
  //freopen( "input.in", "r", stdin );
  int n, q;
  char unos[ MaxN ];
  scanf( "%d %d", &n, &q );
  scanf( "%s", unos );
  for ( int i = 0; i < n; i++ ) dials.init( 1, 0, n - 1, i, unos[ i ] - '0' );
  while ( q-- )
  {
    int l, r;
    scanf( "%d %d", &l, &r );
    printf( "%d\n", dials.query( 1, 0, n - 1, --l, --r, 0 ) );
    dials.update( 1, 0, n - 1, l, r );
  }
  return 0;
}
