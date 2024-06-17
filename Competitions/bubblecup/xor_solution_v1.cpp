#include <cstdio>
#include <vector>
using namespace std;

long long mod = 1000000007;
long long maxSol = 1 << 17;

int n, m, u, v, w, t, total, sol;
long long invP;
int d[200005];
bool o[200005];
pair<int,int> p[200005];
long long num[(1<<18)+5], curr[(1<<18)+5];
vector< pair<int,int> > a[200005];

long long step(long long a,long long b) {
    if (b==0) return 1;
    if (b&1) return ((a * step(a, b-1)) % mod);
    else return step((a * a) % mod, b>>1);
}

void FWHT(long long* x, bool inv) {
    for (int l=1; (l<<1)<=maxSol; l<<=1)
        for (int i=0; i<maxSol; i+=(l<<1))
            for (int j=0; j<l; ++j) {
                u = x[i + j];
                v = x[i + j + l];
                x[i + j] = (u + v) % mod;
                x[i + j + l] = (u - v + mod) % mod;
            }

    if (inv)
        for(int i=0; i<maxSol; ++i)
            x[i] = (x[i]*invP) % mod;
}

void dfs(int node) {
    o[node] = true;
    d[node] = t++;
    for (int j=0; j<a[node].size(); ++j) {
        if (p[node].first != a[node][j].first) {
            if (o[a[node][j].first] && d[a[node][j].first]<d[node]) {
                for (int i=0; i<maxSol; ++i) curr[i]=0;
                curr[a[node][j].second]++;
                int tmp = node;
                while(tmp != a[node][j].first) {
                    curr[p[tmp].second]++;
                    tmp = p[tmp].first;
                }
                FWHT(curr, false);
                for (int i=0; i<maxSol; ++i)
                    num[i] = (num[i]*curr[i]) % mod;
            } else if(!o[a[node][j].first]) {
                p[a[node][j].first] = make_pair(node, a[node][j].second);
                dfs(a[node][j].first);
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    invP = step(maxSol, mod-2);

    for (int i=0; i<m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        a[u-1].push_back(make_pair(v-1,w));
        a[v-1].push_back(make_pair(u-1,w));
        total ^= w;
    }

    num[0] = 1;
    FWHT(num, false);
    dfs(0);
    FWHT(num, true);

    sol = maxSol;
    for(int i=0; i<maxSol; ++i)
        if (num[i] && (total^i) < sol)
            sol = total^i;
    printf("%d %d", sol, num[sol^total]);

    return 0;
}

/* Example:
6 6
4 1 5
5 2 1
6 3 2
1 2 6
1 3 3
2 3 4
*/
