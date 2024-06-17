/* Dat je niz brojeva a[i] tako da za i-tu tacku mora da vazi x[i]+y[i] = a[i].
   Koliko nerastucih funkcija postoji koje zadovoljavaju ovaj uslo.
                  Slozenost O(n*a)                                           */
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 3003, maxa = 10004;
int dp[maxn][maxa], a[maxn], n;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", a + i);
    for (int i=a[n]; i>=0; i--) dp[n][i] = dp[n][i+1] + 1;

    for (int i=n-1; i; i--)
     for (int j=a[i]; j>=0; j--)
      if (a[i] < a[i+1]) dp[i][j] = dp[i][j+1] + dp[i+1][j+a[i+1]-a[i]];
       else dp[i][j] = dp[i][j+1] + dp[i+1][j];

    printf("%d", dp[1][0]);
    return 0;
}
