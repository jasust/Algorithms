#include <cstdio>
#include <vector>

using namespace std;

const int MaxV = 5e4 + 20;
const int offset = 1 << 16;

int V, q, x, y, t, tip, otac[ MaxV ], subtree[ MaxV ], chain[ MaxV ], idx[ MaxV ], cvor[ MaxV ];
char unos[ MaxV ];
vector< vector< int > > adj;

void DFS( int Curr, int Prev )
{
  otac[ Curr ] = Prev;
  subtree[ Curr ] = 1;
  for ( vector< int >::iterator it = adj[ Curr ].begin(); it != adj[ Curr ].end(); it++ )
  {
    if ( *it == Prev ) continue;
    DFS( *it, Curr );
    subtree[ Curr ] += subtree[ *it ];
  }
}

void HLD( int Curr, int Prev, int clr )
{
  idx[ Curr ] = t++;
  cvor[ idx[ Curr ] ] = Curr;
  chain[ Curr ] = clr;
  int idxMax = -1;
  for ( vector< int >::iterator it = adj[ Curr ].begin(); it != adj[ Curr ].end(); it++ )
  {
    if ( *it == Prev ) continue;
    if ( idxMax == -1 || subtree[ *it ] > subtree[ idxMax ] ) idxMax = *it;
  }
  if ( idxMax != -1 ) HLD( idxMax, Curr, clr );
  for ( vector< int >::iterator it = adj[ Curr ].begin(); it != adj[ Curr ].end(); it++ )
  {
    if ( *it == Prev || *it == idxMax ) continue;
    HLD( *it, Curr, *it );
  }
}

struct segment_tree
{
  int tree[ offset << 1 ];
  void update( int idx, int l, int r, int pos )
  {
    if ( l == r )
    {
      tree[ idx ] ^= 1;
      return;
    }
    int mid = ( l + r ) / 2;
    if ( pos <= mid ) update( 2 * idx, l, mid, pos );
    else update( 2 * idx + 1, mid + 1, r, pos );
    tree[ idx ] = tree[ 2 * idx ] + tree[ 2 * idx + 1 ];
  }
  int query( int idx, int l, int r, int levo, int desno )
  {
    if ( levo <= l && r <= desno ) return tree[ idx ];
    int mid = ( l + r ) / 2;
    int ret = 0;
    if ( levo <= mid ) ret += query( 2 * idx, l, mid, levo, desno );
    if ( desno > mid ) ret += query( 2 * idx + 1, mid + 1, r, levo, desno );
    return ret;
  }
  int k_th( int idx, int l, int r, int levo, int desno, int k )
  {
    if ( l == r ) return cvor[ l ];
    int mid = ( l + r ) / 2;
    int tempL = query( 1, 0, V, l > levo ? l : levo, mid < desno ? mid : desno );
    if ( k <= tempL ) return k_th( 2 * idx, l, mid, levo, desno, k );
    else return k_th( 2 * idx + 1, mid + 1, r, levo, desno, k - tempL );
  }
} boje;

int solve( int u, int k )
{
  vector< int > temp;
  while ( u != -1 )
  {
    temp.push_back( u );
    u = otac[ chain[ u ] ];
  }
  for ( vector< int >::reverse_iterator it = temp.rbegin(); it != temp.rend(); it++ )
  {
    int all = boje.query( 1, 0, V, idx[ chain[ *it ] ], idx[ *it ] );
    if ( k > all ) k -= all;
    else return boje.k_th( 1, 0, V, idx[ chain[ *it ] ], idx[ *it ], k );
  }
  return -2;
}

int main()
{
  scanf( "%d %d", &V, &q );
  adj.resize( V );
  scanf( "%s", unos );
  for ( int i = 0; i < V - 1; i++ )
  {
    scanf( "%d %d", &x, &y );
    adj[ --x ].push_back( --y );
    adj[ y ].push_back( x );
  }
  DFS( 0, -1 );
  HLD( 0, -1, 0 );
  for ( int i = 0; i < V; i++ ) if ( unos[ i ] == '0' ) boje.update( 1, 0, V, idx[ i ] );
  while ( q-- )
  {
    scanf( "%d", &tip );
    if ( tip & 1 )
    {
      scanf( "%d %d", &x, &y );
      printf( "%d\n", solve( --y, x ) + 1 );
    }
    else
    {
      scanf( "%d", &x );
      boje.update( 1, 0, V, idx[ --x ] );
    }
  }
  return 0;
}
