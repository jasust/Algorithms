#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5;
const int MaxM = 1e3;

int n, q, x, y;

struct binary_indexed_tree {

  int tree[MaxN+20];

  void update(int idx, int val) {
    for (int i=idx+1; i<=MaxN; i+=i&-i) tree[i] += val;
  }

  int get(int idx) {
    int ret = 0;
    for (int i=idx+1; i; i-=i&-i) ret += tree[i];
    return ret;
  }

  int getSingle (int idx) {
    int ret = tree[++idx];
    int z = idx - (idx & -idx);
    --idx;
    while (idx != z){
        ret -= tree[idx];
        idx -= (idx & -idx);
    }
    return ret;
  }
} BIT;

struct binary_indexed_tree_2D {

  int tree[MaxM+5][MaxM+5];

  void update(int x, int y, int val) {
    for (int i=x+1; i<=MaxM; i+=(i&-i))
        for (int j=y+1; j<=MaxM; j+=(j&-j)) tree[i][j] += val;
  }

  int get(int x, int y) {
    int ret = 0;
    for (int i=x+1; i; i-=(i&-i))
        for (int j=y+1; j; j-=(j&-j)) ret += tree[i][j];
    return ret;
  }
} BIT2D;

int main() {

    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &x);
        BIT.update(x, 1);
    }
    scanf("%d", &q);
    for (int i=0; i<q; i++)
    {
        scanf("%d", &x);
        printf("%d %d\n", BIT.get(x), BIT.getSingle(x));
    }

    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d%d", &x, &y);
        BIT2D.update(x, y, 1);
    }
    scanf("%d", &q);
    for (int i=0; i<q; i++)
    {
        scanf("%d%d", &x, &y);
        printf("%d\n", BIT2D.get(x,y));
    }

    return 0;
}
