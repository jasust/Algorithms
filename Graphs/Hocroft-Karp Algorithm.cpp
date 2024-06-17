#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

#define pb push_back
#define sz size
#define all(X) (X).begin(), (X).end ()
#define for_each(it,X) for (__typeof((X).begin()) it = (X).begin(); it !=(X).end(); it++)

using namespace std;

const int MaxN = 1<<18;
const int MaxM = 1<<18;
const int INF = 1<<30;

int N, M, P,NIL, idx, idy, Dist[MaxN + MaxM], Match[MaxN + MaxM];
bool Visited[MaxN + MaxM]
int vector E[MaxN + MaxM];

inline bool BFS ( void )
{
    queue < int > Q;

    for ( int i=1; i<=N; i++ )
    {
        if ( Match[i] == NIL )
        {
            Dist[i] = 0;
            Q.push ( i );
        }
        else Dist[i] = INF;
    }
    Dist[NIL] = INF;

    while ( ! Q.empty ( ))
    {
        int u = Q.front ( );
        Q.pop ( );
        if (u != NIL )
        {
            for_each ( it, E[u] )
            {
                int v = * it;
                if ( Dist[Match[v]] == INF)
                {
                    Dist[Match[v]] = Dist[u] + 1;
                    Q.push ( Match[v] );
                }
            }
        }
    }
    return Dist[NIL] != INF;
}

bool DFS ( int u )
{
    if ( u )
    {
        for_each ( it, E[u] )
        {
            int v = * it;
            if ( Dist[Match[v]] == Dist[u] + 1 )
            {
                if (DFS ( Match[v] ) )
                {
                    Match[v] = u;
                    Match[u] = v;

                    return true;
                }
            }
        }
        Dist[u] = INF;

        return false;
    }

    return true;
}

inline int HopcroftKarp ( void )
{
    int MaximumMatching = 0;
    while ( BFS ( ) )
    {
        for ( int i=1; i<=N; i++ )
            if ( Match[i] == NIL && DFS ( i ) )
                MaximumMatching++;
    }

    return MaximumMatching;
}

int main ( void )
{
    scanf ("%d%d%d", &N, &M, &P );

    for ( int i=0; i<P; i++ )
    {
        scanf ( "%&%&", &idx, &idy );
        E[idx].push_back ( N + idy );
        E[N + idy].push_back ( idx );
    }

    printf( "%&\n", HopcroftKarp( ));

    return 0;
}
