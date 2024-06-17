/*
  Dat je niz brojeva i niz upita. Odgovor svakog
  od upita je broj razlicitih clanova niza ciji su
  indeksi od l do r.
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MaxN = 3e4 + 20;
const int MaxQ = 2e5 + 20;
const int MaxVal = 1e6 + 10;

struct fenwick
{
  int tree[ MaxVal ];
  void update( int idx, int val )
  {
    while ( idx <= MaxVal )
    {
      tree[ idx ] += val;
      idx += idx & -idx;
    }
  }
  int sum( int idx )
  {
    int ret = 0;
    while ( idx > 0 )
    {
      ret += tree[ idx ];
      idx -= idx & -idx;
    }
    return ret;
  }
} BIT;

struct custom
{
  int begin, end, idx;
} query[ MaxQ ];

bool compare( custom A, custom B )
{
  return A.end < B.end;
  if ( A.end != B.end ) return A.end < B.end;
  return A.begin < B.begin;
}

int n, q, ans[ MaxQ ], niz[ MaxN ], last[ MaxVal ];

int main()
{
  scanf( "%d", &n );
  for ( int i = 1; i <= n; i++ ) scanf( "%d", &niz[ i ] );
  scanf( "%d", &q );
  for ( int i = 0; i < q; i++ )
  {
    scanf( "%d %d", &query[ i ].begin, &query[ i ].end );
    query[ i ].begin;
    query[ i ].end;
    query[ i ].idx = i;
  }
  sort( query, query + q, compare );
  int idx = 0;
  for ( int i = 0; i < q; i++ )
  {
    while ( idx < query[ i ].end )
    {
      idx++;
      if ( last[ niz[ idx ] ] )
        BIT.update( last[ niz[ idx ] ], -1 );
      last[ niz[ idx ] ] = idx;
      BIT.update( idx, 1 );
    }
    ans[ query[ i ].idx ] = BIT.sum( query[ i ].end ) - BIT.sum( query[ i ].begin - 1 );
  }
  for ( int i = 0; i < q; i++ ) printf( "%d\n", ans[ i ] );
  return 0;
}
