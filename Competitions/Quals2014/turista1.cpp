#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, i, l, r, br, maxx, sol, tmp;
struct lol
{
    long long aaa;
    int idx;
} sve[1000006];
char ch[1000006][11];
bool cmp1(const lol &a, const lol &b) { return a.aaa<b.aaa; }

int main()
{
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        scanf("%s", ch[i]);
        l=0;
        r=strlen(ch[i])-1;
        while (l<r)
        {
            if (ch[i][l]<97) ch[i][l]+=32;
            if (ch[i][r]<97) ch[i][r]+=32;
            if (ch[i][l]!=ch[i][r]) break;
            l++;
            r--;
        }
        if (l==r && ch[i][l]<97) ch[i][l]+=32;
        if (l>=r)
        {
            br++;
            for (int j=0; j<10; j++) sve[br].aaa=(sve[br].aaa*27)+ch[i][j]-96;
            sve[br].idx = i;
        }
    }
    sort(sve+1, sve+br+1, cmp1);
    maxx = 1;
    sol = 1;
    tmp = 1;
    for (i=2; i<=br; i++)
    {
        if (sve[i].aaa==sve[i-1].aaa)
        {
            tmp++;
            if (tmp>maxx) { maxx = tmp; sol = i; }
        }
        else tmp = 1;
    }
    printf("%s", ch[sve[sol].idx]);
    return 0;
}
