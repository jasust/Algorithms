/* Z-trening problem z-orasi */
#include <cstdio>
using namespace std;

const int mod = 8192;
int n, m, x, a[30][30], niz[30];

void mnozi(int mat[30][30])
{
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            for (int l=0; l<n; l++) a[i][j]=(a[i][j] + (a[i][l] * mat[l][j]) % mod ) % mod;
}

void kvadriraj ()
{
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            for (int l=0; l<n; l++) a[i][j]=(a[i][j] + (a[i][l] * a[l][j]) % mod ) % mod;
}

void stepen (int ar[30][30], int k)
{
    if (k > 1)
    {
        stepen( ar, k/2 );
        kvadriraj();
        if (k & 1) mnozi( ar );
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &x);
        a[x-1][0]++;
    }
    for (int i=1; i<n; i++) a[i-1][i] = 1;
    niz[0] = 1;
    stepen( a, m);

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) niz[i]= (niz[i] + (niz[j]*a[j][0]) % mod) % mod;

    printf("%d", niz[0]);
}
