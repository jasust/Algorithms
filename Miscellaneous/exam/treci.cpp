/* 3. У пећини, висине s, су наизменично дате висине сталактита и сталагмита,
   на којој висини права паралелна тлу пробија најмање препрека. */
#include<cstdio>
using namespace std;

int s, h, i, mini=1e9, br, st1[1000006], st2[1000006], sol[1000006];
bool stalaktit = true;

int main()
{
    scanf("%d", &s);
    while (scanf("%d", &h)!=-1)
    {
        if (stalaktit)
        {
            st1[0]++;
            st1[h+1]--;
        } else
        {
            st2[0]++;
            st2[h+1]--;
        }
        stalaktit = !stalaktit;
    }
    for (i=1; i<=s; i++)
    {
        st1[i]+=st1[i-1];
        st2[i]+=st2[i-1];
    }
    for (i=1; i<=s; i++)
    {
        if (st1[i]+st2[s-i+1]==mini) { br++; sol[br]=i; }
        if (st1[i]+st2[s-i+1]<mini) { mini=st1[i]+st2[s-i]; br=1; sol[br]=i; }
    }
    printf("%d\n", mini);
    for (i=1; i<=br; i++) printf("%d ", sol[i]);

    return 0;
}
