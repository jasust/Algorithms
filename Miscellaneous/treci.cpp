/* Telefonska kompanija izdaje sedmocifrene brojeve koji ne pocinju sa 0 ili 8, a nastaju kretanjem skakaca po tabli oblika
123
456
789
 0                                                                                                                       */
#include <cstdio>
using namespace std;

int dp_1[10], dp_2[10], zbir=0;

int main()
{
    for (int i=0; i<=9; i++) dp_1[i]=1;
    for (int i=2; i<=7; i++)
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
        for(int j=0; j<=9; j++) dp_1[j] = dp_2[j];
    }
    for (int i=1; i<=7; i++) zbir += dp_1[i];
    zbir += dp_1[9];
    printf("Broj razlicitih brojeva telefona duzine 7 je %d.\n", zbir);
    return 0;
}
