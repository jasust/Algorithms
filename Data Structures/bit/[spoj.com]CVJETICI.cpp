#include <cstdio>

const int MaxN = 1e5 + 5;

int n, x, y, l, r;

struct Fenwick
{
  int tree[ MaxN ];
  void update( int idx, int val )
  {
    for ( int i = ++idx; i < MaxN; i += i & -i ) tree[ i ] += val;
  }
  int query( int idx )
  {
    int ret = 0;
    for ( int i = ++idx; i; i -= i & -i ) ret += tree[ i ];
    return ret;
  }
} BIT;

int main()
{
  scanf( "%d", &n );
  while ( n-- )
  {
    scanf( "%d %d", &x, &y );
    printf( "%d\n", ( l = BIT.query( x ) ) + ( r = BIT.query( y ) ) );
    BIT.update( x, -l );
    BIT.update( x + 1, l );
    BIT.update( y, -r );
    BIT.update( y + 1, r );
    BIT.update( x + 1, 1 );
    BIT.update( y, -1 );
  }
  return 0;
}
