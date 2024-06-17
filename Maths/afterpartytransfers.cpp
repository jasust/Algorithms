#include <cstdio>
using namespace std;

struct dp { int bg, last; } dp[1050000];
int t, n, sum, i, j, sol, brb, brc, brj, ib, ic, sumb, sumc, mask, bit, siz, curr, icc, high;
int a[22], idx[22], idy[22], c[22], b[22], jedn[50000];
double avg;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        sum = 0;
        scanf("%d", &n);
        for (i=0; i<n; i++)
        {
            scanf("%d", a+i);
            sum += a[i];
        }
        avg = (double)sum/n;
        brb = brc = 0;
        for (i=0; i<n; i++)
        {
            if ((double)a[i]>avg)
            {
                idx[brb] = i;
                b[brb++] = a[i];
            } else if ((double)a[i]<avg)
            {
                idy[brc] = i;
                c[brc++] = a[i];
            }
        }
        if (!(brb+brc)) { printf("0\n"); continue; }

        mask = (1<<brb) + 1;
        brj = 0;
        siz = 1<<(brb+brc);
        high = 1<<(brb+1);
        for (i=mask; i<siz; i++)
        {
            dp[i].bg = 0;
            dp[i].last = 0;
            if (!(i&((1<<brb)-1))) continue;
            if (high<=i) { brj=0; high <<= 1; } // nisam siguran da ovo radi, bez toga radi sigurno, ovo ga ubrzava
            bit = 1;
            curr = ic = ib = sumb = sumc = 0;
            while (bit<(1<<brb))
            {
                if (bit&i) { sumb += b[curr]; ib++; }
                bit <<= 1;
                curr ++;
            }
            curr = 0;
            while (bit<(1<<(brb+brc)))
            {
                if (bit&i) { sumc += c[curr]; ic++; }
                bit <<= 1;
                curr ++;
            }
            if (n*(sumb+sumc)==sum*(ib+ic))
            {
                for (j=0; j<brj; j++)
                    if ((i&jedn[j])==jedn[j] && (dp[i-jedn[j]].bg+1>dp[i].bg))
                    {
                        dp[i].bg = dp[i^jedn[j]].bg+1;
                        dp[i].last = jedn[j];
                    }
                if (dp[i].bg==0) { jedn[brj++] = i; dp[i].bg = 1; dp[i].last = i;}
            }
        }

        printf("%d\n", brb+brc-dp[siz-1].bg);
        siz -= 1;
        while (dp[siz].last)
        {
            ic = 1<<brb;
            bit = 1<<brb;
            curr = icc = 0;
            while (ic<=dp[siz].last) { ic <<= 1; icc++; }
            ic >>= 1; icc--;
            while (bit<ic)
            {
                if (bit&dp[siz].last) printf("%d -> %d: %.8lf\n", idy[curr], idy[icc], avg-(double)c[curr]);
                bit <<= 1;
                curr++;
            }
            bit = 1;
            curr = 0;
            while (curr<brb)
            {
                if (bit&dp[siz].last) printf("%d -> %d: %.8lf\n", idy[icc], idx[curr], (double)b[curr]-avg);
                bit <<= 1;
                curr++;
            }
            siz = siz - dp[siz].last;
        }
    }
    return 0;
}
