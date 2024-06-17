/*
  Zadat je niz brojeva i dati su upiti nad njim.
  Svaki upit je tipa l, r, k i treba ispisati
  k-ti po velicini broj na intervalu od l do r.
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MaxN = 1e5 + 200;
const int offset = 131072;
const int MaxVal = 1e9 + 10;

struct binarno_drvece
{
  vector< int > tree[ offset * 2 ];
  void merge_sort( int idx, int l, int r, const int arr[] )
  {
    if ( l == r )
    {
      tree[ idx ].clear();
      tree[ idx ].push_back( arr[ l ] );
      return;
    }
    int mid = ( l + r ) / 2;
    merge_sort( 2 * idx, l, mid, arr );
    merge_sort( 2 * idx + 1, mid + 1, r, arr );
    tree[ idx ].clear();
    tree[ idx ].resize( tree[ 2 * idx ].size() + tree[ 2 * idx + 1 ].size() );
    merge( tree[ 2 * idx ].begin(), tree[ 2 * idx ].end(), tree[ 2 * idx + 1 ].begin(), tree[ 2 * idx + 1 ].end(), tree[ idx ].begin() );
  }
  vector< int > get( int idx, int l, int r, int levo, int desno )
  {
    if ( levo <= l && r <= desno )
    {
      vector< int > ret;
      ret.push_back( idx );
      return ret;
    }
    int mid = ( l + r ) / 2;
    if ( desno <= mid ) return get( 2 * idx, l, mid, levo, desno );
    if ( levo > mid ) return get( 2 * idx + 1, mid + 1, r, levo, desno );
    vector< int > ret;
    vector< int > tempL;
    vector< int > tempR;
    tempL = get( 2 * idx, l, mid, levo, desno );
    tempR = get( 2 * idx + 1, mid + 1, r, levo, desno );
    ret.resize( tempL.size() + tempR.size() );
    merge( tempL.begin(), tempL.end(), tempR.begin(), tempR.end(), ret.begin() );
    return ret;
  }
  int find( vector< int > &niz, long long vrednost )
  {
    int lo = 0;
    int hi = niz.size() - 1;
    if ( hi == 0 )
    {
      if ( niz[ 0 ] <= vrednost ) return 1;
      return 0;
    }
    while ( lo < hi )
    {
        int mid = ( lo + hi ) / 2;
        if ( niz[ mid ] >= vrednost ) hi = mid;
        else lo = mid + 1;
    }
    if ( lo >= 0 && niz[ lo ] > vrednost ) lo--;
    return lo + 1;
  }
  void query( int sz, int l, int r, int k )
  {
    vector< int > indices;
    indices = get( 1, 0, sz - 1, l, r );
    long long lo = 0, hi = 2000000000, mid;
    while ( lo < hi )
    {
      mid = lo + ( hi - lo ) / 2;
      int temp = 0;
      for ( int i = 0; i < indices.size(); i++ ) temp += find( tree[ indices[ i ] ], mid - 1000000000 );
      if ( temp >= k ) hi = mid;
      else lo = mid + 1;
    }
    printf( "%lld\n", lo - 1000000000 );
  }
} segment_tree;

int main()
{
  int n, q, niz[ MaxN ];
  scanf( "%d %d", &n, &q );
  for ( int i = 0; i < n; i++ ) scanf( "%d", &niz[ i ] );
  segment_tree.merge_sort( 1, 0, n - 1, niz );
  while ( q-- )
  {
    int x, y, z;
    scanf( "%d %d %d", &x, &y, &z );
    segment_tree.query( n, --x, --y, z );
  }
  return 0;
}
