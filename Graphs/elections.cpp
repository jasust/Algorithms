// Codeforces Problem 369C - Valera and Elections
#include <cstdio>
#include <vector>
using namespace std;
const int maxn=1e5 + 5;

int n, x, y, z, s[maxn];
vector <int> sol, a[maxn], l[maxn];

void dfs(int c,int p)
{
    for (int i=0; i<a[c].size(); i++)
        if (a[c][i]!=p)
        {
            dfs(a[c][i],c);
            s[c]+=s[a[c][i]];
        }
    for (int i=0; i<l[c].size(); i++)
        if (l[c][i]==p&&!s[c])
        {
            s[c]=1;
            sol.push_back(c);
        } else break;
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<n; i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        a[x].push_back(y);
        a[y].push_back(x);
        if (z == 2)
        {
            l[x].push_back(y);
            l[y].push_back(x);
        }
    }

    dfs(1,0);

    printf("%d\n", sol.size());
    while (!sol.empty()) printf("%d ",sol.back()), sol.pop_back();

    return 0;
}
