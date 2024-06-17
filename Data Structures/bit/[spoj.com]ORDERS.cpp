#include <cstdio>
#include <cstring>

const int MaxN = 2e5 + 25;

struct Fenwick
{
  int tree[ MaxN ];
  void reset()
  {
    for ( int i = 0; i < MaxN; i++ ) tree[ i ] = 0;
  }
  void update( int idx, int val )
  {
    for ( ; idx < MaxN; idx += idx & -idx ) tree[ idx ] += val;
  }
  int query( int idx )
  {
    int ret = 0;
    for ( ; idx; idx -= idx & -idx ) ret += tree[ idx ];
    return ret;
  }
} BIT;

int tsts, n, niz[ MaxN ], ret[ MaxN ];

int main()
{
  for ( scanf( "%d", &tsts ); tsts--; )
  {
    BIT.reset();
    scanf( "%d", &n );
    for ( int i = 1; i <= n; i++ )
      scanf( "%d", niz + i ), BIT.update( i, 1 );
    for ( int i = n; i >= 1; i-- )
    {
      int tar = i - niz[ i ];
      int lo = 1, hi = n;
      while ( lo <= hi )
      {
        int mid = ( lo + hi ) / 2;
        if ( BIT.query( mid ) >= tar ) hi = mid - 1;
        else lo = mid + 1;
      }
      BIT.update( ret[ i ] = lo, -1 );
    }
    for ( int i = 1; i <= n; i++ ) printf( "%d ", ret[ i ] );
    printf( "\n" );
  }
  return 0;
}

