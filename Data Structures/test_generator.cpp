#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define TEST 1
time_t t;
FILE *f;

int main()
{
    srand((unsigned) time(&t));
    f=fopen("test1.txt","w");
    fprintf(f,"%d\n", TEST);
    for (int i=0; i<TEST; i++)
    {
        int n = rand() % 20 +1;
        fprintf(f,"%d\n", n);
        for (int j=0; j<n; j++) { fprintf(f,"%d %d\n", rand() % 1000 +1, rand() % 1000 +1); }
        fprintf(f, "%d %d\n", rand() % 1000 +1, rand() % 40 +1);
    }
    fclose(f);
    return 0;
}
