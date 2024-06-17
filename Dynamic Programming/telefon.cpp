#include <stdio.h>
int main()
{
    int dp_1[10], dp_2[10], brojac, brojac2, n, zbir;
    scanf("%d", &n);
    for (brojac = 0; brojac <= 9; dp_1[brojac] = 1, brojac++);
    for (brojac = 2; brojac <= n; brojac++)
    {
        dp_2[0] = dp_1[4] + dp_1[6];
        dp_2[1] = dp_1[6] + dp_1[8];
        dp_2[2] = dp_1[7] + dp_1[9];
        dp_2[3] = dp_1[4] + dp_1[8];
        dp_2[4] = dp_1[3] + dp_1[9] + dp_1[0];
        dp_2[5] = 0;
        dp_2[6] = dp_1[1] + dp_1[7] + dp_1[0];
        dp_2[7] = dp_1[2] + dp_1[6];
        dp_2[8] = dp_1[1] + dp_1[3];
        dp_2[9] = dp_1[2] + dp_1[4];
        for( brojac2=0; brojac2 <= 9; dp_1[brojac2] = dp_2[brojac2], brojac2++ );
    }
    for (brojac = 1, zbir = 0; brojac <= 7; brojac++, zbir += dp_1[brojac]);
    zbir += dp_1[9];
    printf("Broj razlicitih brojeva telefona za sahiste duzine %d je: %d.\n",n,zbir);
}
