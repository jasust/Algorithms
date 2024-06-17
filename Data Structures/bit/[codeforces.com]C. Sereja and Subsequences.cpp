#include <iostream>

using namespace std;

const int max_n = 1e5 + 15;
const int max_val = 1e6 + 16;
const int MOD = 1e9 + 7;

void upd(int &a, int b) {a = (1LL * a + b + MOD) % MOD;}

struct fenwick
{
  int tree[max_val];
  void update(int idx, int val) {for (; idx < max_val; idx += idx & -idx) upd(tree[idx], val);}
  int query(int idx)
  {
    int ret = 0;
    for (; idx; idx -= idx & -idx) upd(ret, tree[idx]);
    return ret;
  }
} BIT;

int n, x, q[max_val];

int main()
{
  for (cin >> n; n--;)
  {
    cin >> x;
    int temp = (1LL * BIT.query(x) * x + x) % MOD;
    BIT.update(x, temp - q[x]);
    q[x] = temp;
  }
  cout << BIT.query(max_val - 1);
  return 0;
}
