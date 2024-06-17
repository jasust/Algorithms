//Dat je niz zgrada zadate visine koje treba rasporediti u ne opadajuci niz
//spajanjem susednih zgrada. Koliko najmanje operacija treba izvrsiti
#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=200010;

int n;
long long h[MaxN],g[MaxN],f[MaxN];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		h[i]=x;
	}
	for (int i=1;i<=n;++i)
	{
		int j=i-1,sum=h[i];
		while (g[j]>sum) sum+=h[j--];
		g[i]=sum;
		f[i]=f[j]+i-j-1;
	}
	cout<<f[n]<<endl;
	return 0;
}
