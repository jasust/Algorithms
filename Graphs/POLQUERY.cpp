/* Police Query */
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 1e5 + 5;

struct link
{
    int x, y;
    link() { }
    link( int _x, int _y ) { x = _x; y = _y; }
    bool operator < ( const link & newL ) const
    {
        return x < newL.x;
    }
};

vector < link > edge;
vector < link > :: iterator start[ maxn ];
vector < int > adj[ maxn ];
int n, m, q, time, idx[ maxn ], finish[ maxn ], lowlink[ maxn ], depth[ maxn ];

void initEdges()
{
    sort( edge.begin(), edge.end() );
    start[ 0 ] = edge.begin();
    for ( int i = 1; i <= n; i++ )
    {
        start[ i ] = start[ i - 1 ];
        while ( start[ i ] != edge.end() && start[ i ]->x < i ) start[ i ]++;
    }
}

void dfs( int curr, int prev )
{
    idx[ curr ] = time;
    lowlink[ curr ] = time;
    time++;
    for ( vector < link > :: iterator it = start[ curr ]; it != start[ curr + 1 ]; it++ )
    {
        if ( it->y == prev ) continue;
        if ( idx[ it->y ] == -1 )
        {
            depth[ it->y ] = depth[ curr ] + 1;
            dfs( it->y, curr );
            lowlink[ curr ] = min( lowlink[ curr ], lowlink[ it->y ] );
            adj[ curr ].push_back( it->y );
        }
        else lowlink[ curr ] = min( lowlink[ curr ], lowlink[ it->y ] );
    }
    finish[ curr ] = time;
    time++;
}

bool descendant( int x, int y )
{
    return ( idx[ y ] <= idx[ x ] && finish[ y ] >= finish[ x ] );
}

int findSon( int curr, int descendant )
{
    int left = 0, right = adj[ curr ].size() - 1;
    while ( left != right )
    {
        int mid = ( left + right ) / 2;
        if ( idx[ descendant ] > finish[ adj[ curr ][ mid ] ] ) left = mid + 1;
        else if ( finish[ descendant ] < idx[ adj[ curr ][ mid ] ] ) right = mid - 1;
        else left = right = mid;
    }
    return adj[ curr ][ left ];
}

int main()
{
    scanf( "%d %d", &n, &m );
    for ( int i = 0; i < m; i++ )
    {
        int x, y;
        scanf( "%d %d", &x, &y );
        x--; y--;
        edge.push_back( link( x, y ) );
        edge.push_back( link( y, x ) );
    }

    initEdges();
    for ( int i = 0; i < n; i++ ) idx[ i ] = finish[ i ] = depth[ i ] = lowlink[ i ] = -1;
    time = 0;
    depth[ 0 ] = 0;
    dfs( 0, -1 );

    scanf( "%d", &q );
    while ( q-- )
    {
        int type;
        scanf( "%d", &type );
        if ( type & 1 )
        {
            int a, b, c, d;
            scanf( "%d %d %d %d", &a, &b, &c, &d );
            a--; b--; c--; d--;
            if ( descendant( c, d ) ) swap( c, d );
            if ( lowlink[ d ] < idx[ d ] ) printf( "da\n" );
            else if ( descendant( a, d ) == descendant( b, d ) ) printf( "da\n" );
            else printf( "ne\n" );
        }
        else
        {
            int a, b, c;
            scanf( "%d %d %d", &a, &b, &c );
            a--; b--; c--;
            if ( ! descendant( a, c ) && ! descendant( b, c ) ) printf( "da\n" );
            else if ( descendant( a, c ) && descendant( b, c ) )
            {
                int one = findSon( c, a );
                int two = findSon( c, b );
                if ( one == two ) printf( "da\n" );
                else if ( lowlink[ one ] < idx[ c ] && lowlink[ two ] < idx[ c ] ) printf( "da\n" );
                else printf( "ne\n" );
            }
            else
            {
                if ( descendant( a, c ) ) swap( a, b );
                int one = findSon( c, b );
                if ( lowlink[ one ] < idx[ c ] ) printf( "da\n" );
                else printf( "ne\n" );
            }
        }
    }

    return 0;
}
