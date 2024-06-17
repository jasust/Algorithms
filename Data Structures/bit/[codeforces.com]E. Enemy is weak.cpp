#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1e6 + 16;

struct fenwick
{
  int tree[max_n];
  void clear() {for (int i = 0; i < max_n; i++) tree[i] = 0;}
  void update(int idx) {for (int i = idx; i < max_n; i += i & -i) tree[i]++;}
  int sum(int idx)
  {
    int ret = 0;
    for (int i = idx; i; i -= i & -i) ret += tree[i];
    return ret;
  }
} bit;

long long n, ret, niz[max_n], a[max_n], levoveci[max_n], desnomanji[max_n];
map<int, int> m;

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> niz[i];
    a[i] = niz[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) m[a[i]] = i + 1;
  for (int i = 0; i < n; i++) niz[i] = m[niz[i]];
  for (int i = 0; i < n; i++)
  {
    levoveci[i] = bit.sum(n) - bit.sum(niz[i]);
    bit.update(niz[i]);
  }
  bit.clear();
  for (int i = n - 1; i >= 0; i--)
  {
    desnomanji[i] = bit.sum(niz[i]);
    bit.update(niz[i]);
  }
  for (int i = 0; i < n; i++) ret += levoveci[i] * desnomanji[i];
  cout << ret;
  return 0;
}
