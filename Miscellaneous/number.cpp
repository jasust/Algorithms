/* Codeforces Problem 387C - George and Number */
#include <cstdio>
#include <cstring>
using namespace std;

char broj[100005];
int ans, j, n;

int main()
{
    scanf("%s", broj);
    n = strlen(broj);
    for (int  i=n; i; i=j-1)
    {
        for (j=i; broj[j]=='0'; j--);
        if (i-j+1>j || (i-j+1==j && broj[0]<broj[j])) break;
        else ans++;
    }
    printf("%d\n", ans);
    return 0;
}
