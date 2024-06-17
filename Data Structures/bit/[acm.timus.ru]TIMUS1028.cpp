#include <cstdio>

const int MaxVal = 4e4 + 44;
const int MaxN = 2e4 + 24;

struct Fenwick
{
  int tree[ MaxVal ];
  void update( int idx )
  {
    for ( ++idx; idx < MaxVal; idx += idx & -idx ) tree[ idx ]++;
  }
  int query( int idx )
  {
    int ret = 0;
    for ( ++idx; idx; idx -= idx & -idx ) ret += tree[ idx ];
    return ret;
  }
} BIT;

int n, x, y, cnt[ MaxN ];

int main()
{
  scanf( "%d", &n );
  for ( int i = 0; i < n; i++ )
  {
    scanf( "%d %d", &x, &y );
    cnt[ BIT.query( x ) ]++;
    BIT.update( x );
  }
  for ( int i = 0; i < n; i++ ) printf( "%d\n", cnt[ i ] );
  return 0;
}
