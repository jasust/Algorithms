#include <iostream>

using namespace std;

const int MOD = 1e9 + 9;
const int max_n = 1111;
const int max_lim = 33;

int n, lim, ret, dp[3][3][max_lim][max_lim][max_lim];

int nxt(int x)
{
  return min(x + 1, lim);
}

void upd(int &x, int y)
{
  x += y;
  if (x > MOD) x -= MOD;
}

int main()
{
  cin >> n >> lim;
  dp[0][1][0][0][0] = 1;
  for (int h = 0; h < n; h++)
    for (int i = 0; i <= lim; i++)
      for (int j = 0; j <= lim; j++)
        for (int k = 0; k <= lim; k++)
          for (int valid = 0; valid <= 1; valid++)
          {
            int temp = dp[h & 1][valid][i][j][k];
            int l = valid ? 1 : lim;
            upd(dp[h & 1 ^ 1][valid][nxt(i)][nxt(j)][nxt(k)], temp);
            upd(dp[h & 1 ^ 1][i < lim][l][nxt(j)][nxt(k)], temp);
            upd(dp[h & 1 ^ 1][j < lim][l][nxt(i)][nxt(k)], temp);
            upd(dp[h & 1 ^ 1][k < lim][l][nxt(i)][nxt(j)], temp);
            dp[h & 1][valid][i][j][k] = 0;
          }
  for (int i = 0; i <= lim; i++)
    for (int j = 0; j <= lim; j++)
      for (int k = 0; k <= lim; k++)
        for (int valid = 0; valid <= 1; valid++)
          if (i < lim || j < lim || k < lim || valid)
            upd(ret, dp[n & 1][valid][i][j][k]);
  cout << ret;
  return 0;
}
