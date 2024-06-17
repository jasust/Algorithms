#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 3;


int T;
ll A, N, M, b;

void mulmatrix(ll A[2][2], ll B[2][2]) // A <= A*B
{
	ll x = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % M;
	ll y = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % M;
	ll z = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % M;
	ll w = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % M;

	A[0][0] = x;
	A[0][1] = y;
	A[1][0] = z;
	A[1][1] = w;
}

void powermat(ll F[2][2], ll x) // F <= F^x
{
	if (x <= 1)
		return;
	ll Q1[2][2] = { { b + 1, 1 },{ (-b)%M + M, 0 } };
	powermat(F, x / 2);
	mulmatrix(F, F);

	if (x & 1)
		mulmatrix(F, Q1);
}

int main()
{
	cin >> T;
	while (T--)
	{
		scanf("%I64d%I64d%I64d", &A, &N, &M);
		if (A == 0)
			cout << 0 << endl;
		else
		{
			ll B = A;
			b = 1;
			while (B)
			{
				B /= 10;
				b *= 10;
			}

			ll Q[2][2] = { { b + 1, 1 },{ (-b)%M + M, 0 } };
			powermat(Q, N - 2);
			ll D[2][2] = { { (A*b + A)%M, A }, { 0, 0 } };

			if (N == 1)
				cout << A%M << endl;
			else if (N == 2)
				cout << (A*b + A) % M;
			else
			{
				mulmatrix(D, Q);
				if (D[0][0] < 0)
					D[0][0] += M;
				cout << D[0][0] << endl;
			}
		}
	}
	return 0;
}
