#include <cstdio>
using namespace std;

const int MOD = 1e9 + 7;
const int maxN = 1e6 + 6;

int n, m, res, a, l;
int w[maxN], b[maxN];
long long num[103], start[103], finish[103];
long long mat[103][103], sol[103][103];

void matmul (long long f[103][103], long long s[103][103]) {

    long long hlp[103][103];
    for (int i=0; i<m; i++)
        for (int j=0; j<m; j++)
            hlp[i][j] = 0;

    for (int k=0; k<m; k++)
        for (int i=0; i<m; i++)
            for (int j=0; j<m; j++)
                hlp[i][j] = (hlp[i][j] + f[i][k]*s[k][j])%MOD;

    for (int i=0; i<m; i++)
        for (int j=0; j<m; j++)
            f[i][j] = hlp[i][j];
}

void step (int exp) {

    if (exp==1) return;
    step(exp>>1);
    matmul(sol, sol);
    if (exp&1) matmul(sol, mat);
}

int main() {

    scanf("%d%d%d", &n, &l, &m);

    for (int i=0; i<m; i++) start[i] = num[i] = finish[i] = 0;

    for (int i=0; i<n; i++) {
        scanf("%d", &a);
        ++start[a];
    }
    for (int i=0; i<n; i++) {
        scanf("%d", w+i);
        ++num[w[i]];
    }
    for (int i=0; i<n; i++) scanf("%d", b+i);

    for (int i=0; i<m; i++)
        for (int j=0; j<m; j++)
            sol[i][j] = mat[i][j] = (i>j)?(num[m+j-i]):(num[j-i]);

    if (l>2) {
        step(l-2);
        for (int k=0; k<m; k++)
            for (int i=0; i<m; i++)
                finish[i] = (finish[i]+start[k]*sol[k][i])%MOD;
    } else for (int i=0; i<m; i++) finish[i] = start[i];

    for (int i=0; i<n; i++) {
        res += (int)finish[(2*m-w[i]-b[i])%m];
        if (res>MOD) res -= MOD;
    }

    printf("%d", res);
    return 0;
}
