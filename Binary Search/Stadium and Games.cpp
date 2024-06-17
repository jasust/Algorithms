/*                                 Codeforces Problem 325B Stadium and Games
  Igra se igra na sledeci nacin:
  - ako je broj ucesnika m paran, odigra se m/2 utakmica i isto toliko igraca ispadne iz igre, i igra se nastavlja
  - ako je m neparno, odigra se m*(m-1)/2 utakmica i igra se zavrsava
  Za zadati broj utakmica n<=10^18 odrediti sve brojeve igraca m za koje ce biti odigrano tacno n utakmica
*/
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long lld;

int i, ans, f;
lld n, l, r, mid, x;

lld check(lld mid)
{
	if ((mid-1)>>1 > n/mid) return n+1;
	return mid*((1ll<<i)-1)+mid*(mid-1)/2;
}

int main()
{
	scanf("%I64d",&n);
	x=(int)sqrt(n*2);
	if(x*(x+1)==n*2 && (x+1)&1)printf("%I64d\n",x+1),f=1;
	for(i=1; (1ll<<i)-1<=n; i++)
    {
		l=1; r=n/((1ll<<i)-1);
		while(l<=r)
		{
			mid=(l+r)/2;
			if (check(mid)<=n) l=mid+1;
			else r=mid-1;
		}
		if((l-1)&1 && check(l-1)==n) printf("%I64d\n",(l-1)*1<<i),f=1;
	}
	if(!f)printf("-1\n");
	return 0;
}
