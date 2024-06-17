#include <cstdio>
#define MOD 1000000007
using namespace std;

int t, n, m, q, l, r, d;
int a[100005];
int f[10000007];

struct segment_tree {

  struct node {
    int sum1, sum2, mark;
  } tree[1000009];

  void init(int idx, int l, int r) {

    if (l == r) {
        tree[idx].sum1 = f[a[l]+1];
        tree[idx].sum2 = f[a[l]+2];
        tree[idx].mark = 0;
        return;
    }
    int mid = (l+r)>>1;
    init(2*idx, l, mid);
    init(2*idx+1, mid+1, r);
    tree[idx].sum1 = tree[2*idx].sum1 + tree[2*idx+1].sum1;
    if (tree[idx].sum1>=MOD) tree[idx].sum1 -= MOD;
    tree[idx].sum2 = tree[2*idx].sum2 + tree[2*idx+1].sum2;
    if (tree[idx].sum2>=MOD) tree[idx].sum2 -= MOD;
    tree[idx].mark = 0;
  }

  void update(int idx, int l, int r, int levo, int desno, int k) {

    if (levo <= l && r <= desno) {
      tree[idx].mark += k;
      int pom = tree[idx].sum1;
      tree[idx].sum1 = (1LL*f[k]*tree[idx].sum2 + 1LL*f[k-1]*pom)%MOD;
      tree[idx].sum2 = (1LL*f[k+1]*tree[idx].sum2 + 1LL*f[k]*pom)%MOD;
      return;
    }
    int mid = (l+r)>>1;
    if (tree[idx].mark) {
        update(2*idx, l, mid, l, mid, tree[idx].mark);
        update(2*idx+1, mid+1, r, mid+1, r, tree[idx].mark);
        tree[idx].mark = 0;
    }
    if (levo<=mid) update(2*idx, l, mid, levo, desno, k);
    if (desno>mid) update(2*idx+1, mid+1, r, levo, desno, k);
    tree[idx].sum1 = tree[2*idx].sum1 + tree[2*idx+1].sum1;
    if (tree[idx].sum1>=MOD) tree[idx].sum1 -= MOD;
    tree[idx].sum2 = tree[2*idx].sum2 + tree[2*idx+1].sum2;
    if (tree[idx].sum2>=MOD) tree[idx].sum2 -= MOD;
  }

  int query(int idx, int l, int r, int levo, int desno) {

    if (levo <= l && r <= desno) return tree[idx].sum1;
    int mid = (l+r)>>1;
    int ret = 0;
    if (tree[idx].mark) {
        update(2*idx, l, mid, l, mid, tree[idx].mark);
        update(2*idx+1, mid+1, r, mid+1, r, tree[idx].mark);
        tree[idx].mark = 0;
    }
    if (levo <= mid) ret += query(2*idx, l, mid, levo, desno);
    if (desno > mid) ret += query(2*idx+1, mid+1, r, levo, desno);
    if (ret>=MOD) ret-=MOD;
    return ret;
  }
} st;

int main() {

    scanf("%d", &t);
    f[0] = 0; f[1] = 1;
    for (int i=2; i<10000007; i++) { f[i]=f[i-1]+f[i-2]; if (f[i]>=MOD) f[i]-=MOD; }
    while (t--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) scanf("%d", a+i);
        st.init(1, 0, n-1);
        scanf("%d", &q);
        while (q--) {
            scanf("%d %d %d", &m, &l, &r);
            if (m==1) printf("%d\n", st.query(1, 0, n-1, l-1, r-1));
            else { scanf("%d", &d); if (d) st.update(1, 0, n-1, l-1, r-1, d); }
        }
    }
    return 0;
}
