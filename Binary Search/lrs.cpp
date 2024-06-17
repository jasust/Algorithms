/* longest rising subsequence
   slozenost nlogn
*/
#include <cstdio>
#include <vector>
using namespace std;

int n, a[100005];
vector <int> stek;

int lower(int _x)
{
    int l=0, r=stek.size()-1, mid;
    while (l<=r)
    {
        mid = (l+r)>>1;
        if (stek[mid]<_x) l=mid+1; else r=mid-1;
    }
    return l;
}

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", a+i);

    stek.push_back(a[0]);
    for (int i=1; i<n; i++)
        if (a[i]>stek.back()) stek.push_back(a[i]);
            else stek[lower(a[i])]=a[i];

    printf("%d", stek.size());
    return 0;
}
