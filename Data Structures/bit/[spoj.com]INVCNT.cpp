/*
  Data je permutacija brojeva. Odrediti
  koliko ova permutacija sadrzi inverzija.
*/

#include <cctype>
#include <cstdio>

const int MaxVal = 1e7 + 17;
const int MaxN = 2e5 + 25;

struct Fenwick
{
  int tree[ MaxVal ];
  void reset()
  {
    for ( int i = 0; i < MaxVal; i++ ) tree[ i ] = 0;
  }
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

int tsts, n, niz[ MaxN ];

void fast_read( int &x )
{
  x = 0;
  char c;
  while ( !isdigit( c = getchar() ) );
  do x = 10 * x + c - '0'; while ( isdigit( c = getchar() ) );
}

int main()
{
  for ( fast_read( tsts ); tsts--; )
  {
    fast_read( n );
    BIT.reset();
    for ( int i = 0; i < n; i++ ) fast_read( niz[ i ] );
    long long ret = 0;
    for ( int i = n - 1; i >= 0; i-- )
    {
      ret += BIT.query( niz[ i ] - 1 );
      BIT.update( niz[ i ] );
    }
    printf( "%lld\n", ret );
  }
  return 0;
}
