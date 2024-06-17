#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

int main ()
{
    freopen("test.txt", "w", stdout);
    srand (time(NULL));

    int n = 3; //(rand() % 2) + 3;
    printf("%d\n", n);

    for (int i=0; i<n; i++) printf("%d %d\n", (rand()*rand())%10000001, (rand()*rand())%10000001);

    fclose(stdout);
    return 0;
}
