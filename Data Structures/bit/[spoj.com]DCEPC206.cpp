#include <cstdio>

const int MaxN = 1e5 + 5;
const int MaxVal = 1e6 + 1;

int tsts, n, niz[ MaxN ];

struct Fenwick_tree
{
  int tree[ MaxVal + 20 ];
  void reset()
  {
    for ( int i = 0; i <= MaxVal; i++ ) tree[ i ] = 0;
  }
  void update( int idx )
  {
    for ( int i = idx + 1; i <= MaxVal; i += i & -i ) tree[ i ]++;
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
  scanf( "%d", &tsts );
  while ( tsts-- )
  {
    BIT.reset();
    scanf( "%d", &n );
    for ( int i = 0; i < n; i++ ) scanf( "%d", niz + i );
    long long ret = 0LL;
    for ( int i = n - 1; i >= 0; i-- )
    {
      ret += 1LL * niz[ i ] * ( BIT.query( MaxVal - 1 ) - BIT.query( niz[ i ] ) );
      BIT.update( niz[ i ] );
    }
    printf( "%lld\n", ret );
  }
  return 0;
}
