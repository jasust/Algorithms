#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MaxN = 1e3 + 13;

struct Fenwick
{
  int tree[ MaxN ];
  void clear()
  {
    for ( int i = 0; i < MaxN; i++ ) tree[ i ] = 0;
  }
  void update( int idx )
  {
    for ( ; idx < MaxN; idx += idx & -idx ) tree[ idx ]++;
  }
  int query( int idx )
  {
    int ret = 0;
    for ( ; idx; idx -= idx & -idx ) ret += tree[ idx ];
    return ret;
  }
} BIT;

int tsts, m, n, k, x, y;
vector< pair< int, int > > niz;

int main()
{
  scanf( "%d", &tsts );
  for ( int tNo = 1; tNo <= tsts; tNo++ )
  {
    scanf( "%d %d %d", &m, &n, &k );
    niz.clear();
    BIT.clear();
    while ( k-- )
    {
      scanf( "%d %d", &x, &y );
      niz.push_back( make_pair( x, y ) );
    }
    sort( niz.begin(), niz.end() );
    long long ret = 0;
    for ( int i = 0; i < niz.size(); i++ )
    {
      ret += BIT.query( MaxN - 1 ) - BIT.query( niz[ i ].second );
      BIT.update( niz[ i ].second );
    }
    printf( "Test case %d: %lld\n", tNo, ret );
  }
  return 0;
}
