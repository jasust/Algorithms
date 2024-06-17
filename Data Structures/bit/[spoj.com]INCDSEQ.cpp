#include <cstdio>
#include <algorithm>

using namespace std;

const int MaxN = 1e4 + 4;
const int MaxK = 54;
const int MOD = 5e6;

int n, k, niz[ MaxN ], sortirani[ MaxN ], DP[ MaxK ][ MaxN ];

struct Fenwick
{
  int tree[ MaxK ][ MaxN ];
  void update( int k, int n, int val )
  {
    for ( int i = n; i < MaxN; i += i & -i ) if ( ( tree[ k ][ i ] += val ) >= MOD ) tree[ k ][ i ] -= MOD;
  }
  int get( int k, int n )
  {
    int ret = 0;
    for ( int i = n; i; i -= i & -i ) if ( ( ret += tree[ k ][ i ] ) >= MOD ) ret -= MOD;
    return ret;
  }
} BIT;

int main()
{
  scanf( "%d %d", &n, &k );
  for ( int i = 0; i < n; i++ )
  {
    scanf( "%d", &niz[ i ] );
    sortirani[ i ] = niz[ i ];
  }
  sort( sortirani, sortirani + n );
  int t = unique( sortirani, sortirani + n ) - sortirani;
  for ( int i = 0; i < n; i++ ) niz[ i ] = lower_bound( sortirani, sortirani + t, niz[ i ] ) - sortirani;
  for ( int i = 0; i < n; i++ )
    for ( int j = 1; j <= k; j++ )
    {
      int &last = DP[ j - 1 ][ niz[ i ] ];
      int now = BIT.get( j - 1, niz[ i ] );
      if ( j == 1 ) now = 1;
      if ( last != now )
      {
        int diff = now;
        if ( ( now -= last ) < 0 ) now += MOD;
        last = diff;
        BIT.update( j, niz[ i ] + 1, now );
      }
    }
  printf( "%d\n", BIT.get( k, n ) );
  return 0;
}
