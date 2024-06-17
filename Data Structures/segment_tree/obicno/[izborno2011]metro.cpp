/*
  Dat je niz brojeva i niz upita.
  Upit prvog tipa menja i-ti clan niza.
  Upit drugog tipa trazi da se ispise
  koliko okolnih polja moze da se obidje
  za zadato trenutno polje i za zadatu
  vrednost k.
  Ako se nalazimo na i-tom polju i trenutna
  vrednost je k, mozemo se kretati na sva susedna
  polja, sve dok su ona deljiva sa k.
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int max_n = 2e5 + 25;
const int max_log = 1 << 18;
const int oo = 0x3f3f3f3f;

int n, q, t, x, y;

int gcd(int a, int b)
{
  return !b ? a : gcd(b, a % b);
}

struct segment_tree
{
  int tree[2 * max_log];
  int mid(int l, int r) {return (l + r) / 2;}
  int ls(int idx) {return 2 * idx;}
  int rs(int idx) {return 2 * idx + 1;}
  void update(int idx, int l, int r, int pos, int val)
  {
    if (l == r)
    {
      tree[idx] = val;
      return;
    }
    if (pos <= mid(l, r)) update(ls(idx), l, mid(l, r), pos, val);
    else update(rs(idx), mid(l, r) + 1, r, pos, val);
    tree[idx] = gcd(tree[ls(idx)], tree[rs(idx)]);
  }
  int left(int idx, int l, int r, int pos, int k)
  {
    if (l == r) return tree[idx] % k ? l : -oo;
    int ret = -oo;
    if (pos > mid(l, r) && tree[rs(idx)] % k)
      ret = max(ret, left(rs(idx), mid(l, r) + 1, r, pos, k));
    if (ret == -oo && tree[ls(idx)] % k)
      ret = max(ret, left(ls(idx), l, mid(l, r), pos, k));
    return ret;
  }
  int right(int idx, int l, int r, int pos, int k)
  {
    if (l == r) return tree[idx] % k ? r : oo;
    int ret = oo;
    if (pos <= mid(l, r) && tree[ls(idx)] % k)
      ret = min(ret, right(ls(idx), l, mid(l, r), pos, k));
    if (ret == oo && tree[rs(idx)] % k)
      ret = min(ret, right(rs(idx), mid(l, r) + 1, r, pos, k));
    return ret;
  }
  int query(int pos, int k)
  {
    int l = left(1, 0, n - 1, pos, k);
    int r = right(1, 0, n - 1, pos, k);
    if (l == -oo) l = -1;
    if (r == oo) r = n;
    return r - l - 1;
  }
} st;

int main()
{
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", &x), st.update(1, 0, n - 1, i, x);
  while (q--)
  {
    scanf("%d %d %d", &t, &x, &y);
    if (--t) printf("%d\n", st.query(--x, y));
    else st.update(1, 0, n - 1, --x, y);
  }
  return 0;
}
