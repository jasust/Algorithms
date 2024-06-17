#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, d[1003][2], i, j, sol = 0, br = 0;
char x;

int main()
{
    scanf("%d%d", &n, &m);
    for (i=0; i<n; i++)
    {
        scanf("%c", &x);
        d[i][0] = m;
        d[i][1] = -1;
        for (j=0; j<m; j++)
        {
            scanf("%c", &x);
            if (x=='J') d[i][0] = min(d[i][0], j), d[i][1] = max(d[i][1], j);
        }
    }

    int pos = 0;
    for (i=n-1; i; i--)
        if ((n-i)&1 && max(d[i][1],d[i-1][1])>-1)
        {
            sol+= abs(max(d[i][1],d[i-1][1]) - pos);
            pos = max(d[i][1],d[i-1][1]);
            br = n-i-1;
        } else
        if (!((n-i)&1) && min(d[i][0],d[i-1][0])<m)
        {
            sol+= abs(pos - min(d[i][0],d[i-1][0]));
            pos = min(d[i][0],d[i-1][0]);
            br = n-i-1;
        }
    if (n&1 && d[0][1]>-1) sol+= abs(d[0][1] - pos), br = n-1;
        else if (!(n&1) && d[0][0]<m) sol += abs(pos - d[0][0]), br = n-1;

    printf("%d", sol+br);

    return 0;
}
