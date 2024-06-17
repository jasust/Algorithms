/*Dat je niz od N<=5000 clanova. U jednom koraku mozemo povecati ili umanjiti bilo koji broj za 1. Koliko je najmanje potrebno
  primeniti podeza da bi niz postao ne opadajuci. Vremensko ogranicenja 1s. */
#include<stdio.h>
#include<algorithm>
#include<cmath>

#define MAXINT 5000
using namespace std;

int main()
{
	int n, i, j;
	int a[MAXINT+5], b[MAXINT+5];
	long long dp[MAXINT+5];

	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	for(i=1; i<=n; i++) dp[i]=0;

	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
		{
			dp[j]+=abs(a[i]-b[j]);
			if (j>1) dp[j]=min(dp[j-1],dp[j]);
		}
    printf("%I64d\n",dp[n]);

    return 0;
}
