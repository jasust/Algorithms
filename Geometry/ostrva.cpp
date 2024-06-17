/*
  Dato je n tacaka u koordinatnom sistemu (nikoje 3 nisu kolinearne). Nisu poznate njihove koordinate,
  ali je za svaki par (i,j) poznato koliko ima tacaka u poluravni sa desne strane prave (i,j). Odgovoriti
  na svaki od Q upita oblika (a, i, j) - da li je tacka a u desnoj poluravni od prave (i, j).
*/

#include <cstdlib>
#include <cstdio>
using namespace std;
const int MaxN = 210;

int n, k, a[MaxN][MaxN];
bool sol[MaxN][MaxN][MaxN], mark[MaxN];

int main()
{
	/*
	  freopen("ostrva.in", "r", stdin);
      freopen("ostrva.out", "w", stdout);
    */
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);

	for (int broj = 1; broj <= n - 2; broj++)
	{
		// nalazenje tacke na konveksnom omotacu
		int x = 0;
		for (int i = 1; i < n; i++)
		{
			if (mark[i]) continue;
			for (int j = i + 1; j <= n; j++)
				if (!mark[j] && a[i][j] == 0)
				{
					x = i;
					break;
				}
			if (x != 0) break;
		}
		mark[x] = true;

		// racunanje odgovora na sve upite koji sadrze tacku x (i,j,x)
		// i izbacivanje tacke x (updateovanje matrice a)
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++)
				if (!mark[i] && !mark[j])
				{
					bool b = (a[x][i] > a[x][j]);
					sol[x][i][j] = sol[i][j][x] = sol[j][x][i] = b;
					sol[x][j][i] = sol[j][i][x] = sol[i][x][j] = !b;
					if (b) a[i][j]--; else a[j][i]--;
				}
	}

	scanf("%d", &k);
	for (int i = 1; i <= k; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		printf("%s\n", (sol[a][b][c] ? "DA" : "NE"));
	}
	return 0;
}
