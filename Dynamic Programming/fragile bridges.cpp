/* Dato je su n<=1e5 stubova koja su u nizu povezani sa n-1 mostova. Svaki most ima svoju osteljivost 1<=a[i]<=1e9 koja govori
koliko puta igrac moze da predje preko njega pre nogo sto se zauvek srusi. Igrac dobija poen svaki put kada predje preko mosta, a
igra se zavsava kada igrac nema vise validnih poteza. Koliko igrac moze najvise poena da skupi ako moze da krene sa bilo kog stuba. */
#include <cstdio>
#include <algorithm>
using namespace std;

int n, i, a[100005];
long long left[100005], right[100005], sumodd[100005];

int odd(int a) { return (a&1)?a:a-1; }
int even(int a) { return (a&1)?a-1:a; }

int main()
{
    scanf("%d", &n);
    sumodd[0]=0; left[0]=0; right[n-1]=0;
    for (i=1; i<n; i++)
    {
        scanf("%d", a+i);
        sumodd[i] = sumodd[i-1]+odd(a[i]);
        if (a[i]==1) left[i]=0; else left[i]=left[i-1]+even(a[i]);
    }
    for (i=n-2; i>=0; i--)
        if (a[i+1]==1) right[i]=0; else right[i]=right[i+1]+even(a[i+1]);

    long long sol = 0, maks = 0;
    for (i=0; i<n; i++)
    {
        maks = max(maks, left[i]-sumodd[i]);
        sol = max(sol, maks+right[i]+sumodd[i]);
    }

    printf("%I64d", sol);
    return 0;
}
