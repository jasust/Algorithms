#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 1e5 + 20;

struct edge
{
  int node, cost, id;
  edge() {}
  edge( int _node, int _cost, int _id )
  {
    node = _node;
    cost = _cost;
    id = _id;
  }
};

int tests, n, x, y, z, t, otac[ Maxn ], subtree[ Maxn ], chain[ Maxn ], level[ Maxn ], idx[ Maxn ], vrednost[ Maxn ], odgovarajuci[ Maxn ];
char unos[ 12 ];
vector< vector< edge > > adj;

struct segment_tree
{
  int tree[ 0x40000 ];
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
    ret = max( ret, RMQ.query( 1, 0, n, idx[ chain[ u ] ], idx[ u ] ) );
    u = otac[ chain[ u ] ];
  }
  if ( level[ u ] > level[ v ] ) swap( u, v );
  if ( u != v ) ret = max( ret, RMQ.query( 1, 0, n, idx[ u ] + 1, idx[ v ] ) );
  return ret;
}

int main()
{
  scanf( "%d", &n );
  adj.resize( n );
  for (int i=0; i<n-1; i++)
  {
    scanf("%d %d %d", &x, &y, &z);
    adj[ --x ].push_back( edge( --y, z, i ) );
    adj[ y ].push_back( edge( x, z, i ) );
  }
  DFS( 0, -1 );
  HLD( 0, -1, 0 );
  for ( int i = 0; i < n; i++ ) RMQ.update( 1, 0, n, idx[ i ], vrednost[ i ] );
  while ( 1 )
  {
    scanf( "%s", unos );
    if ( *unos == 'D' ) break;
    scanf( "%d %d", &x, &y );
    if ( *unos == 'C' ) RMQ.update( 1, 0, n, idx[ odgovarajuci[ --x ] ], y );
    if ( *unos == 'Q' ) printf( "%d\n", solve( --x, --y ) );
  }
  return 0;
}
