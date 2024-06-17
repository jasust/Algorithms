#include <cstdio>

const int offset = 1 << 11;
const int n = 1 << 10;

struct segment_tree
{
  struct node
  {
    int add, sum;
  } tree[ offset << 1 ];
  void update( int idx, int l, int r, int levo, int desno, int val )
  {
    if ( l == r )
    {
      tree[ idx ].add += val;
      tree[ idx ].sum += ( r - l + 1 ) * val;
      return;
    }
    int mid = ( l + r ) >> 1;
    if ( levo <= mid ) update( 2 * idx, l, mid, levo, desno, val );
    if ( desno > mid ) update( 2 * idx + 1, mid + 1, r, levo, desno, val );
    tree[ idx ].sum = tree[ 2 * idx ].sum + tree[ 2 * idx + 1 ].sum + tree[ idx ].add * ( r - l + 1 );
  }
  int query( int idx, int l, int r, int levo, int desno, int skupi )
  {
    if ( levo <= l && r <= desno ) return skupi * ( r - l + 1 ) + tree[ idx ].sum;
    int ret = 0, mid = ( l + r ) >> 1;
    if ( levo <= mid ) ret += query( 2 * idx, l, mid, levo, desno, skupi + tree[ idx ].add );
    if ( desno > mid ) ret += query( 2 * idx + 1, mid + 1, r, levo, desno, skupi + tree[ idx ].add );
    return ret;
  }
} drvo;

int main()
{
  int t, x, y, z;
  while ( 1 )
  {
    scanf( "%d", &t );
    if ( t )
    {
      scanf( "%d %d", &x, &y );
      printf( "%d\n", drvo.query( 1, 0, n - 1, x, y, 0 ) );
    }
    else
    {
      scanf( "%d %d %d", &x, &y, &z );
      drvo.update( 1, 0, n - 1, x, y, z );
    }
  }
  return 0;
}
