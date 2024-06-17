#include <stdio.h>
#include <algorithm>

int n, i, br = 0;
int x[100005], y[100005];

int upit(int l ,int r)
{
    if ((abs(y[l])>abs(y[r])) or ((abs(y[l])==abs(y[r])) and (abs(x[l])>abs(x[r])))) return 1;
    return 0;
}

void qsort(int left, int right)
{
    if (left < right)
    {
        int p;
        int i = left;
        int j = right;
        int pivot = (i+j)/2;
        while (i<=j)
        {
            while (upit(pivot, i)) i++;
            while (upit(i, pivot)) j--;
            if (i<=j)
            {
                p = y[i], y[i] = y[j], y[j] = p;
                p = x[i], x[i] = x[j], x[j] = p;
                i++;
                j--;
            }
        }
        qsort(left,j);
        qsort(i,right);
    }
}

int main()
{
    scanf("%d", &n);

    for (int i=0; i<n; i++)
    {
        scanf("%d%d", x + i, y + i);
        if ((x[i] == 0) or (y[i] == 0)) br++;
    }
    qsort(0, n - 1);

    printf("%d\n", 6*n - 2*br);
    for (int i=0; i<n; i++)
    {
        if (y[i] == 0)
        {
            if (x[i] < 0) printf("1 %d L\n2\n1 %d R\n3\n", -x[i], -x[i]);
            else printf("1 %d R\n2\n1 %d L\n3\n", x[i], x[i]);
        }
        if (x[i] == 0)
        {
            if (y[i] < 0) printf("1 %d D\n2\n1 %d U\n3\n", -y[i], -y[i]);
            else {printf("1 %d U\n2\n1 %d D\n3\n", y[i], y[i]);}
        }
        if ((y[i] < 0) and (x[i] != 0))
        {
            if (x[i] < 0) printf("1 %d D\n1 %d L\n2\n1 %d R\n1 %d U\n3\n", -y[i], -x[i],-x[i],-y[i]);
            else {printf("1 %d D\n1 %d R\n2\n1 %d L\n1 %d U\n3\n", -y[i], x[i], x[i], -y[i]);}
        }
        if ((y[i] > 0) and (x[i] != 0))
        {
            if (x[i] < 0) printf("1 %d U\n1 %d L\n2\n1 %d R\n1 %d D\n3\n", y[i], -x[i], -x[i], y[i]);
            else {printf("1 %d U\n1 %d R\n2\n1 %d L\n1 %d D\n3\n", y[i], x[i], x[i], y[i]);}
        }
    }

    return 0;
}
