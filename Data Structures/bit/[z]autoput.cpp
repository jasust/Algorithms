#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxVal = 1e5;
int n, d, x, y, z, ret;

struct Fenwick
{
  int tree[ MaxVal + 20 ];
  void update( int idx, int val )
  {
    for ( int i = idx + 1; i < MaxVal; i += i & -i ) tree[ i ] += val;
  }
  int query( int idx )
  {
    int ret = 0;
    for ( int i = idx + 1; i; i -= i & -i ) ret += tree[ i ];
    return ret;
  }
} BIT;

int main()
{
  scanf( "%d %d", &n, &d );
  while ( n-- ) scanf( "%d %d %d", &x, &y, &z ), BIT.update( x, z );
  for ( int i = d + 1; i < MaxVal - d; i++ ) ret = max( ret, BIT.query( i + d ) - BIT.query( i - d - 1 ) );
  printf( "%d\n", ret );
  return 0;
}
