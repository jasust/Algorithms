#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct S_Tree
{
  struct node
  {
    long long curr, ever, markCurr, markEver;
  } tree[2000012];
  void update( int idx, int l, int r, int levo, int desno, int val )
  {
    if ( levo <= l && r <= desno)
    {
      tree[idx].markCurr += 1LL*val;
      tree[idx].curr += 1LL * val;
      if (tree[idx].curr>tree[idx].ever) tree[idx].ever = tree[idx].curr;
      return;
    }
    int mid = (l+r) >> 1;
    update( 2*idx, l, mid, l, mid, tree[idx].markCurr );
    update( 2*idx+1, mid+1, r, mid+1, r, tree[idx].markCurr );
    if ( levo<=mid ) update( 2*idx, l, mid, levo, desno, val);
    if ( desno>mid ) update( 2*idx+1, mid+1, r, levo, desno, val);
    tree[idx].markCurr = 0;
    tree[idx].curr = max(tree[2*idx].curr,tree[2*idx+1].curr);
    if (tree[idx].curr>tree[idx].ever) tree[idx].ever = tree[idx].curr;
  }
  long long query( int idx, int l, int r, int levo, int desno)
  {
    if (levo<=l && r<=desno) return tree[idx].ever;
    int mid = (l+r)>>1;
    tree[2*idx].markCurr+=tree[idx].markCurr;
    tree[2*idx+1].markCurr+=tree[idx].markCurr;
    tree[2*idx].curr+=tree[idx].markCurr;
    tree[2*idx+1].curr+=tree[idx].markCurr;
    if (tree[2*idx].curr>tree[2*idx].ever) tree[2*idx].ever = tree[2*idx].curr;
    if (tree[2*idx+1].curr>tree[2*idx+1].ever) tree[2*idx+1].ever = tree[2*idx+1].curr;
    tree[idx].markCurr=0;
    tree[idx].curr = max(tree[2*idx].curr,tree[2*idx+1].curr);
    if (tree[idx].curr>tree[idx].ever) tree[idx].ever = tree[idx].curr;
    if (desno<=mid) return query(2*idx,l,mid,levo,desno);
    if (levo>mid) return query(2*idx+1, mid+1, r, levo, desno);
    return max(query(2*idx, l, mid, levo, desno), query(2*idx+1, mid+1, r, levo, desno));
  }
} segment_tree;

int n;

long long sol[1000006];

struct cvor {

    int r,p,a,b,idx;

} players[200005];

bool cmp(cvor _a, cvor _b) { return _a.r<_b.r; }

int main()
{
    scanf("%d",&n);
    for (int i=0; i<n; i++)
    {
        scanf("%d%d%d%d", &players[i].r, &players[i].p, &players[i].a, &players[i].b);
        players[i].idx = i;
    }
    sort(players,players+n,cmp);

    for (int i=0; i<n; i++)
    {
        sol[players[i].idx] = segment_tree.query(1,0,2000002,--players[i].a,--players[i].b)+players[i].p;
        segment_tree.update(1,0,2000002,players[i].a,players[i].b,players[i].p);
    }

    for (int i=0; i<n; i++) printf("%lld\n", sol[i]);
    return 0;
}
/*
4
15 22 2 5
13 -7 5 8
9 -5 3 7
12 13 5 6
*/
