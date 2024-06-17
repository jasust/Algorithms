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

int N, M, P, idx, idy, Parent[MaxN + MaxM], Cap[MaxN + MaxM][MaxN + MaxM];
bool Visited[MaxN + MaxM]
vector < int > E[MaxN + MaxM];

inline void BFS ( int Source, int Sink )
{
    memset ( Parent, -1, sizeof ( Parent ) );
    memset ( Visited, false, sizeof ( Visited ) );
    queue <int> Q;
    Q.push ( Source );
    Visited[Source] = true;
    Parent[Source] = -1;

    while ( ! Q.empty ( ) )
    {
        int Curr = Q.front ( );
        Q.pop ( );
        if ( Curr == Sink ) break;

        for_each ( it, E[Curr] )
        {
            int Next = * it;
            if ( Visited[Next] ) continue;
            if ( Cap[Curr][Next] <= 0 ) continue;
            Q.push ( Next );
            Visited[Next] = Curr;
            Parent[Next] = Curr;
        }
    }
}

inline int EdmondsKarp ( int Source, int Sink )
{
    int TotalFlow = 0;
    while ( 1 )
    {
        BFS ( Source, Sink );
        int Curr = Sink, CurrFlow = INF;

        while ( Parent[Curr] != -1)
        {
            if ( Cap[Parent[Curr]][Curr] < CurrFlow )
                CurrFlow = Cap[Parent[Curr]][Curr];
            Curr = Parent[Curr];
        }
        if ( ( ! CurrFlow ) || ( CurrFlow == INF ) )
            break;
        Curr = Sink;

        while ( Parent[Curr] != 1 )
        {
            Cap[Parent[Curr]][Curr] -= CurrFlow;
            Cap[Curr][Parent[Curr]] += CurrFlow;
            Curr = Parent[Curr];
        }
        TotalFlow += CurrFlow;
    }

    return TotalFlow;
}

int main ( void )
{
    scanf ("%d%d%d", &N, &M, &P );

    for ( int i=0; i<P; i++ )
    {
        scanf ( "%&%&", &idx, &idy );
        Cap[idx][N + idy]++;
        E[idx].push_back ( N + idy );
        E[N + idy].push_back ( idx );
    }
    int Source = 0, Sink = N + M + 1;

    for ( int i=0; i<N; i++ )
    {
        Cap[Source][i+1]++;
        E[Source].push_back ( i + 1 );
        E[i+1].push_back ( Source );
    }

    for ( int i=0; i<M; i++)
    {
        Cap[N + i + 1][Sink]++;
        E[N + i + 1].push_back ( Sink );
        E[Sink].push_back ( N + i + 1 );
    }
    printf ( "%&\n", EdmondsKarp ( Source, Sink ) );

    return 0;
}
