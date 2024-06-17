#include <cstdio>
using namespace std;

int A, B;

int main()
{
    scanf("%d%d", &A, &B);

    printf("%d %d", (A+B)>>1, (A-B)>>1);

    return 0;
}
