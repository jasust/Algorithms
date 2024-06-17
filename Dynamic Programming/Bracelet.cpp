#include <stdio.h>
#include <algorithm>
using namespace std;

int n, capacity;
int Weight[101], Value[101], Sol[1001];

inline int Knapsack01()
{
    for (int i=0;i<=capacity;i++) Sol[i] = 0;
    for (int i=0;i<n;i++)
    {
        for (int j=capacity;j>=1;j--)
        {
            if (Weight[i] <= j)
            {
                int x = Sol[j];
                int y = Sol[j-Weight[i]]+Value[i];
                Sol[j] = max(x,y);
            }
        }
    }
    return Sol[capacity];
}

int main()
{
    scanf("%d", &n);
    scanf("%d", &capacity);
    for (int i=0; i<n; i++) scanf("%d", &Weight + i);
    for (int i=0; i<n; i++) scanf("%d", &Value + i);
    printf("%d\n",Knapsack01());
    return 0;
}
