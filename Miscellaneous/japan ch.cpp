#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int maxN = 110;
int n, m, d1[ maxN ], d2[ maxN ], a1[ maxN ][ maxN ], a2[ maxN ][ maxN ];
char sol[ maxN ][ maxN ];

void ucit( )
{
    int x;
    scanf( "%d %d", &n ,&m );
    for ( int i = 1; i <= n; i++ )
    {
        int x;
        scanf( "%d", &x );
        while ( x )
        {
            d1[ i ]++;
            a1[ i ][ d1[ i ] ] = x;
            scanf( "%d", &x );
        }
    }
    for ( int i = 1; i <= m; i++ )
    {
        int x;
        scanf( "%d", &x );
        while ( x )
        {
            d2[ i ]++;
            a2[ i ][ d2[ i ] ] = x;
            scanf( "%d", &x );
        }
    }
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ ) sol[ i ][ j ] = '.';
}

void isp( )
{
    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = 1; j <= m; j++ ) printf( "%c", sol[ i ][ j ] );
        printf( "\n" );
    }
}

void solve( )
{
    ucit( );
    if ( n > m )
        for ( int i = 1; i <= n; i++ )
        {
            int c = 1;
            for ( int j = 1; j <= d1[ i ]; j++ )
            {
                for ( int k = 1; k <= a1[ i ][ j ]; k++ )
                {
                    sol[ i ][ c ] = '#';
                    c++;
                }
                c++;
            }
        }
    else
        for ( int i = 1; i <= m; i++ )
        {
            int c = 1;
            for ( int j = 1; j <= d2[ i ]; j++ )
            {
                for ( int k = 1; k <= a2[ i ][ j ]; k++ )
                {
                    sol[ c ][ i ] = '#';
                    c++;
                }
                c++;
            }
        }
    isp( );
}

int main( )
{
    int t;
    scanf( "%d", &t );
    while ( t-- )
    {
        solve( );
        for ( int i = 1; i < maxN; i++ )
            for ( int j = 1; j < maxN; j++ ) a1[ i ][ j ] = a2[ i ][ j ] = 0;
        for ( int i = 1; i < maxN; i++ ) d1[ i ] = d2[ i ] = 0;
    }
    return 0;
}
