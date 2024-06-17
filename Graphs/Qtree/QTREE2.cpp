/*
  Dato je stablo i dati su upiti dve vrste
  1) Naci rastojanje od cvora a do cvora b
  2) Naci k-ti po redu cvor na putu od a do b
*/

#include <cstdio>
#include <vector>

using namespace std;

const int MaxV = 1e4 + 20;

struct edge
{
  int node, cost;
  edge()
  {
  }
  edge( int _node, int _cost )
  {
    node = _node;
    cost = _cost;
  }
};

int V, x, y, z, t, tests, dubina[ MaxV ], subtree[ MaxV ], otac[ MaxV ], chain[ MaxV ], dist[ MaxV ], idx[ MaxV ], cvor[ MaxV ];
char unos[ 20 ];
vector< vector< edge > > adj;

void DFS( int Curr, int Prev )
{
  otac[ Curr ] = Prev;
  subtree[ Curr ] = 1;
  for ( vector< edge >::iterator it = adj[ Curr ].begin(); it != adj[ Curr ].end(); it++ )
  {
    if ( it->node == Prev ) continue;
    dubina[ it->node ] = dubina[ Curr ] + 1;
    dist[ it->node ] = dist[ Curr ] + it->cost;
    DFS( it->node, Curr );
    subtree[ Curr ] += subtree[ it->node ];
  }
}

void HLD( int Curr, int Prev, int clr )
{
  idx[ Curr ] = t++;
  cvor[ idx[ Curr ] ] = Curr;
  chain[ Curr ] = clr;
  int idxMax = -1;
  for ( vector< edge >::iterator it = adj[ Curr ].begin(); it != adj[ Curr ].end(); it++ )
  {
    if ( it->node == Prev ) continue;
    if ( idxMax == -1 || subtree[ it->node ] > subtree[ idxMax ] ) idxMax = it->node;
  }
  if ( idxMax != -1 ) HLD( idxMax, Curr, clr );
  for ( vector< edge >::iterator it = adj[ Curr ].begin(); it != adj[ Curr ].end(); it++ )
  {
    if ( it->node == Prev || it->node == idxMax ) continue;
    HLD( it->node, Curr, it->node );
  }
}

int LCA( int u, int v )
{
  while ( chain[ u ] != chain[ v ] )
    if ( dubina[ chain[ u ] ] > dubina[ chain[ v ] ] ) u = otac[ chain[ u ] ];
    else v = otac[ chain[ v ] ];
  return dubina[ u ] < dubina[ v ] ? u : v;
}

int solve( int u, int v, int k )
{
  int lca = LCA( u, v );
  if ( dubina[ u ] + dubina[ v ] - 2 * dubina[ lca ]  + 1 < k ) return -3;
  if ( k > dubina[ u ] - dubina[ lca ] + 1 )
  {
    k = dubina[ v ] - dubina[ lca ] + 1 - ( k - dubina[ u ] + dubina[ lca ] - 1 );
    u = v;
  }
  while ( k > dubina[ u ] - dubina[ chain[ u ] ] + 1 )
  {
    k -= dubina[ u ] - dubina[ chain[ u ] ] + 1;
    u = otac[ chain[ u ] ];
  }
  return cvor[ idx[ u ] - k + 1 ];
}

int main()
{
  scanf( "%d", &tests );
  while ( tests-- )
  {
    scanf( "%d", &V );
    adj.clear();
    adj.resize( V );
    for ( int i = 0; i < V; i++ ) dubina[ i ] = subtree[ i ] = otac[ i ] = chain[ i ] = dist[ i ] = 0;
    for ( int i = 0; i + 1 < V; i++ )
    {
      scanf( "%d %d %d", &x, &y, &z );
      adj[ --x ].push_back( edge( --y, z ) );
      adj[ y ].push_back( edge( x, z ) );
    }
    t = 0;
    DFS( 0, -1 );
    HLD( 0, -1, 0 );
    while ( 1 )
    {
      scanf( "%s", unos );
      if ( unos[ 0 ] == 'D' && unos[ 1 ] == 'O' ) break;
      if ( *unos == 'D' )
      {
        scanf( "%d %d", &x, &y );
        printf( "%d\n", dist[ --x ] + dist[ --y ] - 2 * dist[ LCA( x, y ) ] );
      }
      if ( *unos == 'K' )
      {
        scanf( "%d %d %d", &x, &y, &z );
        printf( "%d\n", solve( --x, --y, z ) + 1 );
      }
    }
    printf( "\n" );
  }
  return 0;
}
