#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;

FILE *f, *g;

struct inputSt
{
    int power,food;
};
struct node
{
    int nextPos, lastPos, currPow, maxPow, lastFood;
    double lastPow;
    node(int nPos, int lPos, int cPow,int mPow, double lPow, int lFood)
        :nextPos(nPos),lastPos(lPos),currPow(cPow),maxPow(mPow),lastFood(lFood), lastPow(lPow){}
};
bool cmpF (const inputSt& a,const inputSt& b)
{
    return (a.power*b.food)>(b.power*a.food);
}
bool cmpNode(const node& a, const node& b)
{
    return a.maxPow+a.lastPow<b.maxPow+b.lastPow;
}
bool cmpRes(const int& a, const int& b)
{
    return a>b;
}

int N, numFood, size, resNum;
inputSt A[2004];
vector<node> heapVect;
vector<int> heapRes;
int currPos = 0, currPower, currFood;
double lastPower;

int main(int argc, const char * argv[]) {

    f=fopen("test1.txt","r");
    g=fopen("resenje_netacno.txt","w");
    int br1;
    fscanf(f,"%d", &br1);
    for (int br = 0; br<br1; br++) {
    fscanf(f,"%d",&N);
    for(int i=0; i<N;i++)
        fscanf(f,"%d%d",&A[i].power, &A[i].food);
    fscanf(f,"%d%d",&numFood,&size);

    sort(A,A+N,cmpF);
    A[N].food=1000001;
    A[N].power=0;

    currFood=numFood;
    while(currFood>=A[currPos].food)
    {
        currFood-=A[currPos].food;
        currPower+=A[currPos].power;
        currPos++;
    }
    lastPower=currFood*A[currPos].power*1.0/A[currPos].food;
    heapVect.push_back(node(0,currPos,0,currPower,lastPower,currFood));
    heapRes.push_back(0);
    resNum=1;

    while(!heapVect.empty())
    {
        node x=heapVect.front();
        if(resNum==size && x.maxPow<heapRes.front())
            break;
        if(x.nextPos==N)
        {
            pop_heap(heapVect.begin(),heapVect.end(), cmpNode);
            heapVect.pop_back();
            continue;
        }
        if(x.nextPos<x.lastPos)
        {
            if(resNum<size)
            {
                heapRes.push_back(x.currPow+A[x.nextPos].power);
                push_heap (heapRes.begin(),heapRes.end(), cmpRes);
                resNum++;
            }
            else
            {
                if(x.currPow+A[x.nextPos].power>heapRes.front())
                {
                    pop_heap(heapRes.begin(),heapRes.end(), cmpRes);
                    heapRes.back()=x.currPow+A[x.nextPos].power;
                    push_heap (heapRes.begin(),heapRes.end(), cmpRes);
                }
            }
            currFood=A[x.nextPos].food+x.lastFood;
            currPos=x.lastPos;
            currPower=x.maxPow-A[x.nextPos].power;
            while(currFood>=A[currPos].food)
            {
                currFood-=A[currPos].food;
                currPower+=A[currPos].power;
                currPos++;
            }
            lastPower=currFood*A[currPos].power*1.0/A[currPos].food;
            if((resNum<size || currPower+lastPower>heapRes.front()) && x.nextPos<N-1)
            {
                heapVect.push_back(node(x.nextPos+1,currPos,x.currPow,currPower,lastPower,currFood));
                heapVect.front().currPow+=A[x.nextPos].power;
                heapVect.front().nextPos++;
                push_heap (heapVect.begin(),heapVect.end(), cmpNode);
            }
            else
            {
                heapVect.front().currPow+=A[x.nextPos].power;
                heapVect.front().nextPos++;
            }
        }
        else
        {
            currFood=x.lastFood;
            currPos=x.lastPos+1;
            while(currPos<N && A[currPos].food>currFood)
                currPos++;
            int stPos=currPos;
            currPower=x.currPow;
            while(currFood>=A[currPos].food)
            {
                currFood-=A[currPos].food;
                currPower+=A[currPos].power;
                currPos++;
            }
            lastPower=currFood*A[currPos].power*1.0/A[currPos].food;
            pop_heap (heapVect.begin(),heapVect.end(), cmpNode);
            if((resNum<size || currPower+lastPower>heapRes.front()) && stPos<N)
            {
                heapVect.back().nextPos=stPos;
                heapVect.back().lastPos=currPos;
                heapVect.back().maxPow=currPower;
                heapVect.back().lastFood=currFood;
                heapVect.back().lastPow=lastPower;
                push_heap (heapVect.begin(),heapVect.end(), cmpNode);
            }
            else
                heapVect.pop_back();
        }

    }

    sort_heap(heapRes.begin(), heapRes.end(),cmpRes);
    for (vector<int>::iterator it=heapRes.begin(); it!=heapRes.end(); ++it)
        fprintf(g,"%d\n",*it);

    for(int i=resNum; i<size;i++)
        fprintf(g,"0\n"); }
    fclose(f);
    fclose(g);
    return 0;
}
