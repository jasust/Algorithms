/*Dato je stablo i dati su upiti koji se sastoje u tome da je neophodno
  za data dva cvora odrediti najdubljeg zajednickog pretka. */
#include <cstdio>
#include <vector>
using namespace std;

const int MaxV = 1e6 + 20;

int cnt[ MaxV ], idx[ MaxV ], otac[ MaxV ], dubina[ MaxV ];
vector< vector< int > > adj;

void DFS( int Curr, int Prev )
{
  cnt[ Curr ] = 1;
  for ( vector< int >::iterator it = adj[ Curr ].begin(); it != adj[ Curr ].end(); it++ )
  {
    if ( *it == Prev ) continue;
    otac[ *it ] = Curr;
    dubina[ *it ] = dubina[ Curr ] + 1;
    DFS( *it, Curr );
    cnt[ Curr ] += cnt[ *it ];
  }
}

void HLD( int Curr, int Prev, int clr )
{
  idx[ Curr ] = clr;
  int idxMax = -1;
  for ( vector< int >::iterator it = adj[ Curr ].begin(); it != adj[ Curr ].end(); it++ )
  {
    if ( *it == Prev ) continue;
    if ( idxMax == -1 || cnt[ *it ] > cnt[ idxMax ] ) idxMax = *it;
  }
  if ( idxMax != -1 ) HLD( idxMax, Curr, clr );
  for ( vector< int >::iterator it = adj[ Curr ].begin(); it != adj[ Curr ].end(); it++ )
  {
    if ( *it == Prev || *it == idxMax ) continue;
    HLD( *it, Curr, *it );
  }
}

int LCA( int u, int v )
{
  while ( idx[ u ] != idx[ v ] )
  {
    if ( dubina[ idx[ u ] ] > dubina[ idx[ v ] ] ) u = otac[ idx[ u ] ];
    else v = otac[ idx[ v ] ];
  }
  if ( dubina[ u ] < dubina[ v ] ) return u;
  return v;
}

int main()
{
  int V, q, x, y;
  scanf( "%d %d", &V, &q );
  adj.resize( V );
  while ( --V )
  {
    scanf( "%d %d", &x, &y );
    adj[ --x ].push_back( --y );
    adj[ y ].push_back( x );
  }
  DFS( 0, -1 );
  HLD( 0, -1, 0 );
  while ( q-- )
  {
    scanf( "%d %d", &x, &y );
    printf( "%d\n", LCA( --x, --y ) + 1 );
  }
  return 0;
}
