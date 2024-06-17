//Tangenta 73/1 - 2.Histogram
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector < int > red;
int n, a[10000007];

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", a + i);

    int l=0, r=0, sol = 1, br=0;
    red.push_back(a[0]);
    while (r < n)
    {
        if (r-l+1<=red[br])
        {
            if (sol < r-l+1) sol = r-l+1;
            r++;
            while ((red.back() > a[r]) && (red.size() - br>0)) red.pop_back();
            red.push_back(a[r]);
        }
        else
        {
            if (a[l] == red[br]) br++;
            l++;
        }
    }

    printf("%d", sol);
    return 0;
}

