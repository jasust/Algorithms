/*Codeforces Problem-319C Kalila and Dimna in the Logging Industry */
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long lld;

const lld llmax = 1 << 15;

int N, A[100005], B[100005];
lld DP[100005];

int main()
{
    scanf("%d", &N);

    for (int i=0; i<N; i++) scanf("%d", A+i);
    for (int i=0; i<N; i++)
    {
        scanf("%d", B+i);
        DP[i] = llmax;
    }

    DP[0] = 0;

    for (int i=1; i<N; i++)
        for (int j=0; j<i; j++)
            DP[i] = min(DP[i], DP[j] + A[i]*B[j]);

    printf("%I64d", DP[N-1]);

    return 0;
}
