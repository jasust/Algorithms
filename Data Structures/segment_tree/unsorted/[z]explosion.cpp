#include <cstdio>
#include <algorithm>

using namespace std;

const int offset = 530000 + 40;
const int MaxN = 1e5 + 321;
const int oo = 1e9;

struct custom
{
  int pos, id, dom;
} niz[ MaxN ];

bool operator < ( custom A, custom B )
{
  return A.pos < B.pos;
}

struct node
{
  int mini, maxi;
} tree[ offset * 2 ];

struct drvo
{
  void init()
  {
    for ( int i = 0; i < offset * 2; i++ )
    {
      tree[ i ].mini = oo;
      tree[ i ].maxi = -oo;
    }
  }
  void update( int idx, int l, int r, int pos, node val )
  {
    if ( l == r )
    {
      tree[ idx ].mini = min( val.mini, tree[ idx ].mini );
      tree[ idx ].maxi = max( val.maxi, tree[ idx ].maxi );
      return;
    }
    int mid = ( l + r ) / 2;
    if ( pos <= mid ) update( 2 * idx, l, mid, pos, val );
    else update( 2 * idx + 1, mid + 1, r, pos, val );
    tree[ idx ].mini = min( tree[ 2 * idx ].mini, tree[ 2 * idx + 1 ].mini );
    tree[ idx ].maxi = max( tree[ 2 * idx ].maxi, tree[ 2 * idx + 1 ].maxi );
  }
  node query( int idx, int l, int r, int levo, int desno )
  {
    if ( desno < l || r < levo ) return ( node ){ oo, -oo };
    if ( levo <= l && r <= desno ) return tree[ idx ];
    int mid = ( l + r ) / 2;
    node tempL = query( 2 * idx, l, mid, levo, desno );
    node tempR = query( 2 * idx + 1, mid + 1, r, levo, desno );
    node ret;
    ret.mini = min( tempL.mini, tempR.mini );
    ret.maxi = max( tempL.maxi, tempR.maxi );
    return ret;
  }
} segment_tree;

int n, Sol, idx, levo[ MaxN ], desno[ MaxN ], LDP[ MaxN ], RDP[ MaxN ];

int main()
{
  scanf( "%d", &n );
  for ( int i = 0; i < n; i++ )
  {
    scanf( "%d", &niz[ i ].pos );
    niz[ i ].id = i;
  }
  for ( int i = 0; i < n; i++ ) scanf( "%d", &niz[ i ].dom );
  sort( niz, niz + n );
  for ( int i = 0; i < n; i++ )
  {
    levo[ i ] = lower_bound( niz, niz + n, ( custom ){ niz[ i ].pos - niz[ i ].dom, niz[ i ].id, 0 } ) - niz;
    desno[ i ] = upper_bound( niz, niz + n, ( custom ){ niz[ i ].pos + niz[ i ].dom, niz[ i ].id, 0 } ) - niz - 1;
  }
  segment_tree.init();
  for ( int i = 0; i < n; i++ ) segment_tree.update( 1, 0, n - 1, i, ( node ){ levo[ i ], desno[ i ] } );
  for ( int i = 0; i < n; i++ )
  {
    LDP[ i ] = segment_tree.query( 1, 0, n - 1, levo[ i ], i ).mini;
    segment_tree.update( 1, 0, n - 1, i, ( node ){ LDP[ i ], -oo } );
  }
  for ( int i = n - 1; i >= 0; i-- )
  {
    RDP[ i ] = segment_tree.query( 1, 0, n - 1, i, desno[ i ] ).maxi;
    segment_tree.update( 1, 0, n - 1, i, ( node ){ oo, RDP[ i ] } );
  }
  for ( int i = n - 1; i >= 0; i-- )
  {
    int temp = segment_tree.query( 1, 0, n - 1, LDP[ i ], i ).maxi;
    temp = segment_tree.query( 1, 0, n - 1, LDP[ i ], temp ).mini;
    if ( temp < LDP[ i ] )
    {
      LDP[ i ] = temp;
      segment_tree.update( 1, 0, n - 1, i, ( node ){ temp, -oo } );
    }
  }
  for ( int i = 0; i < n; i++ )
  {
    int temp = segment_tree.query( 1, 0, n - 1, i, RDP[ i ] ).mini;
    temp = segment_tree.query( 1, 0, n - 1, temp, RDP[ i ] ).maxi;
    if ( temp > RDP[ i ] )
    {
      RDP[ i ] = temp;
      segment_tree.update( 1, 0, n - 1, i, ( node ){ oo, temp } );
    }
  }
  idx = oo;
  Sol = -1;
  for ( int i = 0; i < n; i++ ) if ( RDP[ i ] - LDP[ i ] + 1 >= Sol )
  {
    if ( RDP[ i ] - LDP[ i ] + 1 > Sol ) idx = niz[ i ].id + 1;
    else idx = min( niz[ i ].id + 1, idx );
    Sol = RDP[ i ] - LDP[ i ] + 1;
  }
  printf( "%d %d\n", idx, Sol );
  return 0;
}
