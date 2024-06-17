#include <cstdio>
#include <algorithm>

using namespace std;

const int offset = 1 << 19;
const int MaxN = 5e5;
const int MaxQ = 1e5 + 4;

int broj = -1;

struct custom
{
  int levi, desni;
} upit[ MaxQ ];

struct Stree
{
  struct cst
  {
    int ima, koliko;
  } tree[ offset << 1 ];
  void init()
  {
    for ( int i = 0; i < ( offset << 1 ); i++ )
    {
      tree[ i ].ima = 0;
      tree[ i ].koliko = 0;
    }
  }
  void update( int idx, int l, int r, int pocetak, int kraj, int val )
  {
    if ( pocetak > r || kraj < l ) return;
    tree[ idx ].ima += val;
    if ( pocetak <= l && r <= kraj ) tree[ idx ].koliko += val;
    else
    {
      int mid = ( l + r ) / 2;
      update( 2 * idx, l, mid, pocetak, kraj, val );
      update( 2 * idx + 1, mid + 1, r, pocetak, kraj, val );
    }
  }
  int query( int idx, int l, int r, int pocetak, int kraj )
  {
    if ( pocetak > r || kraj < l || !tree[ idx ].ima ) return 0;
    if ( tree[ idx ].koliko ) return ( min( kraj, r ) - max( pocetak, l ) + 1 );
    else
    {
      if ( l == r ) return 0;
      int mid = ( l + r ) / 2;
      return query( 2 * idx, l, mid, pocetak, kraj ) + query( 2 * idx + 1, mid + 1, r, pocetak, kraj );
    }
  }
} segment_tree;

int main()
{
  segment_tree.init();
  while ( 1 )
  {
    char c;
    scanf( "%c", &c );
    if ( c == 'K' ) break;
    if ( c == 'A' )
    {
      int l, r;
      scanf( "%d %d", &l, &r );
      upit[ ++broj ].levi = --l;
      upit[ broj ].desni = --r;
      segment_tree.update( 1, 0, MaxN - 1, l, r, 1 );
    }
    if ( c == 'R' )
    {
      int idx;
      scanf( "%d", &idx );
      --idx;
      segment_tree.update( 1, 0, MaxN - 1, upit[ idx ].levi, upit[ idx ].desni, -1 );
    }
    if ( c == 'Q' )
    {
      int l, r;
      scanf( "%d %d", &l, &r );
      printf( "%d\n", segment_tree.query( 1, 0, MaxN - 1, l - 1, r - 1 ) );
    }
  }
  return 0;
}
