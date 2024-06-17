/*
  Dato je stablo u kome su svi cvorovi obojeni u belo.
  Dati su upiti dve vrste:
  1) Promeni boju datog cvora suprotnom.
  2) Odredi prvi crni cvor na putu od korena do datog cvora.
*/

#include <set>
#include <cstdio>
#include <vector>

using namespace std;

const int MaxV = 1e5 + 20;

int dubina[ MaxV ];
int boja[ MaxV ];
int otac[ MaxV ];
int velicina[ MaxV ];

struct set_compare
{
  bool operator () ( int a, int b )
  {
    return dubina[ a ] < dubina[ b ];
  }
};

set< int, set_compare > crni[ MaxV ];
vector< vector< int > > adj;

void DFS( int Curr, int Prev )
{
  otac[ Curr ] = Prev;
  velicina[ Curr ] = 1;
  for ( vector< int >::iterator it = adj[ Curr ].begin(); it != adj[ Curr ].end(); it++ )
  {
    if ( *it == Prev ) continue;
    dubina[ *it ] = dubina[ Curr ] + 1;
    DFS( *it, Curr );
    velicina[ Curr ] += velicina[ *it ];
  }
}

void HLD( int Curr, int Prev, int clr )
{
  boja[ Curr ] = clr;
  int maxIdx = -1;
  for ( vector< int >::iterator it = adj[ Curr ].begin(); it != adj[ Curr ].end(); it++ )
  {
    if ( *it == Prev ) continue;
    if ( maxIdx == -1 || velicina[ *it ] > velicina[ maxIdx ] ) maxIdx = *it;
  }
  if ( maxIdx != -1 ) HLD( maxIdx, Curr, clr );
  for ( vector< int >::iterator it = adj[ Curr ].begin(); it != adj[ Curr ].end(); it++ )
  {
    if ( *it == Prev || *it == maxIdx ) continue;
    HLD( *it, Curr, *it );
  }
}

int query( int idx )
{
  if ( boja[ idx ] != 0 )
  {
    int temp = query( otac[ boja[ idx ] ] );
    if ( temp != -1 ) return temp;
  }
  if ( crni[ boja[ idx ] ].empty() ) return -1;
  int temp = *crni[ boja[ idx ] ].begin();
  if ( dubina[ temp ] <= dubina[ idx ] ) return temp + 1;
  return -1;
}

void update( int idx )
{
  int clr = boja[ idx ];
  if ( crni[ clr ].find( idx ) == crni[ clr ].end() ) crni[ clr ].insert( idx );
  else crni[ clr ].erase( idx );
}

int main()
{
  int V, q, x, y;
  scanf( "%d %d", &V, &q );
  adj.resize( V );
  while ( --V )
  {
    scanf( "%d %d", &x, &y );
    adj[ --x ].push_back( --y );
    adj[ y ].push_back( x );
  }
  DFS( 0, -1 );
  HLD( 0, -1, 0 );
  while ( q-- )
  {
    scanf( "%d %d", &x, &y );
    if ( x ) printf( "%d\n", query( --y ) );
    else update( --y );
  }
  return 0;
}
