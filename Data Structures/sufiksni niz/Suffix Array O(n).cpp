#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)

const int MAX = 250052;
char str[MAX];
int c[MAX];

inline bool leq(int a1, int a2, int b1, int b2)
{ return(a1 < b1 || (a1 == b1 && a2 <= b2)); }

inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3)
{ return(a1 < b1 || (a1 == b1 && leq(a2,a3, b2,b3))); }

static void radixPass(int* a, int* b, int* r, int n, int K)
{
        int i, sum, t;
        for(i = 0;  i <= K;  i++) c[i] = 0;
        for(i = 0;  i < n;  i++) c[r[a[i]]]++;
        for(i = 0, sum = 0;  i <= K;  i++) {
                t = c[i];
                c[i] = sum;
                sum += t;
        }
        for(i = 0;  i < n;  i++) b[c[r[a[i]]]++] = a[i];
}

void suffixArray(int* s, int* SA, int n, int K) {
        int n0 = (n+2)/3, n1 = (n+1)/3, n2 = n/3, n02 = n0+n2;
        int* s12 = new int[n02 + 3];
        int* SA12 = new int[n02 + 3];
        int* s0 = new int[n0];
        int* SA0 = new int[n0];
        int i, j, name, c0, c1, c2, p, t, k;
        s12[n02] = s12[n02+1] = s12[n02+2] = 0;
        SA12[n02] = SA12[n02+1] = SA12[n02+2] = 0;
        for(i=0, j=0; i < n+(n0-n1); i++) if(i%3 != 0) s12[j++] = i;
        radixPass(s12, SA12, s+2, n02, K);
        radixPass(SA12, s12, s+1, n02, K);
        radixPass(s12, SA12, s, n02, K);
        name = 0, c0 = -1, c1 = -1, c2 = -1;
        for(i = 0; i < n02; i++) {
                if(s[SA12[i]] != c0 || s[SA12[i]+1] != c1 || s[SA12[i]+2] != c2) {
                        name++;
                        c0 = s[SA12[i]];
                        c1 = s[SA12[i]+1];
                        c2 = s[SA12[i]+2];
                }
                if(SA12[i] % 3 == 1) s12[SA12[i]/3] = name;
                else s12[SA12[i]/3 + n0] = name;
        }
        if(name < n02) {
                suffixArray(s12, SA12, n02, name);
                for(i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
        }
        else for(i = 0; i < n02; i++) SA12[s12[i] - 1] = i;
        for(i=0, j=0; i < n02; i++) if(SA12[i] < n0) s0[j++] = 3*SA12[i];
        radixPass(s0, SA0, s, n0, K);
        for(p=0, t=n0-n1, k=0; k < n; k++) {
                i = GetI();
                j = SA0[p];
                if(SA12[t] < n0 ? leq(s[i], s12[SA12[t] + n0], s[j], s12[j/3]) : leq(s[i], s[i+1], s12[SA12[t]-n0+1], s[j], s[j+1], s12[j/3+n0])) {
                        SA[k] = i; t++;
                        if(t == n02) for(k++; p < n0; p++, k++) SA[k] = SA0[p];
                }
                else {
                        SA[k] = j; p++;
                        if(p == n0) for(k++; t < n02; t++, k++) SA[k] = GetI();
                }
        }
        delete[] s12; delete[] SA12; delete[] SA0; delete[] s0;
}
int s[MAX], SA[MAX];
int main()
{
        int n, m, i;
        gets(str);
        m = -1;
        for(i = 0; str[i]; i++) {
                s[i] = str[i];
                m = m > str[i]? m : str[i];
        }
        n = i;
        for(i = n; i < n+3; i++) SA[i] = s[i] = 0;
        suffixArray(s, SA, n, m);
        for(i = 0; i < n; i++) printf("%d\n", SA[i]);
        return 0;
}
