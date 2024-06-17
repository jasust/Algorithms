/*
  Dat je string koji se sastoji od '(' i ')'.
  Operacije prvog tipa nalazu da se izmeni
  i-ta zagrada suprotnom. Operacije drugog
  tipa nalazu da se ispise da li je string
  sastavljen od koretno napisanih zagrada
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int MaxN = 3e4 + 10;
const int offset = 32768 + 20;

struct binarno_drvece
{
  struct node
  {
    int trebaL, trebaD;
  } tree[ offset * 2 ];
  void clear()
  {
    for ( int i = 0; i < offset * 2; i++ )
    {
      tree[ i ].trebaL = 0;
      tree[ i ].trebaD = 0;
    }
  }
  void init( int idx, int l, int r )
  {
    if ( l == r )
    {
      tree[ idx ].trebaL = 0;
      tree[ idx ].trebaD = 1;
      return;
    }
    int mid = ( l + r ) / 2;
    init( 2 * idx, l, mid );
    init( 2 * idx + 1, mid + 1, r );
    int temp = min( tree[ 2 * idx ].trebaD, tree[ 2 * idx + 1 ].trebaL );
    tree[ idx ].trebaL = tree[ 2 * idx ].trebaL + tree[ 2 * idx + 1 ].trebaL - temp;
    tree[ idx ].trebaD = tree[ 2 * idx ].trebaD + tree[ 2 * idx + 1 ].trebaD - temp;
  }
  void update( int idx, int l, int r, int pos )
  {
    if ( l == r )
    {
      tree[ idx ].trebaL ^= 1;
      tree[ idx ].trebaD ^= 1;
      return;
    }
    int mid = ( l + r ) / 2;
    if ( pos <= mid ) update( 2 * idx, l, mid, pos );
    else update( 2 * idx + 1, mid + 1, r, pos );
    int temp = min( tree[ 2 * idx ].trebaD, tree[ 2 * idx + 1 ].trebaL );
    tree[ idx ].trebaL = tree[ 2 * idx ].trebaL + tree[ 2 * idx + 1 ].trebaL - temp;
    tree[ idx ].trebaD = tree[ 2 * idx ].trebaD + tree[ 2 * idx + 1 ].trebaD - temp;
  }
  int query()
  {
    return tree[ 1 ].trebaL + tree[ 1 ].trebaD;
  }
} segment_tree;

int main()
{
  for ( int test = 0; test < 10; test++ )
  {
    int n, q;
    char unosni[ MaxN ];
    scanf( "%d", &n );
    segment_tree.clear();
    segment_tree.init( 1, 0, n - 1 );
    scanf( "%s", &unosni );
    for ( int i = 0; i < n; i++ ) if ( unosni[ i ] == ')' ) segment_tree.update( 1, 0, n - 1, i );
    scanf( "%d", &q );
    printf( "Test %d:\n", test + 1 );
    while ( q-- )
    {
      int x;
      scanf( "%d", &x );
      if ( !x )
      {
        if ( !segment_tree.query() ) printf( "YES\n" );
        else printf( "NO\n" );
      }
      else segment_tree.update( 1, 0, n - 1, --x );
    }
  }
  return 0;
}
