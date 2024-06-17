#include <cstdio>
#include <algorithm>
using namespace std;

struct pos
{
    int x,y,p;
    inline bool operator < (const pos &a) const
    {
        if (x!=a.x)
            return x<a.x;
        if (y!=a.y)
            return y<a.y;
        return p<a.p;
    }
    inline bool operator == (const pos &a) const
    {
        return (x==a.x && y==a.y && p==a.p);
    }
};
pos beg[1000006];
pos fin[1000006];
int begn, finn, n, k, tx, ty, cx, cy, dp, dk, dl;;
char base[1000006];

int main()
{
    scanf("%d%d%d%d", &n, &k, &tx, &ty);
    scanf("%s", base+1);
    begn = 1;
    for (int i=1; i<=n; i++)
    {
        if (base[i]=='U') cy++;
        if (base[i]=='D') cy--;
        if (base[i]=='L') cx--;
        if (base[i]=='R') cx++;
        if (cx<=k && cx>=-k && cy<=k && cy>=-k)
        {
            begn++;
            beg[begn].x=cx;
            beg[begn].y=cy;
            beg[begn].p=i;
        }
        else break;
    }
    cx=tx;
    cy=ty;
    fin[1].x=cx;
    fin[1].y=cy;
    fin[1].p=n+1;
    finn=1;
    for (int i=n; i>=1; i--)
    {
        if (base[i]=='U') cy--;
        if (base[i]=='D') cy++;
        if (base[i]=='L') cx++;
        if (base[i]=='R') cx--;
        if (cx<=k && cx>=-k && cy<=k && cy>=-k)
        {
            finn++;
            fin[finn].x=cx;
            fin[finn].y=cy;
            fin[finn].p=i;
        }
        else break;
    }
    sort(beg+1, beg+1+begn);
    sort(fin+1, fin+1+finn);

    int tar = 1;
    dl = 10 * n;
    for (int i=1; i<=begn; i++)
    {
        while ((fin[tar]<beg[i] || fin[tar]==beg[i]) && tar<finn)
            tar++;
        if (beg[i].x==fin[tar].x && beg[i].y==fin[tar].y)
        {
            if (fin[tar].p-beg[i].p<dl)
            {
                dp=beg[i].p+1;
                dk=fin[tar].p-1;
                dl=fin[tar].p-beg[i].p;
            }
        }
    }
    if (dl==10*n)
        printf("-1\n");
    else
        printf("%d %d\n",dp,dk);
    return 0;
}
