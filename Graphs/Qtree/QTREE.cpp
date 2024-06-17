/*
  Dato je stablo i dati su upiti dve vrste:
  1) Promeni duzinu date ivice
  2) Odredi najduzu ivicu na putu od jednog do drugog cvora
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MaxV = 1e4 + 200;
const int offset = 0x4000;

struct edge
{
  int node, cost, id;
  edge()
  {
  }
  edge( int _node, int _cost, int _id )
  {
    node = _node;
    cost = _cost;
    id = _id;
  }
};

int tests, V, x, y, z, t, otac[ MaxV ], subtree[ MaxV ], chain[ MaxV ], level[ MaxV ], idx[ MaxV ], vrednost[ MaxV ], odgovarajuci[ MaxV ];
char unos[ 12 ];
vector< vector< edge > > adj;

struct segment_tree
{
  int tree[ 2 * offset ];
  void update( int idx, int l, int r, int pos, int val )
  {
    if ( l == r )
    {
      tree[ idx ] = val;
      return;
    }
    int mid = ( l + r ) / 2;
    if ( pos <= mid ) update( 2 * idx, l, mid, pos, val );
    else update( 2 * idx + 1, mid + 1, r, pos, val );
    tree[ idx ] = max( tree[ 2 * idx ], tree[ 2 * idx + 1 ] );
  }
  int query( int idx, int l, int r, int levo, int desno )
  {
    if ( levo > desno ) levo = desno;
    if ( levo <= l && r <= desno ) return tree[ idx ];
    int mid = ( l + r ) / 2;
    return max( levo <= mid ? query( 2 * idx, l, mid, levo, desno ) : 0, desno > mid ? query( 2 * idx + 1, mid + 1, r, levo, desno ) : 0 );
  }
} RMQ;

void DFS( int Curr, int Prev )
{
  otac[ Curr ] = Prev;
  subtree[ Curr ] = 1;
  for ( vector< edge >::iterator it = adj[ Curr ].begin(); it != adj[ Curr ].end(); it++ )
  {
    if ( it->node == Prev ) continue;
    odgovarajuci[ it->id ] = it->node;
    vrednost[ it->node ] = it->cost;
    otac[ it->node ] = Curr;
    level[ it->node ] = level[ Curr ] + 1;
    DFS( it->node, Curr );
    subtree[ Curr ] += subtree[ it->node ];
  }
}

void HLD( int Curr, int Prev, int clr )
{
  idx[ Curr ] = t++;
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

int solve( int u, int v )
{
  int ret = 0;
  if ( u == v ) return ret;
  while ( chain[ u ] != chain[ v ] )
  {
    if ( level[ chain[ u ] ] < level[ chain[ v ] ] ) swap( u, v );
    ret = max( ret, RMQ.query( 1, 0, V, idx[ chain[ u ] ], idx[ u ] ) );
    u = otac[ chain[ u ] ];
  }
  if ( level[ u ] > level[ v ] ) swap( u, v );
  if ( u != v ) ret = max( ret, RMQ.query( 1, 0, V, idx[ u ] + 1, idx[ v ] ) );
  return ret;
}

int main()
{
  scanf( "%d", &tests );
  while ( tests-- )
  {
    scanf( "%d", &V );
    for ( int i = 0; i < V; i++ )
    {
      otac[ i ] = subtree[ i ] = chain[ i ] = level[ i ] = 0;
      idx[ i ] = vrednost[ i ] = odgovarajuci[ i ] = 0;
    }
    adj.clear();
    adj.resize( V );
    for ( int i = 0; i < V - 1; i++ )
    {
      scanf( "%d %d %d", &x, &y, &z );
      adj[ --x ].push_back( edge( --y, z, i ) );
      adj[ y ].push_back( edge( x, z, i ) );
    }
    t = 0;
    DFS( 0, -1 );
    HLD( 0, -1, 0 );
    for ( int i = 0; i < V; i++ ) RMQ.update( 1, 0, V, idx[ i ], vrednost[ i ] );
    while ( 1 )
    {
      scanf( "%s", unos );
      if ( *unos == 'D' ) break;
      scanf( "%d %d", &x, &y );
      if ( *unos == 'C' ) RMQ.update( 1, 0, V, idx[ odgovarajuci[ --x ] ], y );
      if ( *unos == 'Q' ) printf( "%d\n", solve( --x, --y ) );
    }
  }
  return 0;
}

