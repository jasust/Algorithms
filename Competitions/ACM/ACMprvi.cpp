#include <cstdio>
#include <iostream>
using namespace std;

int n, q, brr, brc, i;
long long int sumr, sumc;
char ch;
bool red[1000006], col[1000006];
FILE *f, *g;

int main (){
  f=fopen("adjustment.in","r");
  g=fopen("adjustment.out","w");
  fscanf(f,"%d%d", &n, &q);
  long long s = 1LL*n*(n+1)/(2LL);

  while (q--)
  {
      fscanf(f,"%*c%c%d", &ch, &i);
      if (ch=='R')
      {
          if (!red[i]) {
            red[i] = 1;
            brr += 1;
            sumr += i;
            fprintf(g,"%I64d\n", s+1LL*i*(n-brc)-sumc);
          } else fprintf(g,"0\n");
      } else
      {
          if (!col[i]) {
            col[i] = 1;
            brc += 1;
            sumc += i;
            fprintf(g,"%I64d\n", s+1LL*i*(n-brr)-sumr);
          } else fprintf(g,"0\n");
      }
  }
  fclose(f);
  fclose(g);

  return 0;
}
