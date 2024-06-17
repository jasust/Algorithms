/* Z--trening Problem terorista */
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

typedef long long int lld;
const int maxn = 1e5 + 5;

int n, last, k, water[ maxn ], canHold[ maxn ], price[ maxn ];
lld sol, curr, dp[ maxn ];
set < pair < lld, int > > S;

int main()
{
    scanf( "%d", &n );
    for ( int i = 1; i <= n; i++ ) scanf( "%d %d %d", &water[ i ], &canHold[ i ], &price[ i ] );

    for ( int i = 1; i <= n; i++ ) dp[ i ] = dp[ i - 1 ] + lld( water[ i ] );
    sol = curr = lld( price[ 1 ] );
    last = 1;
    S.insert( make_pair( canHold[ 1 ], 1 ) );
    for ( int i = 2; i <= n; i++ )
    {
        curr += lld( price[ i ] );
        while ( ! S.empty() )
        {
            k = S.begin()->second;
            if ( lld( canHold[ k ] ) + dp[ k - 1 ] < dp[ i ] )
            {
                curr -= price[ k ];
                S.erase( S.begin() );
            }
            else break;
        }
        if ( sol > curr ) sol = curr, last = i;
        S.insert( make_pair( lld( canHold[ i ] ) + dp[ i - 1 ], i ) );
    }

    printf( "%lld\n", sol );
    while ( last )
    {
        if ( canHold[ last ] >= water[ last ] ) printf( "%d\n", last );
        last--;
        water[ last ] += water[ last + 1 ];
    }

    return 0;
}
