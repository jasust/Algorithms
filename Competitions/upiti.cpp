#include "upiti.h"
#include <cstdio>
// Implementirati funkcije Init, AddValue i CalculateSum
// Mozete koristiti dodatne biblioteke, globalne promenljive i druge funkcije
long long int bit[100005];

void Init(int N)
{
	// ako ja budem imao i 5pts na sio bice dobro
	for (int i=0; i<=N; i++) bit[i] = 0;
}

void AddValue(int pos, int val)
{
	// nije ni bitno
	for (int i=pos; i<100001; i+=i&-i) bit[i] += val;
}

long long CalculateSum(int L, int R)
{
    long long ret = 0;
    for (int i=R; i; i-=i&-i) ret += bit[i];
    for (int i=L-1; i; i-=i&-i) ret -= bit[i];
	return ret;
}
