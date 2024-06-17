#include <cstdio>
using namespace std;

int n, a[11][7], poc, x, y, maxx, maxy, i;
bool upit;
char ch[1005];

void krljaj()
{
    while (ch[poc]!=0)
    {
        if (ch[poc]=='^' || ch[poc]=='_') upit=!upit;
        else
        {
            if (upit && x>maxx) maxx=x;
            if (upit && y>maxy) maxy=y;
            if (ch[poc]=='U') { y-=2; if (upit) a[y][x]=a[y+1][x]=a[y+2][x]=i; }
            if (ch[poc]=='D') { y+=2; if (upit) a[y][x]=a[y-1][x]=a[y-2][x]=i; }
            if (ch[poc]=='L') { x-=2; if (upit) a[y][x]=a[y][x+1]=a[y][x+2]=i; }
            if (ch[poc]=='R') { x+=2; if (upit) a[y][x]=a[y][x-1]=a[y][x-2]=i; }
            if (upit && x>maxx) maxx=x;
            if (upit && y>maxy) maxy=y;
        }
        ch[poc] = 0;
        poc++;
    }
}

int check()
{
    if (a[maxy][maxx-1]==i && a[maxy-2][maxx-1]!=i) return 0;
    if (a[maxy-4][maxx-1]!=i && a[maxy-2][maxx-1]!=i) return 1;
    if (a[maxy-1][maxx]!=i) return 2;
    if (a[maxy][maxx-1]==i && a[maxy-1][maxx-2]!=i && a[maxy-3][maxx-2]!=i) return 3;
    if (a[maxy-4][maxx-1]!=i && a[maxy-2][maxx-1]==i) return 4;
    if (a[maxy-3][maxx]!=i && a[maxy-1][maxx-2]!=i) return 5;
    if (a[maxy-3][maxx]!=i && a[maxy-1][maxx-2]==i) return 6;
    if (a[maxy-4][maxx-1]==i && a[maxy][maxx-1]!=i) return 7;
    if (a[maxy-1][maxx-2]==i && a[maxy-2][maxx-1]==i && a[maxy-3][maxx-2]==i && a[maxy-3][maxx]==i) return 8;
    if (a[maxy][maxx-1]==i && a[maxy-1][maxx-2]!=i && a[maxy-3][maxx]==i) return 9;
}

int main()
{
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        scanf("%s", ch);
        poc = 0;
        if (ch[poc] == '^')
        {
            while (ch[poc]!='_' || ch[poc+1]=='^') ch[poc]=0, poc++;
            ch[poc]=0; poc++;
        }
        upit=true;
        maxx = x = 2; maxy = y = 4;
        krljaj();
        printf("%d ", check());
    }
    return 0;
}
