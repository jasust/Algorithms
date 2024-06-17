#include <cstdio>

const int max_n = 1e5 + 15;

struct fenwick
{
  int tree[max_n];
  void update(int idx, int val) {for (int i = idx; i < max_n; i += i & -i) tree[i] += val;}
  int query(int idx)
  {
    int ret = 0;
    for (int i = idx; i; i -= i & -i) ret += tree[i];
    return ret;
  }
} bit;

int n, k, l, r;

int main()
{
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) bit.update(i, 1);
  for (int i = 0, curr = k; i < n; i++)
  {
    printf("%d ", curr);
    bit.update(curr, -1);
    if (n - i == 1) break;
    int tar = k;
    if (tar > bit.query(n) - bit.query(curr))
    {
      tar -= bit.query(n) - bit.query(curr);
      if (tar > n - i - 1) tar %= (n - i - 1);
      if (!tar) tar = n - i - 1;
    }
    else tar += bit.query(curr);
    for (l = 1, r = n; l < r;)
    {
      int mid = (l + r) / 2;
      if (bit.query(mid) < tar) l = mid + 1;
      else r = mid;
    }
    curr = l;
  }
  return 0;
}
