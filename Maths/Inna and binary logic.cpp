/* Codeforces Problem 400E - Inna and binary logic */
#include <cstdio>
using namespace std;
const int maxn = 100005;

int n, m, a[maxn], i, j, bit, p, v, l, r;
long long ans;

int main()
{
	scanf("%d %d", &n, &m);
	for (i=1; i<=n; i++) scanf("%d", a + i);
	for (bit=0; bit<17; bit++)
		for(i=1; i<=n; i++)
			if((a[i]>>bit)&1)
			{
				for (j=i+1; j<=n && (a[j]>>bit)&1; j++);
				ans += ((long long)(j-i)*(j-i+1)>>1) << bit;
				i = j;
			}
	while (m--)
	{
		scanf("%d %d", &p, &v);
		for (bit=0; bit<17; bit++)
			if ((v>>bit&1)^(a[p]>>bit&1))
			{
				for (i=p+1; i<=n && a[i]>>bit&1; i++);
				l = i - p;
				for (i=p-1; i && a[i]>>bit&1; i--);
				r = p - i;
				if (a[p]>>bit&1) ans-= ((long long)l*r) << bit;
				else ans += ((long long)l*r) << bit;
			}
		a[p] = v;
		printf("%I64d\n", ans);
	}
	return 0;
}
