/*Codeforces Problem 340D-Bubble Sort Graph */
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, x[100005];
vector < int > lis;

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", x + i);

    lis.push_back(0);
    for (int i=1; i<n; i++)
    {
        if (x[i] >= x[lis.back()]) lis.push_back(i);
        else
        {
            int left = 0, right = lis.size() - 1;
            while (left < right)
            {
                int mid = (left + right) / 2;
                if (x[lis[mid]] <= x[i]) left = mid + 1;
                else right = mid;
            }
            lis[left] = i;
        }
    }

    printf("%d\n", lis.size());

    return 0;
}
