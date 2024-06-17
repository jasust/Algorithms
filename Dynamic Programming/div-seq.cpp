#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX_NUMBER = 1000000;

int Cnt[MAX_NUMBER];

int main ( void )
{
    int c;
    scanf ( "%d", &c );

    for ( ; c; c-- )
    {
        memset ( Cnt, 0, sizeof ( Cnt ) );
        int d, n, Sum = 0, Sol = 0;

        scanf ( "%d %d", &d, &n );

        Cnt[0] = 1;
        for ( int i = 0; i < n; i++ )
        {
            int Number;

            scanf ( "%d", &Number );

            Sum = ( Sum + ( Number % d ) ) % d;
            Sol += Cnt[Sum]++;
        }

        printf ( "%d\n", Sol );
    }

    return 0;
}
