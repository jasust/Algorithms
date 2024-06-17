/*
  Dat je nesortirani niz brojeva. Proces sortiranja
  se odvija na sledeci nacin: prvi element se pomera
  levo sve dok je levo od njega broj veci od njega.
  Nakon toga drugi element se pomera u levo sve dok
  je manji od trenutnog, itd... Ispisati izgled
  pocetnog niza, ako je dato koliko se svaki element
  pomerio levo.
*/

#include <cctype>
#include <cstdio>
#include <cstring>

const int MaxN = 2e5 + 25;

namespace IO
{
  const int MaxBuffer = 1 << 21;
  char Buffer[MaxBuffer], * Ch = Buffer + MaxBuffer;
  inline char Read_Char ( void )
  {
    if ( Ch == Buffer + MaxBuffer )
    {
      fread ( Buffer, 1, MaxBuffer, stdin );
      Ch = Buffer;
    }
    return * Ch++;
  }
  inline int Read_Int ( void )
  {
    char Ch;
    while ( ! isdigit ( Ch = Read_Char ( ) ) );
    int Ret = Ch - '0';
    while ( isdigit ( Ch = Read_Char ( ) ) ) Ret = ( Ret << 3 ) + ( Ret << 1 ) + ( Ch - '0' );
    return Ret;
  }
  inline int Print_Int ( int Number )
  {
    char StackSize = 0, Stack[10];
    if ( ! Number ) Stack[StackSize++] = '0';
    while ( Number )
    {
      Stack[StackSize++] = ( Number % 10 ) + '0';
      Number /= 10;
    }
    for ( int i = StackSize - 1; i >= 0; i-- ) putchar ( Stack[i] );
    putchar ( ' ' );
  }
};

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
  for ( tsts = IO::Read_Int(); tsts--; )
  {
    BIT.reset();
    n = IO::Read_Int();
    for ( int i = 1; i <= n; i++ )
      niz[ i ] = IO::Read_Int(), BIT.update( i, 1 );
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
    for ( int i = 1; i <= n; i++ ) IO::Print_Int( ret[ i ] );
    putchar( '\n' );
  }
  return 0;
}

