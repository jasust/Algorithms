#include <cstdio>
#include <cctype>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

const int MaxN = 1e6;
const int offset = 0x100000;

struct binarno_drvece
{
  struct node
  {
    int used, V, maxi;
  } tree[ offset * 2 ];
  int koliko()
  {
    return tree[ 1 ].used;
  }
  int sum()
  {
    return tree[ 1 ].V;
  }
  void init( int idx, int l, int r, int K )
  {
    if ( l == r )
    {
      tree[ idx ].used = 0;
      tree[ idx ].V = K;
      tree[ idx ].maxi = K;
      return;
    }
    int mid = ( l + r ) / 2;
    init( 2 * idx, l, mid, K );
    init( 2 * idx + 1, mid + 1, r, K );
    tree[ idx ].used = tree[ 2 * idx ].used + tree[ 2 * idx + 1 ].used;
    tree[ idx ].V = tree[ 2 * idx ].V + tree[ 2 * idx + 1 ].V;
    tree[ idx ].maxi = max( tree[ 2 * idx ].maxi, tree[ 2 * idx + 1 ].maxi );
  }
  void update( int idx, int l, int r, int val )
  {
    if ( l == r )
    {
      tree[ idx ].used = 1;
      tree[ idx ].V -= val;
      tree[ idx ].maxi = tree[ idx ].V;
      return;
    }
    int mid = ( l + r ) / 2;
    if ( tree[ 2 * idx ].maxi >= val ) update( 2 * idx, l, mid, val );
    else update( 2 * idx + 1, mid + 1, r, val );
    tree[ idx ].used = tree[ 2 * idx ].used + tree[ 2 * idx + 1 ].used;
    tree[ idx ].V = tree[ 2 * idx ].V + tree[ 2 * idx + 1 ].V;
    tree[ idx ].maxi = max( tree[ 2 * idx ].maxi, tree[ 2 * idx + 1 ].maxi );
  }
} segment_tree;

int main()
{
  int test;
  cin >> test;
  while ( test-- )
  {
    int zapremina, n;
    cin >> zapremina >> n;
    segment_tree.init( 1, 0, n - 1, zapremina );
    for ( int i = 0; i < n; i++ )
    {
      string unos;
      cin >> unos;
      if ( isalpha( unos[ 0 ] ) )
      {
        int q, c;
        cin >> q >> c;
        while ( q-- )
        {
          i++;
          segment_tree.update( 1, 0, n - 1, c );
        }
        i--;
      }
      else
      {
        istringstream iss( unos );
        int c;
        iss >> c;
        segment_tree.update( 1, 0, n - 1, c );
      }
    }
    int ret = segment_tree.koliko();
    int s = segment_tree.sum();
    cout << ret << " " << s - ( n - ret ) * zapremina << endl;
  }
  return 0;
}
