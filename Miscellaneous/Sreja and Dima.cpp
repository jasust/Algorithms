#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
using namespace std;

const int maxn=1005;
int n, a[maxn], s1 = 0, s2 = 0, l, r;
bool k;

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", a + i);
    l=0; r=n-1; k=true;

    while (l<=r)
    {
        if (a[l]>a[r])
        {
            if (k) s1 += a[l]; else s2 += a[l];
            l++;
        }
        else
        {
            if (k) s1 += a[r]; else s2 += a[r];
            r--;
        }
        k = !k;
    }
    printf("%d %d", s1, s2);

    return 0;
}
