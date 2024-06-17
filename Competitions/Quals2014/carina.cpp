#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long N,C,L,X;
long long pos,trucks,cdist,step;

int main(){
    //freopen("carina.txt","r",stdin);
    scanf("%lld%lld%lld%lld",&N,&C,&L,&X);
    if ((double)C * (double)(X+1) <= 2e18){ //jao zamalo da me zajebete ovde
        N = min(N , C*(X+1));
    }
    while (true){
        if (N<=0){
            N = 0;
            break;
        }
        trucks = (N+C-1)/C;
        cdist = (N - (trucks-1)*C + trucks - 1) / trucks;
        if (pos + cdist >= L){
            N -= trucks * (L - pos);
            break;
        } else {
            pos += cdist;
            N -= trucks * cdist;
        }
    }
    printf("%lld\n",N);
    return 0;
}
