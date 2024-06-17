/* 5. За сваког од  n гостију ресторана задат је тренутак уласка у ресторан и тренутак изласка, у току једног дана,
   колико је највише гостију у неком тренутку било и у којим временским интервалима. */
#include<cstdio>
using namespace std;

int n, i, l, r, maxi=0, br=0, time[1000006], tren[1000006];

int main()
{
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        scanf("%d %d", &l, &r);
        time[l]++;
        time[r+1]--;
    }
    for (i=1; i<=1000001; i++)
    {
        time[i]+=time[i-1];
        if (time[i]==maxi) { br++; tren[br]=i; }
        if (time[i]>maxi) { maxi=time[i]; br=1; tren[br]=i; }
    }
    printf("%d\n", maxi);
    for (i=1; i<=br; i++) printf("%d ", tren[i]);
    return 0;
}
