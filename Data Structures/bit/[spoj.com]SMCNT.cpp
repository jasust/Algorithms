/*
  Dat je niz n brojeva. Za svaki od njih
  odrediti koliko ima manjih od njega sa
  desne strane.
*/

#include <cstdio>

const int MaxN = 1e6 + 5;
const int MaxVal = 1e6 + 1;

int n, sol[ MaxN ], niz[ MaxN ];

struct Fenwick_tree
{
  int tree[ MaxVal + 20 ];
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
  while ( scanf( "%d", niz + n++ ) + 1 );
  for ( int i = --n - 1; i >= 0; i-- )
  {
    sol[ i ] = BIT.query( niz[ i ] - 1 );
    BIT.update( niz[ i ] );
  }
  for ( int i = 0; i < n; i++ ) printf( "%d ", sol[ i ] );
  return 0;
}
