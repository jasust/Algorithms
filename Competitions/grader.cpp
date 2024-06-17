#include <stdlib.h>
#include <stdio.h>

#include "upiti.h"

static int N, Q;
static int t, x, y;

int main()
{
	scanf("%d%d", &N, &Q);

	Init(N);

	for (int i = 1; i <= Q; i++)
	{
		scanf("%d%d%d", &t, &x, &y);
		if (t == 1) // upit AddValue
		{
			AddValue(x, y);
		}
		else // upit CalculateSum
		{
			printf("%lld\n", CalculateSum(x, y));  // promeniti specifikator u %I64d ako je potrebno
		}
	}

	return 0;
}