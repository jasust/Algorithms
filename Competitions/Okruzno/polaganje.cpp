#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long lld;

int brp, brn, br0, n, k, res, mora, pocn, pocp, i, x, a[5005], b[5005];

int main()
{
    scanf("%d%d", &n, &k);
    brp = 0;
    brn = 0;
    br0 = 0;
    res = -1;
    for (i = 0; i<n; i++)
    {
        scanf("%d", &x);
        if (x<0) { b[brn] = x; brn++; }
        else if (x>0) { a[brp] = x; brp++; }
        else br0++;
    }
    if (br0)
    {
        if (k > brn + brp) res = 0;
        if ((brp) && (brn+brp == k) && (brn&1)) res = 0;
        if ((!brp) && (k&1)) res = 0;
        if (res == -1) res = 1;
    }
    if (!br0)
    {
        if ((brp) && (brn+brp == k) && (brn&1)) res = -1;
        else if ((!brp) && (k&1)) res = -1;
        else res = 1;
    }

    if (res == 0)
    {
        printf("0 ");
        k--;
        for (i = 0; i<brp && k; i++, k--) printf("%d ", a[i]);
        for (i = 0; i<brn && k; i++, k--) printf("%d ", b[i]);
        while (k) { printf("0 "); k--; }
        return 0;
    }
    sort(a, a+brp);
    sort(b, b+brn);
    if (res == 1)
    {
        mora = k - brp;
        if (mora<0) mora = 0;
        if (mora&1) mora++;
        for (i = 0; i<mora; i++) printf("%d ", b[i]);
        k -= mora;
        pocn = mora;
        pocp = brp - 1;
        if (k&1) { printf("%d ", a[pocp]); pocp--; k--; }
        while (k)
        {
            if ((pocp>0) && ((pocn+1>brn-1) || (lld(a[pocp]*a[pocp-1])>=lld(b[pocn]*b[pocn+1]))))
            {
                printf("%d %d ", a[pocp], a[pocp-1]);
                pocp -= 2;
                k -= 2;
            }
            else if ((pocn<brn-1) && ((pocp<1) || (lld(a[pocp]*a[pocp-1])<lld(b[pocn]*b[pocn+1]))))
            {
                printf("%d %d ", b[pocn], b[pocn+1]);
                pocn += 2;
                k -= 2;
            }
        }
        return 0;
    }
    if (res == -1)
    {
        if (brp)
        {
            for(i=0; i<brp - 1; i++) printf("%d ", a[i]);
            for(i=0; i<brn - 1; i++) printf("%d ", b[i]);
        }
        else
        {
            for (i=brn-1; i>=brn-k; i--) printf("%d ", b[i]);
        }
        return 0;
    }
    return 0;
}
