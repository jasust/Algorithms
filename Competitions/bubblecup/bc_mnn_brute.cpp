#include <cstdio>
using namespace std;

const int MOD = 1e9 + 7;
const int maxN = 1e6 + 6;

int n, m, res, a, l;
int w[maxN], b[maxN];
long long num[103], start[103];
long long dp[2][103];

int main() {

    scanf("%d%d%d", &n, &l, &m);

    for (int i=0; i<m; i++) start[i] = num[i] = 0;

    for (int i=0; i<n; i++) {
        scanf("%d", &a);
        ++start[a];
    }
    for (int i=0; i<n; i++) {
        scanf("%d", w+i);
        ++num[w[i]];
    }
    for (int i=0; i<n; i++) scanf("%d", b+i);

    for (int i=0; i<m; i++) dp[0][i] = start[i];
    for (int i=1; i<l-1; i++)
        for (int j=0; j<m; j++) {
            dp[i&1][j] = 0;
            for (int k=0; k<m; k++) dp[i&1][j] = (dp[i&1][j]+dp[(i-1)&1][(m+j-k)%m]*num[k])%MOD;
        }

    for (int i=0; i<n; i++) {
        res += dp[(l-2)&1][(2*m-w[i]-b[i])%m];
        if (res>MOD) res -= MOD;
    }

    printf("%d", res);
    return 0;
}
