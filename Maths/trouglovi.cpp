#include <cstdio>
using namespace std;

int N, A, B, L, R, Mid;
double a, b, c, ro, ru, s, sol1, sol2, mid1, mid2;

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; i++)
    {
		scanf("%lf%lf", &a, &b);
		A = 10000*a;
		B = 10000*b;
		L = A>B ? A-B : B-A;
		R = A + B;

		while (L<R)
        {
            Mid = (L+R)>>1;
            mid1 = (double)Mid/10000;
            mid2 = (double)(Mid+1)/10000;

			s = (a + b + mid1) / 2;
			ru = (s - a)*(s - b)*(s - mid1) / s;
			ro = a*a*b*b*mid1*mid1 / (16 * s*(s - a)*(s - b)*(s - mid1));
			sol1 = ro - ru;

			s = (a + b + mid2) / 2;
			ru = (s - a)*(s - b)*(s - mid2) / s;
			ro = a*a*b*b*mid2*mid2 / (16 * s*(s - a)*(s - b)*(s - mid2));
			sol2 = ro - ru;

			if (sol1 == sol2) { printf("ambiguous\n"); break; }
			if (sol1 < sol2) R = Mid; else L = Mid+1;
		}
		if (L==R) printf("%.4lf\n", (double)L/10000);
	}
	return 0;
}
