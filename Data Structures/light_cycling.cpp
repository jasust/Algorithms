#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, i, j;
long long int sol, x, y, d;
char ch[3];
struct node {
    long long int a, l, r;
    node(long long int _a, long long int _l, long long int _r)
    { a = _a; l = _l; r = _r; }
};
vector <node> horizontal, vertical;
bool cmp (node w, node ww) { return w.a<ww.a; }
bool cmp1 (node w, node ww) { return w.l<ww.l; }
struct cmp2 {
  bool operator() (const node & w, const node & ww) const
  { return w.r>ww.r; }
};
priority_queue <node, vector<node>, cmp2> up;

struct binary_indexed_tree
{
  long long int tree[1000006];
  void update(int idx, long long int val)
  {
    for (int k=idx+1; k<1000002; k+=k&-k) tree[k] += val;
  }
  long long int get(int idx)
  {
    long long int ret = 0;
    for (int k=idx+1; k; k-=k&-k) ret += tree[k];
    return ret;
  }
  void clr() { for (int k=0; k<1000002; k++) tree[k] = 0; }
} BIT;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%*s");
        scanf("%lld%lld%d", &x, &y, &n);
        for (i=0; i<n; i++)
        {
            scanf("%s%lld", ch, &d);
            if (ch[0]=='U') { vertical.push_back(node(x, y, y+d)); y += d; }
            if (ch[0]=='D') { vertical.push_back(node(x, y-d, y)); y -= d; }
            if (ch[0]=='L') { horizontal.push_back(node(y, x-d, x)); x -= d; }
            if (ch[0]=='R') { horizontal.push_back(node(y, x, x+d)); x += d; }
        }
        scanf("%lld%lld%d", &x, &y, &n);
        for (i=0; i<n; i++)
        {
            scanf("%s%lld", ch, &d);
            if (ch[0]=='U') { vertical.push_back(node(x, y, y+d)); y += d; }
            if (ch[0]=='D') { vertical.push_back(node(x, y-d, y)); y -= d; }
            if (ch[0]=='L') { horizontal.push_back(node(y, x-d, x)); x -= d; }
            if (ch[0]=='R') { horizontal.push_back(node(y, x, x+d)); x += d; }
        }
        sort(horizontal.begin(),horizontal.end(),cmp1);
        sort(vertical.begin(),vertical.end(),cmp);
        sol = 0; j = 0;
        BIT.clr();
        for (i=0; i<vertical.size(); i++)
        {
            while (j<horizontal.size() && horizontal[j].l<vertical[i].a)
            {
                up.push(horizontal[j]);
                BIT.update((int)horizontal[j].a, 1);
                j++;
            }
            while (!up.empty() && up.top().r<=vertical[i].a)
            {
                BIT.update((int)up.top().a, -1);
                up.pop();
            }
            sol += BIT.get(vertical[i].r-1) - BIT.get(vertical[i].l);
        }
        printf("%lld\n", sol);
        while (!up.empty()) up.pop();
        horizontal.clear();
        vertical.clear();
    }
    return 0;
}
