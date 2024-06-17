/*program zagrade*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long int lld;

const int maxsize = 705;
const lld mod = 1e9 + 7;

char bracket[ maxsize ];

int n;

lld dp[ maxsize ][ maxsize ][ 3 ][ 3 ];

lld compute( int left, int right, int colL, int colR )
{
    if ( left > right ) return 1;
    if ( dp[ left ][ right ][ colL ][ colR ] != -1 ) return dp[ left ][ right ][ colL ][ colR ];

    lld ans = lld( 0 );

    int cntOpen = 1, idx = left + 1;
    while ( idx <= right )
    {
        if ( bracket[ idx ] == '(' ) cntOpen++;
        else cntOpen--;
        if ( ! cntOpen ) break;
        idx++;
    }

    if ( colL != 1 ) ans += ( compute( left + 1, idx - 1, 1, 0 ) * compute( idx + 1, right, 0, colR ) ) % mod;
    if ( colL != 2 ) ans += ( compute( left + 1, idx - 1, 2, 0 ) * compute( idx + 1, right, 0, colR ) ) % mod;

    if ( idx < right )
    {
    ans += ( compute( left + 1, idx - 1, 0, 1 ) * compute( idx + 1, right, 1, colR ) ) % mod;
    ans += ( compute( left + 1, idx - 1, 0, 2 ) * compute( idx + 1, right, 2, colR ) ) % mod;
    }
    else
    {
    if ( colR != 1 ) ans += compute( left + 1, right - 1, 0, 1 ) % mod;
    if ( colR != 2 ) ans += compute( left + 1, right - 1, 0, 2 ) % mod;
    }

    dp[ left ][ right ][ colL ][ colR ] = ans % mod;

    return dp[ left ][ right ][ colL ][ colR ];
}

int main()
{
cin >> bracket;

n = strlen( bracket );
memset( dp, -1, sizeof( dp ) );

cout << compute( 0, n - 1, 0, 0 ) << endl;

return 0;
}
