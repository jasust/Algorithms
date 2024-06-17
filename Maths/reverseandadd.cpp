#include<cstdio>
//FILE *f;
using namespace std;

long long int unazad(long long int a)
{
    long long int sol = 0;
    while (a)
    {
        sol *= 10;
        sol += a%10;
        a /= 10;
    }
    return sol;
}

int main()
{
//    f=fopen("brojevi.txt","r");
    for (int i=1; i<=1; i++)
    {
        long long x, red = 1, j;
        x = 1112111;
//        fscanf(f,"%lld",&x);
        while (red<x) red *= 10;
        red /= 10;
        bool nasao = false;
        for (j=(x>>1); j<red; j++)
            if (j+unazad(j)==x) { nasao = true; printf("bar"); break; }
        if (nasao)
            for (j=red; j<x; j++)
                if (j+unazad(j)==x) { printf("ok %d\n", j); break; }
    }
    // resenja 121, 1111, 11011, 12221, 110011, 121121
}
