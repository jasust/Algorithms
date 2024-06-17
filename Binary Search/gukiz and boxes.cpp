#include <cstdio>
#include <iostream>
using namespace std;

int n, m;
long long a[100005], b[100005];

bool possible(long long v) {

    for (int i=0; i<n; i++) a[i] = b[i];
    int curr = n-1;
    int em = m;
    while (curr!=-1 && em--) {
        long long pom = v;
        while (curr!=-1 && !a[curr]) curr--;
        pom -= curr+1;
        while (curr!=-1 && pom>0)
            if (pom<a[curr]) { a[curr] -= pom; pom = 0; }
                else { pom-=a[curr]; a[curr--]=0; }
    }
    while (curr!=-1 && !a[curr]) curr--;
    if (curr==-1) return true;
        else return false;
}

long long binary() {
    long long l = 1, r = 100000000100000LL, mid;
    while (l<=r) {
        mid = (l+r)>>1;
        if (possible(mid)) r = mid-1; else l = mid+1;
    }
    return l;
}

int main() {

    cin >> n >> m;
    for (int i=0; i<n; i++) scanf("%I64d", b+i);

    long long t = binary();
    cout << t;

    return 0;
}
