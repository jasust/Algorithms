#include <cstdio>
#include <cstring>

using namespace std;

typedef long long int lld;

const int MaxLen = 1 << 20;

lld B, N, C;
char __B[MaxLen], __N[MaxLen];

inline lld Euler ( lld N )
{
    lld Ret = 1LL;

    for ( lld i = 2LL; i * i <= N; i++ ) if ( ! ( N % i ) )
                                         {
                                             Ret *= i - 1LL;
                                             N /= i;

                                             while ( ! ( N % i ) )
                                             {
                                                 Ret *= i;
                                                 N /= i;
                                             }
                                         }

    if ( N > 1LL ) Ret *= N - 1LL;

    return Ret;
}

inline lld Pow ( lld A, lld B, lld M )
{
    if ( ! B ) return 1LL;

    lld Ret = A, Base = A;
    B--;

    while ( B )
    {
        if ( B & 1LL ) Ret = ( Ret * Base ) % M;
        B >>= 1LL;
        Base = ( Base * Base ) % M;
    }

    return Ret;
}

int main ( void )
{
    scanf ( "%s %s %I64d", __B, __N, &C );

    int LenB = strlen ( __B ), LenN = strlen ( __N );

    for ( int i = 0; i < LenB; i++ )
    {
        B = B * 10LL + __B[i] - '0';
        while ( B >= C ) B -= C;
    }

    lld Phi = Euler ( C );

    for ( int i = 0; i < LenN; i++ )
    {
        N = N * 10LL + __N[i] - '0';
        while ( N >= Phi ) N -= Phi;
    }

    lld Sol = B - 1LL + C;

    N = ( N - 1LL + Phi ) % Phi + Phi;
    if ( LenN <= 10 )
    {
        lld RealN = 0LL;
        for ( int i = 0; i < LenN; i++ ) RealN = RealN * 10LL + __N[i] - '0';

        if ( RealN < Phi ) N -= Phi;
    }

    Sol = ( Sol * Pow ( B, N, C ) ) % C;

    if ( ! Sol ) Sol = C;
    printf ( "%I64d\n", Sol );

    return 0;
}
