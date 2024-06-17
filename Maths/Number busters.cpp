//Codeforces - Problem 382B Number busters
#include <cstdio>
#include <cmath>
using namespace std;
long long a, b, w, x, c;

int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d", &a, &b, &w, &x, &c);
	long long dif = c - a;
	if (dif <= 0) printf("0\n");
	else
	{
		double k = double(dif * x - b) / (w - x);
		long long result = dif + ceil(k);
		printf("%I64d\n",result);
	}
	return 0;
}
