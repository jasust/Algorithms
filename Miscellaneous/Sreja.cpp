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

const int maxn=100005;
int n, a[maxn], b[maxn], br = 1, br2, br1;

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", a + i);
    sort (a,a+n);
    for (int i=1; i<n; i++)
    {
        if (a[i] != a[i-1]) { br++; br2 = 0; }
        if (a[i] == a[i-1]) br2++;
        if (a[i] == a[i-1] & br2==1) br1++;
    }
    if (br2) br1--;
    printf("%d\n", br+br1);
    printf("%d ", a[0]);
    br2=0;
    for (int i=1; i<n; i++)
    {
        if (a[i] != a[i-1]) printf("%d ", a[i]);
    }
    for (int i=n-1; i>=0; i--)
    {
        if (a[i] == a[i-1] & !br) { br++; printf("%d ", a[i]); }
        else if (a[i] != a[i-1]) br = 0;
    }
    return 0;
}
