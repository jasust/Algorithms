#include <cstdio>
using namespace std;
const int mod = 1e9+7;

int n, s, br=0;
long long a[102][102], sol[102][102][2];

void step1 (void)
{
    for (int k=0; k<n; k++)
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                sol[i][j][1-br&1] = (sol[i][j][1-br&1]+(sol[i][k][br&1]*sol[k][j][br&1])%mod)%mod;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) sol[i][j][br&1]=0;
}

void step2 (void)
{
    for (int k=0; k<n; k++)
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                sol[i][j][1-br&1] = ((sol[i][j][1-br&1]+a[i][k]*sol[k][j][br&1])%mod)%mod;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) sol[i][j][br&1]=0;
}

void brz_step (int _s)
{
    if (_s==0) return;
    brz_step(_s>>1);
    step1();
    br++;
    if (_s&1) step2(), br++;
}

int main()
{
    scanf("%d%d", &n, &s);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        {
            scanf("%d", &a[i][j]);
            sol[i][j][0] = (i==j);
        }
    brz_step(s);
    for (int i=0; i<n; i++)
        { for (int j=0; j<n; j++) printf("%d ", sol[i][j][br&1]); printf("\n"); }

    return 0;
}
