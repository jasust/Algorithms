#include <cstdio>
using namespace std;

int t;
long long n;

int main() {

    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        if (n<4) printf("1\n");
         else if (n==4) printf("2\n");
           else printf("%lld\n", n);
    }

    return 0;
}
