/*
  Dat je niz brojeva i upiti nad njim.
  Upit prvog tipa zahteva da se uvecaju svi
  brojevi na intervalu od l do r za po 1. Drugi
  upit zahteva da se ispise koliko ima brojeva
  koji su deljivi sa 3 i indeksi su im od l do r.
*/

#include <cstdio>

const int max_n = 1 << 17;

struct segment_tree
{
  struct node
  {
    int cnt[4];
    int add;
  } tree[2 * max_n];
  void init(int idx, int l, int r)
  {
    if (l == r) return void(tree[idx].cnt[tree[idx].add = 0] = 1);
    int mid = (l + r) / 2;
    init(2 * idx, l, mid);
    init(2 * idx + 1, mid + 1, r);
    tree[idx].cnt[0] = tree[2 * idx].cnt[0] + tree[2 * idx + 1].cnt[0];
    tree[idx].add = 0;
  }
  void update(int idx, int l, int r, int levo, int desno)
  {
    if (levo <= l && r <= desno)
    {
      tree[idx].add = (tree[idx].add + 1) % 3;
      for (int i = 3; i >= 0; i--) tree[idx].cnt[i] = tree[idx].cnt[(i + 3) & 3];
      return;
    }
    int mid = (l + r) / 2;
    if (levo <= mid) update(2 * idx, l, mid, levo, desno);
    if (desno > mid) update(2 * idx + 1, mid + 1, r, levo, desno);
    for (int i = 0; i < 3; i++) tree[idx].cnt[i] = tree[2 * idx].cnt[i] + tree[2 * idx + 1].cnt[i];
    for (int i = 0; i < tree[idx].add; i++)
      for (int j = 3; j >= 0; j--) tree[idx].cnt[j] = tree[idx].cnt[(j + 3) & 3];
  }
  int query(int idx, int l, int r, int levo, int desno, int add = 0)
  {
    if (levo <= l && r <= desno) return tree[idx].cnt[(3 - add % 3) % 3];
    int mid = (l + r) / 2;
    int ret = 0;
    if (levo <= mid) ret += query(2 * idx, l, mid, levo, desno, add + tree[idx].add);
    if (desno > mid) ret += query(2 * idx + 1, mid + 1, r, levo, desno, add + tree[idx].add);
    return ret;
  }
} st;

int n, q, t, x, y;

int main()
{
  scanf("%d %d", &n, &q);
  st.init(1, 0, n - 1);
  while (q--)
  {
    scanf("%d %d %d", &t, &x, &y);
    if (t) printf("%d\n", st.query(1, 0, n - 1, x, y));
    else st.update(1, 0, n - 1, x, y);
  }
  return 0;
}
