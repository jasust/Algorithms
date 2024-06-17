/*
  Dat je niz brojeva i upiti nad njima.
  Svaki upit je oblika l, r, k i potrebno
  je odgovoriti koliko ima brojeva od l do
  r vecih od k.
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int MaxN = 3e4 + 20;
const int MaxQ = 2e5 + 20;

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

struct query
{
  int idx, val, pocetak, kraj, tip;
  query(){}
  query( int _idx, int _val, int _pocetak, int _kraj, int _tip )
  {
    idx = _idx;
    val = _val;
    pocetak = _pocetak;
    kraj = _kraj;
    tip = _tip;
  }
  bool operator < ( const query &A ) const
  {
    if ( val != A.val ) return val > A.val;
    return tip > A.tip;
  }
} niz[ MaxN + MaxQ ];

int n, q, x, y, z, sol[ MaxQ ];

int main()
{
  scanf( "%d", &n );
  for ( int i = 0; i < n; i++ )
  {
    scanf( "%d", &x );
    niz[ i ] = query( i + 1, x, -1, -1, 0 );
  }
  scanf( "%d", &q );
  for ( int i = 0; i < q; i++ )
  {
    scanf( "%d %d %d", &x, &y, &z );
    niz[ n + i ] = query( i + 1, z, x, y, 1 );
  }
  sort( niz, niz + q + n );
  for ( int i = 0; i < q + n; i++ )
    if ( !niz[ i ].tip ) BIT.update( niz[ i ].idx );
    else sol[ niz[ i ].idx ] = BIT.sum( niz[ i ].kraj ) - BIT.sum( niz[ i ].pocetak - 1 );
  for ( int i = 1; i <= q; i++ ) printf( "%d\n", sol[ i ] );
  return 0;
}
