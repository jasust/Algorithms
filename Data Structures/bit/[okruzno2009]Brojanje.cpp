/*
  Dat je skup brojeva koji je na pocetku prazan.
  Date su operacije dva tipa. Prvi tip operacija
  oznacava da treba da se ubaci element x. Drugi tip
  oznacava da treba da se nadji k-ti po velicini broj
  iz skupa.
*/

#include <cstdio>

const int MaxN = 1 << 17;

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

int find( int tar )
{
  int l = 0, r = 1 << 16;
  while ( l < r )
  {
    int mid = ( l + r ) / 2;
    if ( BIT.sum( mid ) < tar ) l = mid + 1;
    else r = mid;
  }
  return l;
}

int main()
{
  int q, t, x;
  scanf( "%d", &q );
  while ( q-- )
  {
    scanf( "%d %d", &t, &x );
    if ( t & 1 ) BIT.update( ++x );
    else printf( "%d\n", find( x ) - 1 );
  }
  return 0;
}
