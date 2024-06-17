#include <cstdio>
#include <vector>

using namespace std;

const int MaxV = 5e5 + 5;

int V, q, x, y, t, plata[ MaxV ], in[ MaxV ], out[ MaxV ];
char unos[ 12 ];
vector< int > adj[ MaxV ];

void DFS( int Curr )
{
  in[ Curr ] = t++;
  for ( vector< int >::iterator it = adj[ Curr ].begin(); it != adj[ Curr ].end(); it++ ) DFS( *it );
  out[ Curr ] = t;
}

struct Fenwick
{
  int tree[ MaxV ];
  void update( int idx, int val )
  {
    for ( int i = ++idx; i < MaxV; i += i & -i ) tree[ i ] += val;
  }
  int sum( int idx )
  {
    int ret = 0;
    for ( int i = ++idx; i; i -= i & -i ) ret += tree[ i ];
    return ret;
  }
} BIT;

int main()
{
  scanf( "%d %d", &V, &q );
  scanf( "%d", plata );
  for ( int i = 1; i < V; i++ )
  {
    scanf( "%d %d", plata + i, &x );
    adj[ --x ].push_back( i );
  }
  DFS( 0 );
  while ( q-- )
  {
    scanf( "%s", unos );
    if ( *unos == 'p' )
    {
      scanf( "%d %d", &x, &y );
      BIT.update( in[ --x ] + 1, y );
      BIT.update( out[ x ], -y );
    }
    else
    {
      scanf( "%d", &x );
      x--;
      printf( "%d\n", BIT.sum( in[ x ] ) + plata[ x ] );
    }
  }
  return 0;
}
