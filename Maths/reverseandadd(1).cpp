#include<cstdio>
long long curr = 1;
bool par = true;

long long unazad(long long a)
{
    long long sol = 0;
    while (a)
    {
        sol *= 10;
        sol += a%10;
        a /= 10;
        if (!sol) printf("0");
    }
    return sol;
}

void stampaj()
{
    long long pom = curr*11;
    if (!par)
    {
        printf("%lld",pom);
        printf("%lld\n",unazad(pom));
        return;
    }
    if (curr&1) printf("%lld",pom+1); else printf("%lld",pom);
    printf("%lld\n",unazad(pom/10));
    return;
}

long long next(long long a)
{
    long long des = 1;
    while (((long long)(a/des))&1) des*=10;
    if (des>a)
    {
        par = !par;
        if (!par) return (des/10);
        return des;
    }
    return (a-(a%des)+des);
}

int main()
{
    for (int i=0; i<4991; i++)
    {
        stampaj();
        curr = next(curr);
        if (par)
            switch (curr)
            {
            case 110LL: printf("1197801\n"); break;
            case 1100LL: printf("119777801\n"); break;
            case 11000LL: printf("11977777801\n"); break;
            case 110000LL: printf("1197777777801\n"); break;
            case 1100000LL: printf("119777777777801\n"); break;
            case 11000000LL: printf("11977777777777801\n"); break;
            case 110000000LL: printf("1197777777777777801\n"); break;
            case 1100000000LL: printf("119777777777777777801\n"); break;
            case 11000000000LL: printf("11977777777777777777801\n"); break;
            }
    }
    return 0;
}
