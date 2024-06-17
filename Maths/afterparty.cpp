#include <cstdio>
using namespace std;

bool uslov, inPerm[11];
int t, n, sum, i, sol, brb, brc, brgrupa, ib, ic, lastb, lastc, sumb, sumc;
int a[22], solidx[11], curridx[11], idx[22], idy[22], currPerm[11], solperm[11], c[22], b[22];
double avg;

void perm(int pos)
{
    if (pos == (uslov?brc:brb))
    {
        brgrupa = 1;
        sumb = 0;
        ib = 0;
        ic = 1;
        sumc = uslov?currPerm[0]:c[0];
        while (ib<brb || ic<brc)
        {
            if (n*(sumb+sumc)>sum*(ib+ic)) sumc += uslov?currPerm[ic++]:c[ic++];
            else if (n*(sumb+sumc)<sum*(ib+ic)) sumb += uslov?b[ib++]:currPerm[ib++];
            else
            {
                brgrupa++;
                if (ib<brb) sumb += uslov?b[ib++]:currPerm[ib++];
                else if (ic<brc) sumc += uslov?currPerm[ic++]:c[ic++];
            }
        }
        if (brgrupa>sol)
        {
            sol = brgrupa;
            for (int i=0; i<(uslov?brc:brb); i++) solperm[i] = currPerm[i], solidx[i] = curridx[i];
        }
        return;
    }
    for (int i=0; i<(uslov?brc:brb); i++)
    {
        if (!inPerm[i])
        {
            currPerm[pos] = uslov?c[i]:b[i];
            curridx[pos] = uslov?idy[i]:idx[i];
            inPerm[i] = true;
            perm(pos+1);
            inPerm[i] = false;
        }
    }
}

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
        sol = 0;
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
        if (brc>brb) uslov = false; else uslov = true;
        if (!(brb+brc)) { printf("0\n"); continue; }
        perm(0);

        printf("%d\n", brb+brc-sol);
        lastb = lastc = ib = sumb = 0;
        ic = 1;
        sumc = uslov?solperm[0]:c[0];
        while (ib<brb || ic<brc)
        {
            if (n*(sumb+sumc)>(sum*(ib+ic))) sumc += uslov?solperm[ic++]:c[ic++];
            else if (n*(sumb+sumc)<(sum*(ib+ic))) sumb += uslov?b[ib++]:solperm[ib++];
            else
            {
                for (i=lastc; i<ic-1; i++) printf("%d -> %d: %.8lf\n", uslov?solidx[i]:idy[i], uslov?solidx[ic-1]:idy[ic-1], avg-(double)(uslov?solperm[i]:c[i]));
                for (i=lastb; i<ib; i++) printf("%d -> %d: %.8lf\n", uslov?solidx[ic-1]:idy[ic-1], uslov?idx[i]:solidx[i], (double)(uslov?b[i]:solperm[i])-avg);
                lastb = ib;
                lastc = ic;
                if (ib<brb) sumb += uslov?b[ib++]:solperm[ib++];
                else if (ic<brc) sumc += uslov?solperm[ic++]:c[ic++];
            }
        }
        for (i=lastc; i<ic-1; i++) printf("%d -> %d: %.8lf\n", uslov?solidx[i]:idy[i], uslov?solidx[ic-1]:idy[ic-1], avg-(double)(uslov?solperm[i]:c[i]));
        for (i=lastb; i<ib; i++) printf("%d -> %d: %.8lf\n", uslov?solidx[ic-1]:idy[ic-1], uslov?idx[i]:solidx[i], (double)(uslov?b[i]:solperm[i])-avg);
    }
    return 0;
}
