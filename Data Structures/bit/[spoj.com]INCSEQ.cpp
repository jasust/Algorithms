#include <cstdio>
#include <algorithm>

using namespace std;

const int MaxN = 1e4 + 4;
const int MaxK = 54;
const int MOD = 5e8;

int n, k, niz[ MaxN ], mapa[ MaxN ], sortirani[ MaxN ];

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
  for ( int i = 0; i < n; i++ ) mapa[ i ] = lower_bound( sortirani, sortirani + n, niz[ i ] ) - sortirani;
  for ( int i = 0; i < n; i++ )
    for ( int j = 1; j <= k; j++ ) BIT.update( j, mapa[ i ] + 1, ( j == 1 ) ? 1 : BIT.get( j - 1, mapa[ i ] ) );
  printf( "%d\n", BIT.get( k, n ) );
  return 0;
}
