/* Quickselect algoritam za nalazenje k-tog elementa po velicini u nizu
   Slozenost: O(n) - worst-case O(n^2)
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, a[1003];

int qselect(int *_a, int _l, int _r, int _k)
{
    int left = _l, right = _r;
    while (left<right)
    {
        int pivotidx = left, pivot = _a[(left+right)>>1];
        swap(_a[(left+right)>>1], _a[right]);
        for (int i=left; i<right; i++)
            if (_a[i]<pivot) swap(_a[i], _a[pivotidx]), pivotidx++;
        swap(_a[right],_a[pivotidx]);
        if (_k==pivotidx) return _a[pivotidx];
            else if (_k>pivotidx) left = pivotidx+1;
                else right = pivotidx-1;
    }
    return _a[left];
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++) scanf("%d", a+i);
    printf("%d", qselect(a,0,n-1,k-1));
    return 0;
}
