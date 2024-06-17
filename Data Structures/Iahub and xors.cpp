/*           Codeforces - problem 341D Iahub and Xors
Data je kvadratna matrica n<=1000 ispunjena 0 i dato je m<=10^5 upita dva tipa:
1 x1 y1 x2 y2 - ispisati xor svih elemenata podmatrice ogranicene elementima x1 y1 x2 y2
2 x1 y1 x2 y2 v - promeni sve elemente podmatrice x1 y1 x2 y2 na a[i,j] xor v
*/
#include<cstdio>
using namespace std;

const int maxn=1010;
int n, m, upit, x1, y1, x2, y2, z[2][2][maxn][maxn];

void update(int x,int y,long long v)
{
	for (int i=x; i<=n; i+=i&-i)
		for (int j=y; j<=n; j+=j&-j)
			z[x&1][y&1][i][j]^=v;
}

long long query(int x,int y)
{
	long long ans=0;
	for (int i=x; i; i-=i&-i)
		for (int j=y; j; j-=j&-j)
			ans^=z[x&1][y&1][i][j];
	return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
	while (m--)
	{
		scanf("%d %d %d %d %d", &upit, &x1, &y1, &x2, &y2);
		if (upit==1) printf("%I64d\n",query(x1-1,y1-1)^query(x2,y1-1)^query(x1-1,y2)^query(x2,y2));
		else
		{
			long long v;
			scanf("%I64d",&v);
			update(x1,y1,v);
			update(x2+1,y1,v);
			update(x1,y2+1,v);
			update(x2+1,y2+1,v);
		}
	}
	return 0;
}
