//Z-training - z-paradajz
#include <cstdio>
#include <vector>
using namespace std;

vector < int > red;
int n, a[200005], rok;

int main()
{
    scanf("%d %d", &n, &rok);
    for (int i=0; i<n; i++) scanf("%d", a + i);

    int l=0, r=rok, sol = a[0], br=0;
    red.push_back(a[0]);
    for (int i=1; (i<rok && i<n) ; i++)
    {
        while ((red.back() > a[i]) && (red.size()>0)) red.pop_back();
        red.push_back(a[i]);
        sol += red[0];
    }

    while (r < n)
    {
        if (red[br] == a[l]) br++;
        l++;
        while ((red.back() > a[r]) && (red.size() - br>0)) red.pop_back();
        red.push_back(a[r]);
        sol += red[br];
        r++;
    }

    printf("%d", sol);
    return 0;
}
