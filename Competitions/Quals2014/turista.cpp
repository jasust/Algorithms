#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, i, l, r, br, maxx, sol, tmp;
long long a[1000006];
char ch[11];

int main()
{
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        scanf("%s", ch);
        l=0;
        r=strlen(ch)-1;
        while (l<r)
        {
            ch[l]-=64; ch[r]-=64;
            if (ch[l]>32) ch[l]-=32;
            if (ch[r]>32) ch[r]-=32;
            if (ch[l]!=ch[r]) break;
            l++;
            r--;
        }
        if (l==r) { ch[l]-=64; if (ch[l]>32) ch[l]-=32; }
        if (l>=r)
        {
            br++;
            for (int j=0; j<10; j++) a[br]=(a[br]*27)+ch[j];
        }
        for (int j=0; j<10; j++) ch[j] = 0;
    }
    sort(a+1, a+br+1);
    maxx = 1;
    sol = 1;
    tmp = 1;
    for (i=2; i<=br; i++)
    {
        if (a[i]==a[i-1])
        {
            tmp++;
            if (tmp>maxx) { maxx = tmp; sol = i; }
        }
        else tmp = 1;
    }
    br = 27;
    for (i=0; i<10; i++)
    {
        ch[9-i] = (a[sol] % br);
        if (ch[9-i]) ch[9-i]+=96;
        a[sol] = a[sol] / br;
    }
    printf("%s", ch);
    return 0;
}
