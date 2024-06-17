#include <cstdio>

const int max_n = 1e4 + 14;

int n, k, x, temp, idx, ret = -1;

struct fenwick_tree
{
  int t[max_n];
  void clear() {for (int i = 0; i < max_n; i++) t[i] = 0;}
  void update(int idx) {for (int i = idx; i < max_n; i += i & -i) t[i]++;}
  int query(int idx)
  {
    int ret = 0;
    for (int i = idx; i; i -= i & -i) ret += t[i];
    return ret;
  }
} BIT;

int main()
{
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= k; i++)
  {
    BIT.clear();
    temp = 0;
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &x);
      x = n - x + 1;
      temp += BIT.query(x);
      BIT.update(x);
    }
    if (temp > ret) ret = temp, idx = i;
  }
  printf("%d", idx);
  return 0;
}
