#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MaxN = 2e5+5;

struct querry {
    int type, x, w;
} upit[MaxN];

int q, n, time;
int dad[MaxN], subtree[MaxN], dubina[MaxN], chain[MaxN], idx[MaxN];
long long sol[MaxN], spoj[MaxN];
vector <int> adj[MaxN];

struct segment_tree
{
  long long tree[0x80000];

  void update(int idx, int l, int r, int levo, int desno, long long val) {
    if (levo<=l && r<=desno) {
      tree[idx] += val;
      return;
    }
    int mid = (l+r)>>1;
    if (tree[idx]) {
        update(2*idx, l, mid, l, mid, tree[idx]);
        update(2*idx+1, mid+1, r, mid+1, r, tree[idx]);
        tree[idx] = 0;
    }
    if (levo<=mid) update(2*idx, l, mid, levo, desno, val);
    if (desno>mid) update(2*idx+1, mid+1, r, levo, desno, val);
  }

  long long query(int idx, int l, int r, int levo, int desno) {
    if (levo<=l && r<=desno) return tree[idx];
    int mid = (l+r)>>1;
    if (tree[idx]) {
        update(2*idx, l, mid, l, mid, tree[idx]);
        update(2*idx+1, mid+1, r, mid+1, r, tree[idx]);
        tree[idx] = 0;
    }
    if (levo<=mid) return query(2*idx, l, mid, levo, desno);
    return query(2*idx+1, mid+1, r, levo, desno);
  }
} ST;

void DFS(int Curr, int Prev) {
  dad[Curr] = Prev;
  subtree[Curr] = 1;
  for (vector<int>::iterator it = adj[Curr].begin(); it != adj[Curr].end(); ++it)
    if (*it != Prev) {
      dubina[*it] = dubina[Curr]+1;
      DFS(*it, Curr);
      subtree[Curr] += subtree[*it];
    }
}

void HLD( int Curr, int Prev, int clr ) {
  idx[Curr] = time++;
  chain[Curr] = clr;
  int idxMax = -1;
  for (vector<int>::iterator it = adj[Curr].begin(); it != adj[Curr].end(); ++it)
    if (*it!=Prev && (idxMax==-1 || subtree[idxMax]<subtree[*it])) idxMax = *it;
  if (~idxMax) HLD(idxMax,Curr,clr);
  for (vector<int>::iterator it = adj[Curr].begin(); it != adj[Curr].end(); ++it)
    if (*it!=Prev && *it!=idxMax) HLD(*it, Curr, *it);
}

void update(int a, int val) {
  while (chain[a] != 0) {
    if (a>chain[a]) ST.update(1, 0, n, idx[chain[a]], idx[a]-1, val);
    spoj[chain[a]] += val;
    if (spoj[chain[a]]>sol[dad[chain[a]]]) sol[dad[chain[a]]] = spoj[chain[a]];
    a = dad[chain[a]];
  }
  if (a != 0) ST.update(1, 0, n, 0, idx[a]-1, val);
}

int main() {

    scanf("%d", &q);
    for (int i=0; i<q; i++) {
        scanf("%d%d", &upit[i].type, &upit[i].x);
        upit[i].x--;
        if (upit[i].type==1) {
            n++;
            scanf("%d", &upit[i].w);
            adj[upit[i].x].push_back(n);
            adj[n].push_back(upit[i].x);
            upit[i].x = n;
        }
    }
    DFS(0,-1);
    HLD(0,-1,0);

    for (int i=0; i<q; i++) {
        if (upit[i].type==1) update(upit[i].x, upit[i].w);
        else {
            long long res = ST.query(1, 0, n, idx[upit[i].x], idx[upit[i].x]);
            if (sol[upit[i].x]>res) res = sol[upit[i].x];
            printf("%lld\n", res);
        }
    }

    return 0;
}
