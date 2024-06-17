#include <cstdio>
#include <map>
#include <iostream>
#define MID (left+right)/2

using namespace std;

map<string,int> names;

const int MAX_N=100010;
const int INF=1000010;
int ST[4*MAX_N];
int a[MAX_N];

void Update(int idx,int x,int val,int left,int right)
{
    if(left==right)
    {
        ST[idx]=val;
        return;
    }
    if(x<=MID)Update(2*idx,x,val,left,MID);
    else Update(2*idx+1,x,val,MID+1,right);
    ST[idx]=(ST[2*idx]+ST[2*idx+1]);
}
int Query(int idx,int l,int r,int left,int right)
{
    if(l<=left&&right<=r)
        return ST[idx];
    int ret=0;
    if(l<=MID)ret+=Query(2*idx,l,r,left,MID);
    if(r>MID)ret+=Query(2*idx+1,l,r,MID+1,right);
    return ret;
}
int getVal(string s)
{
  int ret=0;
  for(int i=0;i<s.length();i++)
  {
    ret+=s[i]-'a'+1;
  }
  return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    int cur=1;
    while(q--)
    {
      char c;
      cin>>c;
      if(c=='A')
      {
        string s;
        cin>>s;
        if(names[s]>0)
        {
          cout<<("Can't add ");
          cout<<s<<endl;
        }
        else
        {
          names[s]=cur;
          Update(1,cur,getVal(s),1,10000);
          cur++;
        }
      }
      if(c=='S')
      {
        string x,y;
        cin>>x>>y;
        int xid=names[x];
        int yid=names[y];
        int xval=Query(1,xid,xid,1,10000);
        int yval=Query(1,yid,yid,1,10000);
        Update(1,xid,yval,1,10000);
        Update(1,yid,xval,1,10000);
        swap(names[x],names[y]);
      }
      if(c=='M')
      {
        string x,y;
        cin>>x>>y;
        int xid=names[x];
        int yid=names[y];
        cout<<Query(1,min(xid,yid),max(xid,yid),1,10000)<<endl;
      }
      if(c=='R')
      {
        string x,y;
        cin>>x>>y;
        int xid=names[x];
        names.erase(x);
        names[y]=xid;
        Update(1,xid,getVal(y),1,10000);

      }
      if(c=='N')
        cout<<(cur-1)<<endl;
    }

    return 0;
}
