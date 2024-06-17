/*                              Codeforces Problem 367D - Sereja and Sets
Sereja ima m<=20 disjunktnih skupova cija je unija skup sa elementima od 1 do n<=10^5 i jedan broj d<=10^5.
Sereja zeli da izabere neki proj skupova tako da za njihovu sortiranu uniju vazi b[1]<=d; b[i+1]-b[i]<=d(1<=i<|b|); n-d+1<=b[|b|].
Pomozite Sereji da nadje minimalni broj takvih skupova.                                                                         */
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, d, sz, x, a[100005], freq[22];
bool bad[(1<<20)];

void add()
{
    int mask=0;
    for(int i=0; i<m; i++) if(!freq[i]) mask |= (1<<i);
    bad[mask] = true;
}

int main()
{
    scanf("%d %d %d", &n, &m, &d);
    for(int i=0; i<m; i++)
    {
        scanf("%d", &sz);
        for(int j=0; j<sz; j++)
        {
            scanf("%d", &x);
            a[x-1] = i;
        }
    }

    for(int i=0; i<d; i++) freq[a[i]]++;
    add();
    for(int i=d; i<n; i++)
    {
        freq[a[i]]++;
        freq[a[i-d]]--;
        add();
    }

    int ans = m;
    for(int mask=(1<<m)-1; mask; mask--)
    {
        if (!bad[mask])
        {
            int cnt=0;
            for(int i=0; i<m; i++) if (mask&(1<<i)) cnt++;
            ans = min(ans, cnt);
        }
        else for(int i=0; i<m; i++) if (mask&(1<<i)) bad[mask^(1<<i)]=true;
    }
    printf("%d", ans);
    return 0;
}
