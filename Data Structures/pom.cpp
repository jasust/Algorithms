#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

FILE *f, *g;

int N, numFood, sizer, i, br1, nzm;
vector<int> res;

struct inputSt
{
    int power,food;
} A[2004];

int main()
{
    f=fopen("test1.txt","r");
    g=fopen("resenje.txt","w");
    fscanf(f,"%d", &br1);
    for (int br = 0; br<br1; br++) {
    bool neradi = false;
    fscanf(f,"%d",&N);
    for(i=0; i<N;i++) fscanf(f,"%d%d",&A[i].power, &A[i].food);
    fscanf(f,"%d%d",&numFood,&sizer);
    for (i=1; i<(1<<N); i++)
    {
        int pom = 1, br=0, sum = 0, sup = 0;
        while (pom<=i)
        {
            if (pom&i) { sup+=A[br].food; sum+=A[br].power; }
            pom <<= 1;
            br++;
        }
        if (sup<=numFood) res.push_back(sum);
        if (sup<=numFood && sum==749) printf("paznja --- %x ---", i);
    }
    sort(res.begin(), res.end(), greater<int>());
    for (i=0; i<min(sizer, (int)res.size()); i++)
    {
        fprintf(g,"%d\n", res[i]);

    }
    for (i=0; i<(sizer-(int)res.size()); i++) fprintf(g, "0\n");
    //if (neradi) printf("ne radi %d\n", br+1);
    }
    fclose(f);
    fclose(g);
    return 0;
}
