//Dato je n celih brojeva.Koliko najmanje brojeva treba da promenis da bi prvi
//deo niza cinili samo negativni,a drugi samo pozitivni brojevi
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int put,n,s[100002],cur;

int main()
{
  cur=0;
  scanf("%d",&n);
  for(int i=0; i<n; i++)
    {
       scanf("%d",&s[i]);
       if(i==0 && s[i]>=0) cur++;
       if(i!=0 && s[i]<=0) cur++;
    }
  put=cur;
  for(int i=1; i<n-1; i++)
  {
    if(s[i]>0) cur++;
    if(s[i]<0) cur--;
    if(cur<put) put=cur;
  }
  printf("%d\n",put);
  return 0;
}
