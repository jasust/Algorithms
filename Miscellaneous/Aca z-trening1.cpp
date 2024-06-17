/*
    Aleksandar "Al3kSaNdaR" Ivanovic

    z-zurka
*/
#include <cstdio>
#include <cstring>

using namespace std;

const int MaxCities = 1000 + 5;

int DP[MaxCities];

int main ( void )
{
    memset ( DP, 0, sizeof ( DP ) );

    int Sol = 0;

    for ( int i = 0; i < 3; i++ )
    {
        int N;

        scanf ( "%d", &N );

        for ( int j = 0; j < N; j++ )
        {
            int idx;

            scanf ( "%d", &idx );

            DP[idx]++;

            if ( DP[idx] == 3 ) Sol++;
        }
    }

    printf ( "%d\n", Sol );

    return 0;
}

/*
    Aleksandar "Al3kSaNdaR" Ivanovic

    z-niz
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MaxN = 10000 + 5;

int X[MaxN], Y[MaxN];

int main ( void )
{
    int N;

    scanf ( "%d", &N );

    for ( int i = 0; i < N; i++ ) scanf ( "%d", X + i );

    int K;

    scanf ( "%d", &K );

    for ( int i = 0; i < K; i++ )
    {
        int A, B, C;

        scanf ( "%d %d %d", &A, &B, &C );

        --A;
        --B;

        for ( int j = A; j <= B; j++ ) Y[j - A] = X[j];

        sort ( Y, Y + ( B - A + 1 ) );

        printf ( "%d\n", Y[--C] );
    }

    return 0;
}

/*
    Aleksandar 'Al3kSaNdaR' Ivanovic

    ABC-coci
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main ( void )
{
    vector < int > X;
    map < char, int > Map;

    Map['A'] = 0;
    Map['B'] = 1;
    Map['C'] = 2;

    for ( int i = 0; i < 3; i++ )
    {
        int number;

        scanf ( "%d", &number );
        X.push_back ( number );
    }

    sort ( X.begin ( ), X.end ( ) );

    char S[3];
    scanf ( "%s", S );

    for ( int i = 0; i < 3; i++ ) printf ( "%d ", X[Map[S[i]]] );

    return 0;
}

//Acm contenst
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <utility>
#include <map>

using namespace std;

int N, Cnt[10], Accepted[10];
double TotalTime[10];

map < pair < string, char >, bool > Solved;

map < pair < string, char >, int > CntR;

inline void Round ( double X )
{
   double Y = 100 * X;

   int Rounded = ( int ) ( Y + 0.5 );

   printf ( " %d.%02d", Rounded / 100, Rounded % 100);
}

int main ( void )
{
    scanf ( "%d", &N );

    for ( int i = 0; i < N; i++ )
    {
        double Time;

        scanf ( "%lf", &Time );

        string Team;

        cin >> Team;

        char Task, Result;

        scanf ( " %c %c", &Task, &Result );

        if ( Solved[ make_pair ( Team, Task ) ] ) continue;

        if ( Result == 'R' )
        {
            CntR[ make_pair ( Team, Task ) ]++;

            continue;
        }

        Cnt[Task - 'A']++;

        Accepted[Task - 'A']++;

        TotalTime[Task - 'A'] += Time;

        Solved[ make_pair ( Team, Task ) ] = true;
    }

    for ( map < pair < string, char >, int > :: iterator it = CntR.begin ( ); it != CntR.end ( ); it++ ) if ( Solved[ ( * it ).first ] ) Cnt[ ( * it ).first.second - 'A' ] += ( * it ).second;

    for ( int i = 0; i < 9; i++ )
    {
        printf ( "%c %d", 'A' + i, Accepted[i] );

        if ( ! Accepted[i] )
        {
            printf ( "\n" );

            continue;
        }

        double X = ( Cnt[i] * 1.0 ) / ( Accepted[i] * 1.0 );

        double Y = TotalTime[i] / Accepted[i];

        Round ( X );
        Round ( Y );

        printf ( "\n" );
    }

    return 0;
}
