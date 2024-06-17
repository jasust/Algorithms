/* Set se obično koristi kao zamena za heap strukturu ili za binarno pretraživačko stablo.
STL set se moze koristiti i u implementaciji Dajkstrinog algoritma. */
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

const int MaxV = 1e5;
const int MaxE = 1e5;
const int oo = 2e9;

int Dijkstra( int V, const vector< vector< pair< int, int > > > &adj, int start, int end )
{
  set< pair< int, int > > heap;
  int d[ MaxV ];
  for ( int i = 0; i < V; i++ ) d[ i ] = oo;
  heap.insert( make_pair( d[ start ] = 0, start ) );
  while ( !heap.empty() )
  {
    int node = heap.begin()->second;
    int dist = heap.begin()->first;
    heap.erase( heap.begin() );
    for ( int i = 0; i < adj[ node ].size(); i++ )
    {
      int tempNode = adj[ node ][ i ].first;
      int tempDist = adj[ node ][ i ].second;
      if ( dist + tempDist < d[ tempNode ] )
      {
        if ( d[ tempNode ] != oo ) heap.erase( heap.find( make_pair( d[ tempNode ], tempNode ) ) );
        heap.insert( make_pair( d[ tempNode ] = dist + tempDist, tempNode ) );
      }
    }
  }
  return d[ end ];
}


int main()
{
  //freopen( "input.in", "r", stdin );
  int tests;
  scanf( "%d", &tests );
  while ( tests-- )
  {
    int Edg, Ve, pocetak, kraj;
    scanf( "%d %d %d %d", &Ve, &Edg, &pocetak, &kraj );
    vector< vector< pair< int, int > > > a;
    a.resize( Ve );
    for ( int i = 0; i < Edg; i++ )
    {
      int x, y, z;
      scanf( "%d %d %d", &x, &y, &z );
      a[ --x ].push_back( make_pair( --y, z ) );
      a[ y ].push_back( make_pair( x, z ) );
    }
    int ret = Dijkstra( Ve, a, --pocetak, --kraj );
    if ( ret == oo ) printf( "NONE\n" );
    else printf( "%d\n", ret );
  }
  return 0;
}
