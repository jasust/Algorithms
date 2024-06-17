#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MaxN = 1 << 12;

int N, B[MaxN], DP[MaxN][MaxN];

vector < int > Numbers;
map < int, int > Hash;

int main ( )
{
    scanf ( "%d", &N );

    for ( int i = 0; i < N; i++ )
    {
        scanf ( "%d", &B[i] );
        Numbers.push_back ( B[i] );
    }

    sort ( Numbers.begin ( ), Numbers.end ( ) );

    int HashValue = 0;

    for ( int i = 0; i < N; i++ ) if ( ! i || Numbers[i] != Numbers[i - 1] ) Hash[Numbers[i]] = HashValue++;

    for ( int i = 0; i < N; i++ ) Numbers[i] = Hash[B[i]];

    for ( int i = 0; i < N; i++ )
        for ( int j = 0; j < i; j++ ) if ( DP[j][Numbers[i]] + 1 > DP[i][Numbers[j]] ) DP[i][Numbers[j]] = DP[j][Numbers[i]] + 1;

    int Sol = 0;

    for ( int i = 0; i < N; i++ )
        for ( int j = 0; j < HashValue; j++ ) if ( DP[i][j] > Sol ) Sol = DP[i][j];

    printf ( "%d\n", Sol + 1 );

    return 0;
}
