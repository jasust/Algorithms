#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

struct p {

    int pos;
    char c;
} a[100005];

bool cmp (p f, p s) {
    if (f.c == s.c) return f.pos<s.pos;
    return f.c>s.c;
}

char c;
int t, n;
int sol[100005];

int main() {

    scanf("%d", &t);
    while (t--) {
        scanf("%d%*c", &n);
        for (int i=0; i<n; ++i) {
            scanf("%c", &c);
            a[i].c = c;
            a[i].pos = i+1;
        }
        sort(a, a+n, cmp);
        set <int> idxs;

        for (int i=0; i<n; ++i) {
            if (idxs.upper_bound(a[i].pos)==idxs.end()) sol[a[i].pos-1] = -1;
                else sol[a[i].pos-1] = *idxs.upper_bound(a[i].pos);
            idxs.insert(a[i].pos);
        }
        for (int i=0; i<n; ++i) printf("%d ", sol[i]);
        printf("\n");
    }
    return 0;
}
