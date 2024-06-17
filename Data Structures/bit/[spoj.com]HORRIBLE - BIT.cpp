#include <cstdio>

const int MaxN = 1e5 + 20;

int tests, n, q, tip, x, y, z;

struct Fenwick
{
  struct node
  {
    long long add, sum;
  } tree[ MaxN ];
  void clear()
  {
    for ( int i = 0; i < MaxN; i++ ) tree[ i ] = ( node ){ 0, 0 };
  }
  void update( int idx, int val )
  {
    for ( int i = idx; i < MaxN; i += i & -i )
    {
      tree[ i ].sum += ( i - idx + 1LL ) * val;
      tree[ i ].add += val;
    }
  }
  long long sum( int idx )
  {
    long long ret = tree[ idx ].sum;
    for ( int i = idx - ( idx & -idx ); i; i -= i & -i ) ret += tree[ i ].sum + tree[ i ].add * ( idx - i );
    return ret;
  }
} BIT;

int main()
{
  scanf( "%d", &tests );
  while ( tests-- )
  {
    scanf( "%d %d", &n, &q );
    BIT.clear();
    while ( q-- )
    {
      scanf( "%d", &tip );
      if ( tip )
      {
        scanf( "%d %d", &x, &y );
        printf( "%lld\n", BIT.sum( y ) - BIT.sum( x - 1 ) );
      }
      else
      {
        scanf( "%d %d %d", &x, &y, &z );
        BIT.update( x, z );
        BIT.update( y + 1, -z );
      }
    }
  }
  return 0;
}
