#include <cstdio>
#include <cstring>
#include <algorithm>
#define DEBUG (false)
using namespace std;

struct tacka{
    long long x,y;
    inline friend tacka operator -(tacka a,tacka b){
        a.x -= b.x;
        a.y -= b.y;
        return a;
    }
    inline friend bool operator *(tacka a,tacka b){
        return a.x*b.x + a.y*b.y > 0;
    }
    inline friend bool operator <(tacka a,tacka b){
        bool a1,b1;
        a1 = a.y > 0 || (a.y == 0 && a.x > 0);
        b1 = b.y > 0 || (b.y == 0 && b.x > 0);
        if (a1 && !b1) return true;
        if (b1 && !a1) return false;
        //a je manji (ide pre b) od b ako ima veci x/y
        //return a.x / a.y > b.x / b.y;
        return a.x * b.y > b.x * a.y;
    }
};

tacka A[1005],Q[1005];
int N,tup;

long long turn(tacka a,tacka b){ //0-ta tacka je 0,0
    return a.x*b.y - b.x*a.y;
    //ovo je >0 kada 0-a-b skrece u levo
    //ovo je <0 kada 0-a-b skrece u desno
    //ovo je =0 kada su kolinearne
}

inline bool levaostraoblast(tacka a,tacka b){
    return a*b && turn(a,b)>=0;
}

inline bool desnaostraoblast(tacka a,tacka b){
    return a*b && turn(a,b)<=0;
}

long long safeconvert(double x){
    x *= 1000;
    long long f = x;
    if (f > x+0.5) f--; else
    if (f < x-0.5) f++;
    return f;
}

void ucitaj_tacke(){
    scanf("%d",&N);
    int i;
    double xx,yy;
    for (i=1; i<=N; i++){
        scanf("%lf%lf",&xx,&yy);
        A[i].x = safeconvert(xx);
        A[i].y = safeconvert(yy);
    }
}

inline int nxt(int x){
    x++;
    if (x==N) x=1;
    return x;
}

inline int prev(int x){
    x--;
    if (x==0) x=N-1;
    return x;
}

inline int between(int st,int en){
    if (st <= en) return en-st+1;
    return N-st+en;
}

void nadjitupe(){
    int i,j,n=N-1,st,en,x;
    sort(Q+1,Q+N);
    if (DEBUG){
        for (i=1; i<=n; i++) printf("pt %lld %lld\n",Q[i].x,Q[i].y);
    }
    //krecemo od prve tacke sa kruga. za nju nalazimo st i en
    en=1;
    for (i=1; i<=n; i++){
        if (levaostraoblast(Q[1],Q[i])){
            en = i;
        } else break;
    }
    st=1;
    for (i=n; i>1; i--){
        if (desnaostraoblast(Q[1],Q[i])){
            if (i==en) break;
            st = i;
        } else break;
    }
    if (DEBUG) printf("st = %d ; en = %d\n",st,en);
    tup += n-between(st,en);
    if (DEBUG) printf("tup %d\n",tup);
    for (x=2; x<=n; x++){
        //start advancuje, izbacuje nepodobne tacke
        //ali usput i pomera en
        while (!desnaostraoblast(Q[x],Q[st])){
            if (st==en){
                st = nxt(st);
                en = st;
            } else st = nxt(st);
        }
        //end advancuje, ali ne vise od starta
        while (levaostraoblast(Q[x],Q[nxt(en)])){
            if (nxt(en)==st) break;
            en = nxt(en);
        }
        if (DEBUG) printf("st = %d ; en = %d\n",st,en);
        tup += n-between(st,en);
        if (DEBUG) printf("tup %d\n",tup);
    }
}

void resavaj(){
    int i,j,k;
    for (i=1; i<=N; i++){
        k=0;
        if (DEBUG) printf("%d\n",i);
        for (j=1; j<=N; j++){
            if (j!=i){
                k++;
                Q[k] = A[j]-A[i];
            }
        }
        nadjitupe();
    }
}

void stampaj(){
    printf("%d\n",N*(N-1)*(N-2)/6 - tup/2);
}

int main(){
    //freopen("trouglovi.txt","r",stdin);
    ucitaj_tacke();
    resavaj();
    stampaj();
    return 0;
}

