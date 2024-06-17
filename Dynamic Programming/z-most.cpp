/* Z-trening problem z-most */
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, time[ 20 ], weight[ 20 ], dp[ 1 << 17 ];
vector < int > pos;

void calc( int oldMask, int idx, int timeMax, int totalWeight, int newMask )
{
    if ( totalWeight > n ) return;
    if ( idx == pos.size() )
    {
        dp[ oldMask ] = min( dp[ oldMask ], dp[ newMask ] + timeMax );
        return;
    }
    calc( oldMask, idx+1, max( timeMax, time[pos[idx]] ), totalWeight+weight[pos[idx]], newMask ^ ( 1<<pos[idx] ) );
    calc( oldMask, idx+1, timeMax, totalWeight, newMask );
}

int main()
{
    scanf("%d %d", &n, &m);
    for ( int i=0; i<m; i++ )
    {
        scanf("%d %d", time + i, weight + i);
        dp[ 1<<i ] = time[ i ];
    }

    dp[ 0 ] = 0;
    for ( int i=1; i<( 1<<m ); i++ )
    {
        pos.clear();
        for ( int j=0; j<m; j++ )
            if ( i & ( 1<<j ) ) pos.push_back( j );
        dp[ i ] = int( 2e9 );
        calc( i, 0, 0, 0, i );
    }

    printf("%d\n", dp[(1<<m)-1]);
    return 0;
}
