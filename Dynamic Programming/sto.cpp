#include <iomanip>
#include <iostream>
#include <cstdio>
using namespace std;

int n, l;
double ret, f[55], dp[55][55];

int main()
{
  *f = 1;
  for (int i = 1; i < 55; i++) f[i] = f[i - 1] * i;
  **dp = 1;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> l;
    for (int cnt = i+1; cnt > 0; cnt--)
      for (int w = 50; w - l >= 0; w--)
        dp[cnt][w] += dp[cnt - 1][w - l];
  }
  cin >> l;
  for (int i = 1; i <= n; i++) {
    for (int w = 1; w <= l; w++) { printf("%.f ", dp[i][w]); ret += f[i] * f[n - i] * dp[i][w]; } printf("\n"); }
  cout << setprecision(10) << ret / f[n];
  return 0;
}
