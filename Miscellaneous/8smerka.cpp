#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int n,len;
char a[1005][1005];
char s[15];
long long int result = 0;
long long int* currStr;
long long int* prevStr;
long long int* tmp;

long long int eltondzon(int l, int r, char xStep, char yStep, int limit)
{
if (limit < 2) { return 0; }

//Uradi za prvo slovo stringa s
int currX = l;
int currY = r;

if (a[currX][currY] == s[0]) { prevStr[0] = 1; }
else { prevStr[0] = 0; }
currX += xStep; currY += yStep;

for (int i=1; i < limit; ++i)
{
if (a[currX][currY] == s[0]) { prevStr[i] = prevStr[i-1] + 1; }
else { prevStr[i] = prevStr[i-1]; }
currX += xStep; currY += yStep;
}


//Uradi za 2 -> length(s)
for (int curr=1; curr < len; ++curr)
{
currStr[0] = 0;
currX = l + xStep;
currY = r + yStep;

for (int i=1; i < limit; ++i)
{
if (a[currX][currY] == s[curr]) { currStr[i] = currStr[i-1] + prevStr[i-1]; }
else { currStr[i] = currStr[i-1]; }
currX += xStep; currY += yStep;
}

long long int* tmp = prevStr;
prevStr = currStr;
currStr = tmp;
}

return prevStr[limit-1];
}

int main(void)
{
prevStr = (long long int*) calloc(1005,sizeof(int));
currStr = (long long int*) calloc(1005,sizeof(int));

scanf("%d %s",&n,s);
for (int i=0; i<n; ++i) scanf("%s",a[i]);
len = strlen(s);

//i=0
result += eltondzon(0, 0, 0, 1, n); //Desno
result += eltondzon(0, n-1, 0, -1, n); //Levo
result += eltondzon(0, 0, 1, 0, n); //Dole
result += eltondzon(n-1, 0, -1, 0, n); //Gore
result += eltondzon(n-1, 0, -1, 1, n); //Gore-Desno
result += eltondzon(0, n-1, 1, -1, n); //Dole-Levo
result += eltondzon(0, 0, 1, 1, n); //Dole-Desno
result += eltondzon(n-1, n-1, -1, -1, n); //Gore-Levo
//printf("i=0 %lld\n",result);

for (int i=1; i<n; ++i)
{
//Desno, Levo, Dole, Gore
result += eltondzon(i, 0, 0, 1, n); //Desno
result += eltondzon(i, n-1, 0, -1, n); //Levo
result += eltondzon(0, i, 1, 0, n); //Dole
result += eltondzon(n-1, i, -1, 0, n); //Gore

//Gore-Desno
result += eltondzon(n-1-i, 0, -1, 1, n-i); //Vertikalno
result += eltondzon(n-1, i, -1, 1, n-i); //Horizontalno

//Dole-Levo
result += eltondzon(i, n-1, 1, -1, n-i); //Vertikalno
result += eltondzon(0, n-1-i, 1, -1, n-i); //Horizontalno

//Dole-Desno
result += eltondzon(i, 0, 1, 1, n-i); //Vertikalno
result += eltondzon(0, i, 1, 1, n-i); //Horizontalno

//Gore-Levo
result += eltondzon(n-1-i, n-1, -1, -1, n-i); //Vertikalno
result += eltondzon(n-1, n-1-i, -1, -1, n-i); //Horizontalno
//printf("i=%d %lld\n",i,result);
}

printf("%I64d",result);
//free(currStr);
//free(prevStr);
return 0;
}
