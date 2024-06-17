#include <cstdio>
using namespace std;

int n, k, x, y, sumx, sumy, i, j, l, nemoguce, sol1, sol2;
int dpx[1000006], dpy[1000006];
char ch[1000006];

int main()
{
    scanf("%d %d %d %d", &n, &k, &x, &y);
    scanf("%s", ch);
    for (i=1; i<=n; i++)
    {
        if (ch[i-1] == 'U') { dpy[i] = dpy[i-1]+1; dpx[i] = dpx[i-1]; }
        if (ch[i-1] == 'D') { dpy[i] = dpy[i-1]-1; dpx[i] = dpx[i-1]; }
        if (ch[i-1] == 'L') { dpy[i] = dpy[i-1]; dpx[i] = dpx[i-1]-1; }
        if (ch[i-1] == 'R') { dpy[i] = dpy[i-1]; dpx[i] = dpx[i-1]+1; }
    }
    if (n>10000) { printf("-1"); return 0;}
    sol1 = 0; sol2 = n+1;
    for (i=1; i<=n; i++)
     for (j=1; j<=i; j++)
     {
         nemoguce = 0;
         sumy =  dpy[i] - dpy[j-1];
         sumx =  dpx[i] - dpx[j-1];
         if ((dpx[n] - sumx == x) && (dpy[n] - sumy == y))
         {
             for (l=1; l<j; l++) if (dpy[l]>k || dpy[l]<-k || dpx[l]>k || dpy[l]<-k) nemoguce = 1;
             for (l=i+1; l<=n; l++) if (dpy[l]-sumy>k || dpy[l]-sumy<-k || dpx[l]-sumx>k || dpy[l]-sumx<-k) nemoguce = 1;
             if (!nemoguce && (i-j+1)<(sol2-sol1+1)) { sol2 = i; sol1 = j; }
         }
     }
     if (sol1 == 0) printf("-1");
     else printf("%d %d", sol1, sol2);

    return 0;
}
