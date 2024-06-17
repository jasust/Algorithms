/*                             Codeforces Problem 383D Antimatter
  Zadat je niz od n<=1000 masina koji mogu da proizvode ili materiju ili antimateriju, Suma(a[i])<=10^4. Odrediti broj razlicitih
  podnizova uzastopnih clanova tako da je kolicina materije i antimaterije na njima ista.
  Napomena: dva podniza su razlicita ako postoji bar jedna masina koja proizvodi materiju u prvom, a antimateriju u drugom.
*/
#include<cstdio>
using namespace std;
#define Mod 1000000007
int n, a, D[1010][20010], sol;
int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
    {
		scanf("%d", &a);
		for (int j = 0; j <= 20000; j++)
		{
			if (!D[i-1][j]) continue;
			if (j-a) D[i][j-a] = (D[i][j-a] + D[i-1][j]) % Mod;
			D[i][j+a] = (D[i][j+a] + D[i-1][j]) % Mod;
		}
		D[i][10000 - a]++;
		D[i][10000 + a]++;
		sol = (sol + D[i][10000]) % Mod;
	}
	printf("%d\n", sol);
}
