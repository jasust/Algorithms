/* 4. Дата је логичка формула од највише 6 променљивих користећи стек израчунати вредности израза. */
#include<cstdio>
using namespace std;

struct node
{
    int inf;
    node* prev;
    node* next;
} a;

int n, bitmask;

int main()
{
    scanf("%d", &n);
    bitmask = 1<<n;

    return 0;
}
