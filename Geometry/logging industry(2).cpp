/*Codeforces Problem-319C Kalila and Dimna in the Logging Industry */
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long lld;

const int maxn = 1e5 + 5;

int N;
lld Dp[maxn], A[maxn], B[maxn];
vector < int > hull;

lld y_koordinata(int k, int x)
{
    return x * B[k] + Dp[k];
}

double x_koordinata_preseka(int X, int Y)
{
    return double(Dp[Y] - Dp[X]) / double(B[X] - B[Y]);
}

int main()
{
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", A + i);
    for (int i=0; i<N; i++) scanf("%d", B + i);

    hull.push_back(0);
    int br = 0;

    for (int i=1; i<N; i++)
    {
        while (br+1 < hull.size() && y_koordinata(hull[br+1], A[i]) < y_koordinata(hull[br], A[i])) br++;
        Dp[i] = y_koordinata(hull[br], A[i]);
        while (br+1 < hull.size() && x_koordinata_preseka(hull.back(), i) <= x_koordinata_preseka(hull[hull.size()-2], hull.back()))
            hull.pop_back();
        hull.push_back(i);
    }

    printf("%I64d\n", Dp[N - 1]);

    return 0;
}
