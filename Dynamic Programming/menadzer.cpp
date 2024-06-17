/*
    Aleksandar 'Al3kSaNdaR' Ivanovic

    z-menadzer
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct movie
{
    int P, K, O;

    movie ( int _P, int _K, int _O )
    {
        P = _P;
        K = _K;
        O = _O;
    }

    inline friend bool operator < ( const movie & X, const movie &Y )
    {
        return X.K < Y.K;
    }
};

vector < movie > Movies;

const int MAX_N = 100000;

typedef long long int lld;

lld DP[MAX_N];

int main ( void )
{
    int n;

    scanf ( "%d", &n );
    for ( int i = 0; i < n; i++ )
    {
        int _P, _K, _O;

        scanf ( "%d %d %d", &_P, &_K, &_O );
        Movies.push_back ( movie ( _P, _K, _O ) );
    }

    sort ( Movies.begin ( ), Movies.end ( ) );

    lld Curr = 0;
    for ( int i = 0; i < n; i++ )
    {
        Curr = max ( 0LL + Movies[i].O, Curr );

        movie Movie = Movies[i];
        Movie.K = Movie.P;

        int idx = lower_bound ( Movies.begin ( ), Movies.begin ( ) + i, Movie ) - Movies.begin ( );

        if ( idx == 0 ) DP[i] = Curr;
        else
        {
            idx--;

            Curr = max ( Movies[i].O + DP[idx], Curr );

            DP[i] = Curr;
        }
    }

    printf ( "%d\n", DP[n - 1] );

    return 0;
}
