#include <cstdio>
#include <algorithm>

using namespace std;

const int MaxN = 3e5 + 35;
const int MaxVal = 1e5 + 15;

struct Fenwick
{
  int tree[ MaxVal ];
  void update( int idx )
  {
    for ( ++idx; idx < MaxVal; idx += idx & -idx ) tree[ idx ]++;
  }
  int query( int idx )
  {
    int ret = 0;
    for ( ++idx; idx; idx -= idx & -idx ) ret += tree[ idx ];
    return ret;
  }
} BIT;

struct coder
{
  int x, y, idx, ret;
  coder()
  {
  }
  void load( int _idx )
  {
    scanf( "%d %d", &x, &y );
    idx = _idx;
  }
  bool operator < ( const coder &A ) const
  {
    if ( x != A.x ) return x < A.x;
    if ( y != A.y ) return y < A.y;
    return idx < A.idx;
  }
} niz[ MaxN ];

int n, ret;

bool compare_idx( const coder &A, const coder &B )
{
  return A.idx < B.idx;
}

int main()
{
  scanf( "%d", &n );
  for ( int i = 0; i < n; i++ ) niz[ i ].load( i );
  sort( niz, niz + n );
  niz[ 0 ].ret = 0;
  BIT.update( niz[ 0 ].y );
  for ( int i = 1; i < n; i++ )
  {
    if ( niz[ i ].x == niz[ i - 1 ].x && niz[ i ].y == niz[ i - 1 ].y ) niz[ i ].ret = niz[ i - 1 ].ret;
    else ret = niz[ i ].ret = BIT.query( niz[ i ].y );
    BIT.update( niz[ i ].y );
  }
  sort( niz, niz + n, compare_idx );
  for ( int i = 0; i < n; i++ ) printf( "%d\n", niz[ i ].ret );
  return 0;
}
