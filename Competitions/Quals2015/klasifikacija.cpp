#include <cstdio>
using namespace std;

int t, i, n, br, dis1, dis2, dis3, dis4, teme[15], x[15], y[15];

int main()
{
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);
        for (i=0; i<n; i++) scanf("%d%d", x+i, y+i);
        x[n] = x[0]; y[n] = y[0];
        x[n+1] = x[1]; y[n+1] = y[1];
        br = 0;
        for (i=2; i<n+2; i++) if ((x[i-1]-x[i-2])*(y[i]-y[i-2])-(y[i-1]-y[i-2])*(x[i]-x[i-2])) teme[br++] = i-1;

        if (br==0) printf("Duz\n");
        if (br==3)
        {
            dis1 = (x[teme[1]]-x[teme[0]])*(x[teme[1]]-x[teme[0]])+(y[teme[1]]-y[teme[0]])*(y[teme[1]]-y[teme[0]]);
            dis2 = (x[teme[0]]-x[teme[2]])*(x[teme[0]]-x[teme[2]])+(y[teme[0]]-y[teme[2]])*(y[teme[0]]-y[teme[2]]);
            dis3 = (x[teme[1]]-x[teme[2]])*(x[teme[1]]-x[teme[2]])+(y[teme[1]]-y[teme[2]])*(y[teme[1]]-y[teme[2]]);
            if (dis1==dis2 && dis1==dis3) printf("Trougao - Jednakokraki, Jednakostranicni\n"); else
            if (dis1==dis2 || dis1==dis3 || dis2==dis3)
            {
                printf("Trougao - Jednakokraki");
                if (dis1+dis2==dis3 || dis3+dis2==dis1 || dis1+dis3==dis2) printf(", Pravougli\n"); else printf("\n");
            } else
            if (dis1+dis2==dis3 || dis3+dis2==dis1 || dis1+dis3==dis2) printf("Trougao - Pravougli\n");
            else printf("Trougao\n");
        }
        if (br==4)
        {
            dis1 = (x[teme[1]]-x[teme[0]])*(x[teme[1]]-x[teme[0]])+(y[teme[1]]-y[teme[0]])*(y[teme[1]]-y[teme[0]]);
            dis2 = (x[teme[1]]-x[teme[2]])*(x[teme[1]]-x[teme[2]])+(y[teme[1]]-y[teme[2]])*(y[teme[1]]-y[teme[2]]);
            dis3 = (x[teme[3]]-x[teme[2]])*(x[teme[3]]-x[teme[2]])+(y[teme[3]]-y[teme[2]])*(y[teme[3]]-y[teme[2]]);
            dis4 = (x[teme[0]]-x[teme[3]])*(x[teme[0]]-x[teme[3]])+(y[teme[0]]-y[teme[3]])*(y[teme[0]]-y[teme[3]]);
            if (dis1==dis2 && dis2==dis3 && dis3==dis4)
            {
                if ((y[teme[1]]-y[teme[0]])*(y[teme[2]]-y[teme[1]])==(x[teme[0]]-x[teme[1]])*(x[teme[2]]-x[teme[1]]))
                    printf("Cetvorougao - Paralelogram, Romb, Trapez, Pravougaonik, Kvadrat\n");
                else printf("Cetvorougao - Paralelogram, Romb, Trapez\n");
            } else
            if (dis1==dis3 && dis2==dis4)
            {
                if ((y[teme[1]]-y[teme[0]])*(y[teme[2]]-y[teme[1]])==(x[teme[0]]-x[teme[1]])*(x[teme[2]]-x[teme[1]]))
                    printf("Cetvorougao - Paralelogram, Trapez, Pravougaonik\n");
                else printf("Cetvorougao - Paralelogram, Trapez\n");
            } else
            if ((y[teme[1]]-y[teme[0]])*(x[teme[3]]-x[teme[2]])==(y[teme[3]]-y[teme[2]])*(x[teme[1]]-x[teme[0]]) || (y[teme[2]]-y[teme[1]])*(x[teme[0]]-x[teme[3]])==(y[teme[0]]-y[teme[3]])*(x[teme[2]]-x[teme[1]]))
                printf("Cetvorougao - Trapez\n");
            else printf("Cetvorougao\n");
        }
        if (br>4) printf("Ostalo\n");
    }

    return 0;
}
