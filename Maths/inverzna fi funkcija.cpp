#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long int lld;
const lld INF = 1LL << 61LL;

lld N, K;
vector <lld> Primes;

void Calc ( int idx, lld N, lld K )
{
    if ( N > :: N ) return; // :: znaci promenljiva iz glavnog programa
    if ( K == 1LL )
    {
        if ( N < :: N ) :: N = N;
        return;
    }
    for ( int i = idx; i >= 0; i-- )
    {
        lld NextN = N, NextK = K;
        if ( K % ( Primes[i] - 1LL ) == 0LL )
        {
            NextK = K / ( Primes[i] - 1LL );
            NextN *= Primes[i];
            Calc ( i - 1, NextN, NextK );
            while ( NextK % Primes[i] == 0LL )
            {
                NextK /= Primes[i];
                NextN *= Primes[i];
                Calc ( i - 1, NextN, NextK );
            }
        }
    }
}

inline lld Prime ( lld N )
{
    if ( N == 1LL ) return false;
    if ( N == 2LL ) return true;
    if ( N % 2LL == 0LL ) return false;
    for ( int i = 3LL; i * i <= N; i += 2LL ) if ( N % i == 0LL ) return false;
    return true;
}

inline lld InverseEuler ( lld K )
{
    if ( K == 1LL ) return 1LL;
    if ( K == 2LL ) return 3LL;
    if ( K % 2LL == 1LL ) return 0LL;
    Primes.clear ( );
    for ( int i = 1; i * i <= K; i++ )
    {
        if ( K % i != 0LL ) continue;
        if ( Prime ( i + 1LL ) ) Primes.push_back ( i + 1LL );
        if ( Prime ( K / i + 1LL ) ) Primes.push_back ( K / i + 1LL );
    }
    sort ( Primes.begin ( ), Primes.end ( ) );
    Primes.resize ( unique ( Primes.begin ( ), Primes.end ( ) ) - Primes.begin ( ) );
    N = INF;
    Calc ( Primes.size ( ) - 1, 1LL, K );
    if ( N == INF ) N = 0LL;
    return N;
}

int main()
{
    scanf("%lld", &K);
    printf("%lld", InverseEuler(K));
    return 0;
}
