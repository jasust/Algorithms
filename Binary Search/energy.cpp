#include <cstdio>
#include <iostream>
using namespace std;
#define EPS 0.00000001

int n, k;
int a[10004];

bool p(double sol) {
    double prenos = 0.0, preneti = 0.0;
    for (int i=0; i<n; i++)
        if (a[i]>sol) prenos += 1.0*a[i]-sol; else preneti += sol-1.0*a[i];
    return (prenos*(100-k)>=preneti*100);
}

double binary() {
    double l = 0.0, r = 10000000.0, mid;
    while (r-l>EPS) {
        mid = l+(r-l)/2;
        if (p(mid)) l = mid+EPS;
            else r = mid-EPS;
    }
    return (l+r)/2;
}

int main()
{
    cin >> n >> k;
    for (int i=0; i<n; i++) scanf("%d", a+i);
    printf("%.7lf", binary());
    return 0;
}
