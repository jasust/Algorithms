#include <cstdio>
#include <string>
#include <map>

using namespace std;

const int MaxN = 3e4 + 20;

struct Fenwick
{
  int tree[ MaxN ];
  void clear()
  {
    for ( int i = 0; i < MaxN; i++ ) tree[ i ] = 0;
  }
  void update( int idx )
  {
    for ( int i = idx; i < MaxN; i += i & -i ) tree[ i ]++;
  }
  int read( int idx )
  {
    int ret = 0;
    for ( int i = idx; i; i -= i & -i ) ret += tree[ i ];
    return ret;
  }
} BIT;

int main()
{
  int tests, n;
  scanf( "%d", &tests );
  while ( tests-- )
  {
    scanf( "%d", &n );
    char unos[ 30 ];
    BIT.clear();
    map< string, int > val;
    for ( int i = n; i; i-- )
    {
      scanf( "%s", unos );
      val[ unos ] = i;
    }
    int ret = 0;
    for ( int i = 0; i < n; i++ )
    {
      scanf( "%s", unos );
      BIT.update( val[ unos ] );
      ret += BIT.read( val[ unos ] - 1 );
    }
    printf( "%d\n", ret );
  }
  return 0;
}
