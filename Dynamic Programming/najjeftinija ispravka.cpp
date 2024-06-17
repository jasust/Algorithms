// program najjeftinija_ispravka
#include <stdio.h>
#include <cstring>
float min(float a,float b, float c)
 {
  float temp;

temp=a;
  if (b<temp) temp = b;
  if (c<temp) temp = c;
  return(temp);
  }

main()
 {
  float dp[100][100],  cUmet, cBrJ, cZam, cBrKr;
  char a[256], b[256];
  int i,j,k,m,n;

  printf("Unesi cenu umetanja: "); scanf ( "%f",   &cUmet);
  printf("Unesi cenu brisanja jednog simbola: ");
  scanf("%f", &cBrJ);
  printf("Cena zamene: "); scanf("%f", &cZam);
  printf("Cena brisanja do kraja stringa: ");
  scanf("%f", &cBrKr);
  printf("Unesi string A: "); gets(a);  m = strlen(a);
  printf("Unesi string B: "); gets(b);  n = strlen(b);

dp[0][0] = 0;
 for (i=1; i<=m; i++)
    {
      dp[i][0] = dp[i-1][0] + cBrJ;
      if (dp[i][0]>cBrKr) dp[i][0] = cBrKr;
    }

  for (i=1; i<=n; i++)
    dp[0][i] = dp[0][i-1] + cUmet;

  for (i=1; i<=m;i++)
  {
    for (j=1; j<=n; j++)
        if (a[i] == b[j]) dp[i][j] = dp[ i-1][j-1];
            else dp[i][j] = min(dp[i-1][j-1] + cZam, dp[i][j-1] + cUmet, dp[i-1][j] + cBrJ);
    for (k=1; k<=i-1;  k++)
        if (dp[i][n] > dp[k][n] + cBrKr )
            dp[i][n] = dp[k][n] + cBrKr;
  }

  printf("Najjeftinija ispravka kosta: %g\n", dp[m][n] );

}
