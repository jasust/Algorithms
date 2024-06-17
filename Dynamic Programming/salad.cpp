#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100 + 5;
const int inf = 1e9;
const int array_limit = 2 * 10000 + 5;

int n, k, taste[maxn], calories[maxn], dp[maxn][array_limit];

int main()
{
    scanf( "%d %d", &n, &k );
    for ( int i = 0; i < n; i++ ) scanf( "%d", &taste[ i ] );
    for ( int i = 0; i < n; i++ ) scanf( "%d", &calories[ i ] );
    for ( int i = 0; i < n; i++ )
        for ( int j = -10000; j <= 10000; j++ ) dp[ i ][ j + 10000 ] = -inf;
    dp[ 0 ][ 10000 ] = 0;
    for ( int i = 0; i < n; i++ )
        for ( int j = -10000; j <= 10000; j++ )
        {
            if ( dp[ i ][ j + 10000 ] == -inf ) continue;
            dp[ i + 1 ][ j + 10000 ] = max( dp[ i + 1 ][ j + 10000 ], dp[ i ][ j + 10000 ] );
            int new_j = j + taste[ i ] - k * calories[ i ];
            if ( new_j < -10000 || new_j > 10000 ) continue;
            dp[ i + 1 ][ new_j + 10000 ] = max( dp[ i + 1 ][ new_j + 10000 ], dp[ i ][ j + 10000 ] + taste[ i ] );
        }
    if ( dp[ n ][ 10000 ] != 0 ) printf( "%d\n", dp[ n ][ 10000 ] );
    else printf( "-1\n" );
    return 0;
}
