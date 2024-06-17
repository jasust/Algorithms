//Dijkstrin algoritam za nalazenje duzina najkracih puteva iz jednog izvora u grafu
//Slozenost: O(M log N)
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 2147483647;

struct node
{
    int x, val;
    node( int _x, int _val ) { x = _x; val = _val; }
};

int n, k, m, i, j, x, y, val, curr, d[1003];
bool o[1003];
vector <node> a[1003];
struct cmp {
  bool operator() (const int& lhs, const int& rhs) const
  {return d[lhs]<d[rhs];}
};
set <int, cmp> s;
set <int, cmp>::iterator it;

void dijkstra(int source)
{
    d[source] = 0; o[source] = true;
    for (i=0; i<n; i++) if (i!=source) d[i]=inf;
    for (i=0; i<a[source].size(); i++)
    {
        d[a[source][i].x] = a[source][i].val;
        s.insert(a[source][i].x);
    }

    for (i=1; i<n; i++)
    {
        it = s.begin();
        curr = *it;
        o[curr] = true;
        s.erase(curr);
        for (j=0; j<a[curr].size(); j++)
        if (!o[a[curr][j].x] && d[curr]+a[curr][j].val<d[a[curr][j].x])
        {
            if (d[a[curr][j].x]<inf) s.erase(a[curr][j].x);
            d[a[curr][j].x] = d[curr]+a[curr][j].val;
            s.insert(a[curr][j].x);
        }
    }

    return;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (i=0; i<m; i++)
    {
        scanf("%d %d %d", &x, &y, &val);
        a[x-1].push_back(node(y-1,val));
    }
    dijkstra(k-1);
    for (i=0; i<n; i++) printf("%d ", d[i]);
    return 0;
}

