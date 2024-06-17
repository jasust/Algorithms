/*
  Data su dva niza brojeva: a i b. Dati su upiti
  dva tipa. Upit prvog tipa je oblika x, y, k, sto
  znaci da treba iskopirati k elemenata iz niza a
  pocevsi od indeksa x u niz b pocevsi od indeksa y.
  Na upit drugog tipa se odgovara ispisivanjem clana
  b[i], gde je i zadato.
*/

#include <vector>
#include <iostream>

using namespace std;

const int max_n = 1 << 18;

struct segment_tree
{
  int tree[max_n * 2];
  segment_tree() {for (int i = 0; i < 2 * max_n; i++) tree[i] = -1;}
  void update(int idx, int l, int r, int levi, int desni, int val)
  {
    if (levi <= l && r <= desni) return void(tree[idx] = val);
    int mid = (l + r) / 2;
    if (levi <= mid) update(2 * idx, l, mid, levi, desni, val);
    if (desni > mid) update(2 * idx + 1, mid + 1, r, levi, desni, val);
  }
  int query(int idx, int l, int r, int pos)
  {
    if (l == r) return tree[idx];
    int mid = (l + r) / 2;
    return max(tree[idx], pos <= mid ? query(2 * idx, l, mid, pos) : query(2 * idx + 1, mid + 1, r, pos));
  }
} st;

int n, q, t, x, y, k, a[max_n], b[max_n];
vector<pair<int, int> > niz;

int main()
{
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  while (q--)
  {
    cin >> t;
    if (--t)
    {
      cin >> x;
      y = st.query(1, 0, n - 1, --x);
      cout << (~y ? a[niz[y].first + x - niz[y].second] : b[x]) << endl;
    }
    else
    {
      cin >> x >> y >> k;
      niz.push_back(make_pair(--x, --y));
      st.update(1, 0, n - 1, y, y + k - 1, niz.size() - 1);
    }
  }
  return 0;
}
