/*

Dato je stablo, svaki cvor ima svoju tezinu. Naci cvor cija maksimalna grana ima najmanju vrednost.
Maksimalna grana je ona grana koja vodi do podstabla ciji je zbir vrednosti svih cvorova najveci.

*/

#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>

using namespace std;

int suma[ 100 ], ljudi[ 100 ], otac[ 100 ];

vector < int > sin[ 100 ];

void dfs( int  c )
{
    suma[ c ] = ljudi[ c ];

    for ( vector < int > :: iterator i = sin[ c ]. begin(); i != sin[ c ]. end(); i ++ )
    {
        if ( * i != otac[ c ] )
        {
            otac[ * i ] = c;

            dfs( * i );

            suma[ c ] += suma[ * i ];
        }
    }
}

int guzva_otac( int c )
{
    return suma[ 1 ] - suma[ c ];
}

int guzva_sin( int c )
{
    int maksimum = 0;

    for ( vector < int > :: iterator i = sin[ c ]. begin(); i != sin[ c ]. end(); i ++ )

        if ( * i != otac[ c ] && suma[ * i ] > maksimum ) maksimum = suma[ * i ];

    return maksimum;
}

int guzva( int c )
{
    return max( guzva_otac( c ), guzva_sin( c ) );
}

int main()
{
    int n, m, q, res = INT_MAX;

    cin >> n;

    for ( int i = 1; i <= n; i ++ ) cin >> ljudi[ i ];

    cin >> m;

    while ( m -- )
    {
        int x, y;

        cin >> x >> y;

        sin[ x ]. push_back( y );

        sin[ y ]. push_back( x );
    }

    dfs( 1 );

    for ( int i = 1; i <= n; i ++ ) cout << suma[ i ] << " ";

    for ( int i = 1; i <= n; i ++ ) res = min( guzva( i ), res );

    cout << res;

    return 0;
}
