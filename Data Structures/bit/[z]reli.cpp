#include <cstdio>

const int MaxN = 1e5 + 15;
const int MOD = 1e4;

int n, niz[ MaxN ];
long long ret;

struct Fenwick
{
  int tree[ MaxN ];
  void update( int idx )
  {
    for ( int i = idx; i < MaxN; i += i & -i ) tree[ i ]++;
  }
  int sum( int idx )
  {
    int ret = 0;
    for ( int i = idx; i; i -= i & -i ) ret += tree[ i ];
    return ret;
  }
} BIT;

int main()
{
  scanf( "%d", &n );
  for ( int i = 0; i < n; i++ ) scanf( "%d", niz + i );
  for ( int i = n - 1; i >= 0; i-- )
  {
    ret = ( ret + BIT.sum( niz[ i ] ) ) % MOD;
    BIT.update( niz[ i ] );
  }
  printf( "%lld\n", ret );
  return 0;
}
