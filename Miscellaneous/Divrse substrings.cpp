/*                             Codeforces Problem 386C Diverse Substrings
  Definisan je diverzitet stringa kao broj razlicitih karaktera tog stringa. Za zadati niz malih slova alfabeta duzine do 3*10^5
  odrediti diverzitet kao i broj podstringova sa diverzitetom od 1 do diverziteta stringa, pojedinacno.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long lld;

int n, i, last[28], tmp[28];
lld ans[28];
char s[300005];

int main()
{
    scanf("%s",s);
    for (i=0; i<=26; i++) last[i]=-1;
    int length = strlen(s);
    for (i=0; i<length; i++)
    {
        last[s[i]-'a']=i;
        for (int j=0; j<=26; j++) tmp[j]=last[j];
        sort(tmp, tmp+27);
        for (int j=26; j; j--) ans[26-j+1] += tmp[j] - tmp[j-1];
    }
    for (i=1; i<=26;i++) if (!ans[i]) break;
    printf("%d\n",i-1);
    for (int j=1; j<i; j++) printf("%I64d\n",ans[j]);
    return 0;
}
