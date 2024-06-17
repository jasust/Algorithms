/*
  Dato je n pravougaonika svojim koordinatama.
  Ispisati povrsinu unije ovih pravougaonika.
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int MaxN = 1e4 + 20;
const int MaxY = 3e4 + 20;
const int offset = 1 << 15;

int n, x1, y1, x2, y2, area, prev;

struct pravokutnjak
{
  int x, y1, y2, tip;
  pravokutnjak()
  {
  }
  pravokutnjak( int _x, int _y1, int _y2, int _tip )
  {
    x = _x;
    y1 = _y1;
    y2 = _y2;
    tip = _tip;
  }
  bool operator < ( const pravokutnjak &A ) const
  {
    return x < A.x;
  }
} niz[ MaxN << 1 ];

struct segment_tree
{
  struct node
  {
    int add, sum;
  } tree[ offset << 1 ];
  void update( int idx, int l, int r, int levo, int desno, int val )
  {
    if ( levo <= l && r <= desno ) tree[ idx ].add += val;
    else
    {
      int mid = ( l + r ) / 2;
      if ( levo <= mid ) update( 2 * idx, l, mid, levo, desno, val );
      if ( desno > mid ) update( 2 * idx + 1, mid + 1, r, levo, desno, val );
    }
    if ( tree[ idx ].add ) tree[ idx ].sum = r - l + 1;
    else tree[ idx ].sum = l < r ? tree[ 2 * idx ].sum + tree[ 2 * idx + 1 ].sum : 0;
  }
  int query()
  {
    return tree[ 1 ].sum;
  }
} duzi;

int main()
{
  scanf( "%d", &n );
  for ( int i = 0; i < n; i++ )
  {
    scanf( "%d %d %d %d", &x1, &y1, &x2, &y2 );
    y1++;
    niz[ i ] = pravokutnjak( x1, y1, y2, 1 );
    niz[ i + n ] = pravokutnjak( x2, y1, y2, -1 );
  }
  n <<= 1;
  sort( niz, niz + n );
  prev = niz[ 0 ].x;
  for ( int i = 0; i < n; i++ )
  {
    area += duzi.query() * ( niz[ i ].x - prev );
    prev = niz[ i ].x;
    duzi.update( 1, 0, MaxY, niz[ i ].y1, niz[ i ].y2, niz[ i ].tip );
  }
  printf( "%d\n", area );
  return 0;
}
