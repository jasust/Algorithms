#include <cstdio>
#include <iostream>
using namespace std;

long long n, step;
int mask, br;
FILE *f;

int main (){
    f=fopen("bindecimal.txt","w");
    for (int i=1; i<524288; i++)
    {
        mask = 1; step = 1;
        n = 0;
        for (mask = 1; mask<=262144; mask <<=1, step *=10LL) if (mask&i) n+= step;
        if ((n&(1LL*i))==(i*1LL)) br++, fprintf(f,"%I64d\n", n);
    }
    fprintf(f,"%d",br);
    fclose(f);

    return 0;
}
