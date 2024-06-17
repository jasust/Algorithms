/*
  Dato je stablo cije su sve grane
  na pocetku sa vrednoscu 0. Date su operacije
  tipa (a, b), i neophodno je uvecati vrednost
  svih grana na prostom putu od a do b za 1.
  Ispisati krajnje vrednosti svih grana.
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MaxV = 1e5 + 15;
const int offset = 0x20000;

struct edge
{
  int node, ID;
  edge(){}
  edge( int _node, int _ID )
  {
    node = _node;
    ID = _ID;
  }
};

int V, q, x, y, time, dad[ MaxV ], subtree[ MaxV ], dubina[ MaxV ], chain[ MaxV ], idx[ MaxV ], grana[ MaxV ], sol[ MaxV ];
vector< edge > adj[ MaxV ];

struct segment_tree
{
  struct node
  {
    int add, sum;
  } tree[ offset << 1 ];
  void update( int idx, int l, int r, int levo, int desno )
  {
    if ( levo <= l && r <= desno )
    {
      tree[ idx ].add++;
      tree[ idx ].sum += r - l + 1;
      return;
    }
    int mid = ( l + r ) / 2;
    if ( levo <= mid ) update( 2 * idx, l, mid, levo, desno );
    if ( desno > mid ) update( 2 * idx + 1, mid + 1, r, levo, desno );
    tree[ idx ].sum = tree[ 2 * idx ].sum + tree[ 2 * idx + 1 ].sum + ( r - l + 1 ) * tree[ idx ].add;
  }
  int query( int idx, int l, int r, int levo, int desno, int ost )
  {
    if ( levo <= l && r <= desno ) return tree[ idx ].sum + ( r - l + 1 ) * ost;
    int mid = ( l + r ) / 2;
    int ret = 0;
    if ( levo <= mid ) ret += query( 2 * idx, l, mid, levo, desno, ost + tree[ idx ].add );
    if ( desno > mid ) ret += query( 2 * idx + 1, mid + 1, r, levo, desno, ost + tree[ idx ].add );
    return ret;
  }
} ST;

void DFS( int Curr, int Prev )
{
  dad[ Curr ] = Prev;
  subtree[ Curr ] = 1;
  for ( vector< edge >::iterator it = adj[ Curr ].begin(); it != adj[ Curr ].end(); it++ )
    if ( it->node != Prev )
    {
      grana[ it->node ] = it->ID;
      dubina[ it->node ] = dubina[ Curr ] + 1;
      DFS( it->node, Curr );
      subtree[ Curr ] += subtree[ it->node ];
    }
}

void HLD( int Curr, int Prev, int clr )
{
  idx[ Curr ] = time++;
  chain[ Curr ] = clr;
  int idxMax = -1;
  for ( vector< edge >::iterator it = adj[ Curr ].begin(); it != adj[ Curr ].end(); it++ )
    if ( it->node != Prev && ( idxMax == -1 || subtree[ idxMax ] < subtree[ it->node ] ) ) idxMax = it->node;
  if ( ~idxMax ) HLD( idxMax, Curr, clr );
  for ( vector< edge >::iterator it = adj[ Curr ].begin(); it != adj[ Curr ].end(); it++ )
    if ( it->node != Prev && it->node != idxMax ) HLD( it->node, Curr, it->node );
}

void update( int a, int b )
{
  while ( chain[ a ] != chain[ b ] )
  {
    if ( dubina[ chain[ a ] ] < dubina[ chain[ b ] ] ) swap( a, b );
    ST.update( 1, 0, V - 1, idx[ chain[ a ] ], idx[ a ] );
    a = dad[ chain[ a ] ];
  }
  if ( dubina[ a ] > dubina[ b ] ) swap( a, b );
  if ( a != b ) ST.update( 1, 0, V - 1, idx[ a ] + 1, idx[ b ] );
}

int main()
{
  scanf( "%d", &V );
  for ( int i = 0; i < V - 1; i++ )
  {
    scanf( "%d %d", &x, &y );
    adj[ --x ].push_back( edge( --y, i ) );
    adj[ y ].push_back( edge( x, i ) );
  }
  DFS( 0, -1 );
  HLD( 0, -1, 0 );
  scanf( "%d", &q );
  while ( q-- )
  {
    scanf( "%d %d", &x, &y );
    update( --x, --y );
  }
  for ( int i = 1; i < V; i++ ) sol[ grana[ i ] ] = ST.query( 1, 0, V - 1, idx[ i ], idx[ i ], 0 );
  for ( int i = 0; i < V - 1; i++ ) printf( "%d ", sol[ i ] );
  return 0;
}
