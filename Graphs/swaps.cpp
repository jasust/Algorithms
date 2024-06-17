// Codeforces Problem 441D - Valera and Swaps
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

const int MaxN = 3003;
int n, m, k, i, j, p[MaxN];
bool used[MaxN];

int main()
{
	scanf("%d", &n);
    for (i=0; i<n; i++)
    {
		scanf("%d", p+i);
		p[i]--;
	}
	scanf("%d", &m);
	m = n - m;

	for (i=0; i<n; i++)
		if (!used[i])
        {
			k++;
			for (j=i; !used[j]; j=p[j]) used[j] = true;
		}
    for (i=0; i<n; i++) used[i] = false;

	printf("%d\n", (int)abs(k-m));
	if (k>m)
    {
		for (i=0; !used[i]; i=p[i]) used[i] = true;
		for (i=1; i<n && k>m; i++)
        {
			if (!used[i])
			{
				printf("%d %d ", 1, i+1);
				k--;
				for (j=i; !used[j]; j=p[j]) used[j] = true;
			}
		}
	}
	if (k<m)
    {
		for (i=0; i<n && k<m; i++)
		{
			vector <int> pos(n, -1);

			int cur = 0;
			for (j=p[i]; j!=i; j=p[j]) pos[j] = cur++;
			pos[i] = cur;

			cur = 0;
			for (j=i+1; j<n && k<m; j++)
				if (pos[j] >= cur)
                {
					printf("%d %d ", i+1, j+1);
					k++;
					cur = pos[j]+1;
					swap(p[i], p[j]);
				}
		}
	}
	return 0;
}
