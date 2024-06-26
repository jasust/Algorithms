/* Codeforces Problem 387E - George and Cards */
#include <cstdio>
#include <set>
using namespace std;
const int maxn = 1000006;

int bit[maxn], pos[maxn], n, k, x;
long long ans;
bool chek[maxn];
set<int> s;

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &x);
		pos[x] = i;
	}
	for(int i=1; i<=k; i++)
	{
		scanf("%d", &x);
		chek[x] = true;
	}

	s.insert(0);
	s.insert(n+1);
	for(int i=1; i<=n; i++)
     if (chek[i]) s.insert(pos[i]);
	 else
	 {
        int left = *--s.lower_bound(pos[i]);
		int right = *s.upper_bound(pos[i]);
		ans += right - left - 1;
		for(int j=right-1; j; j^=j&-j) ans -= bit[j];
		for(int j=left; j; j^=j&-j) ans += bit[j];
		for(int j=pos[i]; j<=n; j+=j&-j) bit[j]++;
     }

	printf("%I64d\n",ans);
	return 0;
}
