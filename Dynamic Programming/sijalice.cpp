/* Dat je niz d realnih brojeva duzine n<=1000, koji predstavljaju udaljenost nocnih svetiljki od pocetka ulice.Za svaku od
   svetiljki je data i njena potrosnja u jedinici vremena kada je upaljena. Perica se nalazi na udaljenosti start od pocetka
   ulice i zeli da pogasi sve svetiljke u ulici. On se krece brzinom od jednog metra u jedinici vremena. Kolika je minimalna
   potro·snja svetiljki koje one proizvedu - dok ih Perica sve ne pogasi?
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int N,Start,S,A[1005],W[1005],L[1005][1005],D[1005][1005],T[1005][1005];

void qsort(int left, int right)
{
    if (left < right)
    {
        int i = left;
        int j = right;
        int pivot = A[(i+j)/2];
        while (i<=j)
        {
            while (A[i]<pivot) i++;
            while (A[j]>pivot) j--;
            if (i<=j)
            {
                swap(A[i], A[j]);
                swap(W[i], W[j]);
                i++;
                j--;
            }
        }
        qsort(left,j);
        qsort(i,right);
    }
}

int main ( )
{
    scanf("%d%d",&N,&Start);
    for (int i=1; i<=N; i++)
    {
        scanf("%d%d",&A[i],&W[i]);
        A[i]-=Start;
    }
    A[N + 1] = 0;
    W[N + 1] = 0;

    qsort(1, N + 1);

    for (int i=1; i<=N; i++)
        for (int j=i; j<=N; j++)
            T[i][j] = T[i][j-1] + W[j];

    S = T[1][N];
    for (int i=1; i<=N; i++)
        for (int j=i; j<=N; j++)
           T[i][j] = S - T[i][j];

    for (int i=N-1; i>0; i--)
        for (int j=N; j>i; j--)
            L[i][j] = min(L[i + 1][j] + T[i + 1][j]*(A[i + 1] - A[i]),D[i + 1][j] + T[i + 1][j]*(A[j] - A[i]));

    for (int i=1; i<=N; i++)
        for (int j=i+1; j<=N; j++)
            D[i][j] = min(D[i][j - 1] + T[i][j - 1]*(A[j] - A[j - 1]),L[i][j - 1] + T[i][j - 1]*(A[j] - A[i]));

    printf("%d",min(L[1][N],D[1][N]));

    return 0;
}
