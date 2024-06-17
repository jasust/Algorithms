#include<cstdio>
#include<cstdlib>

double ****A;

void alociraj(double ****A)
{
  A = (double****) malloc(sizeof(double***)*201);
  for (int i=0; i<=200; i++)
  A[i] = malloc((200-i+1)*sizeof(**double));
  for (int i=0; i<=200; i++)
  for (int j=200-i; j>=0; j--)
  A[i][j] = malloc(sizeof(*double)*(200-min(2*i+j,2*j+i)+1));
  for (int i=0; i<=200; i++)
  for (int j=200-i; j>=0; j--)
  for (int k=0; k<=200-min(2*i+j,2*j+i); k++)
  A[i][j][k] = malloc(sizeof(double)*(i+j+1));
}

int main()
{
    return 0;
}
