/* Codeforces round 497B Tennis Game
Za zadati raspored osvojenih n<=10^5 poena u tenisu ispisati broj nacina kao i sve moguce raspodele broja osvojenih poena
potrebnih za dobijanje jednog seta i broja potrebnih setova za osvajanje meca.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int n, x, cnt, dp1[100005], dp2[100005], pos1[100005], pos2[100005];
pair<int,int> sol[100005];

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &x);
        dp1[i] = dp1[i - 1];
        dp2[i] = dp2[i - 1];
        if (x == 1) { dp1[i]++; pos1[dp1[i]]=i; }
        else { dp2[i]++; pos2[dp2[i]]=i; }
    }
    bool pobednik1 = !(x-1);
    for (int i=1; i<=n; i++)
    {
        int j=1, win1=0, win2=0;
        while (j <= n)
        {
            int pom1=n+1, pom2=n+1;
            if (dp1[j-1] + i <= dp1[n]) pom1 = pos1[dp1[j-1] + i];
            if (dp2[j-1] + i <= dp2[n]) pom2 = pos2[dp2[j-1] + i];
            if (pom1<pom2) win1++; else win2++;
            j = min(pom1, pom2) + 1;
        }
        if (j==n+1 && ((win1>win2 && pobednik1) || (win1<win2 && !pobednik1))) sol[++cnt] = pair<int,int>(max(win1,win2),i);
    }
    sort(sol + 1, sol + cnt + 1);
    printf("%d\n", cnt);
    for (int i=1; i<=cnt; i++) printf("%d %d\n", sol[i].first, sol[i].second);
    return 0;
}
