#include <cstdio>
using namespace std;

long long k;
int n;
int a[50];

int main() {

    while (1) {
        scanf("%lld %d", &k, &n);
        if (k==0) break;

        int step = 0, sum = 0;
        while (k) {
            sum += a[step++] = k%n;
            k /= n;
        }
        printf("%d ", sum + --step);
        for (int i=step; i; --i) {
            while (a[i]--) printf("S");
            if (i==step && n==2) printf("S");
                else printf("M");
        }
        while (a[0]--) printf("S");
        printf("\n");
    }

    return 0;
}
