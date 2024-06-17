/*
  Isto kao zadatak GSS1, samo sto postoji
  i upit koji menja clan niza.
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int MaxN = 131072 + 30;

struct node
{
  int l, r, s, max;
};

struct custom
{
  node tree[ 2 * MaxN ];
  void make( int idx, int levi, int desni, const int niz[] )
  {
    if ( levi == desni )
    {
      tree[ idx ].l = niz[ levi ];
      tree[ idx ].r = niz[ levi ];
      tree[ idx ].s = niz[ levi ];
      tree[ idx ].max = niz[ levi ];
      return;
    }
    int mid = ( levi + desni ) / 2;
    make( 2 * idx, levi, mid, niz );
    make( 2 * idx + 1, mid + 1, desni, niz );
    tree[ idx ].l = max( tree[ 2 * idx ].l, tree[ 2 * idx ].s + tree[ 2 * idx + 1 ].l );
    tree[ idx ].r = max( tree[ 2 * idx + 1 ].r, tree[ 2 * idx + 1 ].s + tree[ 2 * idx ].r );
    tree[ idx ].s = tree[ 2 * idx ].s + tree[ 2 * idx + 1 ].s;
    tree[ idx ].max = max( max( tree[ 2 * idx ].max, tree[ 2 * idx + 1 ].max ), tree[ 2 * idx ].r + tree[ 2 * idx + 1 ].l );
  }
  node update( int idx, int levi, int desni, const int &pos, const int &val )
  {
    if ( levi == desni )
    {
      tree[ idx ].l = val;
      tree[ idx ].r = val;
      tree[ idx ].s = val;
      tree[ idx ].max = val;
      return tree[ idx ];
    }
    int mid = ( levi + desni ) / 2;
    if ( pos <= mid ) update( 2 * idx, levi, mid, pos, val );
    else update( 2 * idx + 1, mid + 1, desni, pos, val );
    tree[ idx ].l = max( tree[ 2 * idx ].l, tree[ 2 * idx ].s + tree[ 2 * idx + 1 ].l );
    tree[ idx ].r = max( tree[ 2 * idx + 1 ].r, tree[ 2 * idx + 1 ].s + tree[ 2 * idx ].r );
    tree[ idx ].s = tree[ 2 * idx ].s + tree[ 2 * idx + 1 ].s;
    tree[ idx ].max = max( max( tree[ 2 * idx ].max, tree[ 2 * idx + 1 ].max ), tree[ 2 * idx ].r + tree[ 2 * idx + 1 ].l );
  }
  node get( int idx, int levi, int desni, int a, int b )
  {
    if ( a <= levi && desni <= b ) return tree[ idx ];
    int mid = ( levi + desni ) / 2;
    if ( b <= mid ) return get( 2 * idx, levi, mid, a, b );
    if ( a > mid ) return get( 2 * idx + 1, mid + 1, desni, a, b );
    node idiL, idiD, ret;
    idiL = get( 2 * idx, levi, mid, a, b );
    idiD = get( 2 * idx + 1, mid + 1, desni, a, b );
    ret.l = max( idiL.l, idiL.s + idiD.l );
    ret.r = max( idiD.r, idiD.s + idiL.r );
    ret.s = idiL.s + idiD.s;
    ret.max = max( max( idiL.max, idiD.max ), idiL.r + idiD.l );
    return ret;
  }
} segment_tree;

int n, a[ MaxN ], Q;

int main()
{
  //freopen( "input.in", "r", stdin );
  scanf( "%d", &n );
  for ( int i = 0; i < n; i++ ) scanf( "%d", &a[ i ] );
  segment_tree.make( 1, 0, n - 1, a );
  scanf( "%d", &Q );
  while ( Q-- )
  {
    int t, a, b;
    scanf( "%d %d %d", &t, &a, &b );
    if ( t ) printf( "%d\n", segment_tree.get( 1, 0, n - 1, --a, --b ).max );
    else segment_tree.update( 1, 0, n - 1, --a, b );
  }
  return 0;
}
