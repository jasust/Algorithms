/* Boni i Klajd pljackaju dve banke u jednoj ulici. Da ne bi bili uhvaceni oni pljackaju banke koje su na minimalnoj razdaljini d.
   Odretiti maksimalnu kolicinu novca koju mogu da pokupe Boni i Klajd, gde je:
   a[i] - udaljenost i-te banke od pocetka ulice
   w[i] - kolicina novca u i-toj banci
  */
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;

int n, d, a[maxn], dp[maxn], w[maxn];

int main()
{
    scanf("%d %d", &n, &d);

    for (int i=0; i<n; i++) scanf("%d", a + i);
    for (int i=0; i<n; i++) scanf("%d", w + i);
    //dp[i] - maksimalna kolicina novca u nekoj banci izmedju i-te i n-te banke ukljucujuci
    for (int i=n-1; i>=0; i--) dp[i] = max(dp[i+1], w[i]);

    int l = 0, r = 0, sol = 0;
    while (r < n)
    {
        r++;
        while (a[r]-a[l]>=d)
        {
            if (w[l] + dp[r] > sol) sol = w[l] + dp[r];
            l++;
        }
    }

    printf("%d", sol);
    return 0;
}
