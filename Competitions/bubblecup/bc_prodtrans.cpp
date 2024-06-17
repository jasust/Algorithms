#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 1e6+200;

int n, m, a, q, phi;
long long st;
int lp[MaxN], exp[MaxN];
long long dp[MaxN], idp[MaxN];
vector<int> pr;

long long step(int x, int s, int mod) {

	if (!s) return 1;
	long long sol = step(x, s>>1, mod);
	sol = (sol*sol) % mod;
    if (s&1) sol = (sol*x) % mod;
	return sol;
}

int main() {

    scanf("%d%d%d%d", &n, &m, &a, &q);

    for (int i=2; i<MaxN; i++) {
        if (lp[i] == 0) {
            if (step(a, i, q) == 1) { phi = i; break; }
            else { lp[i] = i; pr.push_back(i); }
        }
        for (int j=0; j<pr.size() && pr[j]<=lp[i] && 1LL*i*pr[j]<1LL*MaxN; j++) lp[i*pr[j]] = pr[j];
    }

    cout << phi << endl;

    dp[0] = idp[0] = 1;
    for (int i=1; i<phi; i++) {
        dp[i] = (dp[i-1]*i) % phi;
        idp[i] = step(dp[i], phi-2, phi);
    }

    for (int i=0; i<n; i++) {
        if (i<=m) st += (dp[m]*((idp[i]*idp[m-i])%phi))%phi;
        if (st>=phi) st -= phi;
        exp[n-i-1] = (int)st;
    }

    for (int i=0; i<n; i++) printf("%lld ", step(a, exp[i], q));
    return 0;
}
