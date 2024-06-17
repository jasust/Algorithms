/*
  Data je matrica brojeva i upiti nad njom.
  Upiti prvog tipa menjaju odredjeni clan matrice,
  a upiti drugog tipa zahtevaju ispis sume
  svih clanova unutar nekog kvadrata u matrici.
*/

#include <cstdio>
#include <iostream>

using namespace std;

const int MaxN = ( 1 << 10 ) + 100;

struct Fenwick
{
  int tree[ MaxN ][ MaxN ];
  void init()
  {
    for ( int i = 0; i < MaxN; i++ )
      for ( int j = 0; j < MaxN; j++ ) tree[ i ][ j ] = 0;
  }
  void update( int posI, int posJ, int val )
  {
    for ( int i = posI; i <= MaxN; i += i & -i )
      for ( int j = posJ; j <= MaxN; j += j & -j ) tree[ i ][ j ] += val;
  }
  int sum( int posI, int posJ )
  {
    if ( posI == 0 || posJ == 0 ) return 0;
    int ret = 0;
    for ( int i = posI; i; i -= i & -i )
      for ( int j = posJ; j; j -= j & -j ) ret += tree[ i ][ j ];
    return ret;
  }
} BIT;

int main()
{
  int test;
  scanf( "%d", &test );
  while ( test-- )
  {
    int n;
    scanf( "%d", &n );
    BIT.init();
    while ( 1 )
    {
      char unos[ 12 ];
      scanf( "%s", unos );
      if ( unos[ 0 ] == 'E' ) break;
      if ( unos[ 1 ] == 'E' )
      {
        int i, j, c;
        scanf( "%d %d %d", &i, &j, &c );
        BIT.update( i + 1, j + 1, c - BIT.sum( i + 1, j + 1 ) - BIT.sum( i, j ) + BIT.sum( i, j + 1 ) + BIT.sum( i + 1, j ) );
      }
      else
      {
        int i1, j1, i2, j2;
        scanf( "%d %d %d %d", &i1, &j1, &i2, &j2 );
        printf( "%d\n", BIT.sum( i2 + 1, j2 + 1 ) + BIT.sum( i1, j1 ) - BIT.sum( i2 + 1, j1 ) - BIT.sum( i1, j2 + 1 ) );
      }
    }
    printf( "\n" );
  }
  return 0;
}
