#include <set>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int MaxN = 1e5 + 20;

int n, q, cnt;
set< string > lista;

struct ans
{
  int idx, ret;
  ans()
  {
  }
  ans( int _idx, int _ret )
  {
    idx = _idx;
    ret = _ret;
  }
  bool operator < ( const ans &A ) const
  {
    return idx < A.idx;
  }
} resenje[ MaxN ];

struct custom
{
  int idx, tip;
  string rec;
  custom()
  {
  }
  custom( int _idx, int _tip, string _rec )
  {
    idx = _idx;
    tip = _tip;
    rec = _rec;
  }
  bool operator < ( const custom &A ) const
  {
    if ( rec != A.rec ) return rec < A.rec;
    return tip < A.tip;
  }
} niz[ MaxN ];

struct FenwickTree
{
  int tree[ MaxN ];
  void update( int idx )
  {
    for ( int i = idx; i < MaxN; i += i & -i ) tree[ i ]++;
  }
  int query( int idx )
  {
    int ret = 0;
    for ( int i = idx; i; i -= i & -i ) ret += tree[ i ];
    return ret;
  }
} BIT;

int main()
{
  scanf( "%d", &q );
  char tip[ 10 ], unos[ 123 ];
  for ( int i = 1; i <= q; i++ )
  {
    scanf( "%s", tip );
    scanf( "%s", unos );
    for ( int j = 0; unos[ j ]; j++ ) if ( unos[ j ] < 'a' ) unos[ j ] += 32;
    if ( tip[ 0 ] == 'A' )
    {
      if ( lista.find( unos ) != lista.end() ) continue;
      lista.insert( unos );
      niz[ n++ ] = custom( i, 1, unos );
    }
    else niz[ n++ ] = custom( i, 0, lista.find( unos ) != lista.end() ? unos : "@" );
  }
  sort( niz, niz + n );
  for ( int i = 0; i < n; i++ )
    if ( niz[ i ].tip ) BIT.update( niz[ i ].idx );
    else
    {
      if ( niz[ i ].rec[ 0 ] == '@' ) resenje[ cnt++ ] = ans( niz[ i ].idx, -1 );
      else resenje[ cnt++ ] = ans( niz[ i ].idx, BIT.query( niz[ i ].idx ) );
    }
  sort( resenje, resenje + cnt );
  for ( int i = 0; i < cnt; i++ )
    if ( resenje[ i ].ret == -1 ) printf( "no such word\n" );
    else printf( "%d\n", resenje[ i ].ret );
  return 0;
}
