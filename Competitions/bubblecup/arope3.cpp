#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct node{
    int value;
    int priority;
    int subtree_value;
    int _cnt;
    bool rev;
    node *l, *r;
} node;
typedef node* pnode;

int get_value(pnode t){
    return t? t->subtree_value : 1 << 30;
}
int get_size(pnode t){
    return t? t->_cnt : 0;
}
void update_value(pnode t){
    if(t) t->subtree_value = min(get_value(t->l), min(t->value, get_value(t->r)));
}
void update_size(pnode t){
    if(t) t->_cnt = get_size(t->l) + 1 + get_size(t->r);
}

void push(pnode &t){
    if(t && t->rev){
        update_size(t);
        update_value(t);
        t->rev = 0;
        swap(t->l, t->r);
        if(t->l) t->l->rev ^= 1;
        if(t->r) t->r->rev ^= 1;
    }
}

void Split(pnode t, pnode &l, pnode &r, int pos, int add = 0){
    if(!t)
        return void(l = r = NULL);
    push(t);
    int cur_pos = get_size(t->l) + add;
    if(cur_pos + 1 <= pos)
        Split(t->r, t->r, r, pos, cur_pos + 1), l = t;
    else Split(t->l, l, t->l, pos, add), r = t;
    update_size(t);
    update_value(t);
}
void Merge(pnode &t, pnode l, pnode r){
    push(l);
    push(r);
    if(!l || !r)
        t = l? l : r;
    else if(l->priority > r->priority)
        Merge(l->r, l->r, r), t = l;
    else Merge(r->l, l, r->l), t = r;
    update_size(t);
    update_value(t);
}

pnode Init(int key){
    pnode p = (pnode)malloc(sizeof(node));
    p->value = key;
    p->priority = rand();
    p->subtree_value = key;
    p->_cnt = 1;
    p->rev = 0;
    p->l = p->r = NULL;
    return p;
}
void Insert(pnode &f, pnode item, int pos){
    pnode l1, r1;
    Split(f, l1, r1, pos - 1);
    Merge(l1, l1, item);
    Merge(f, l1, r1);
}
void Insert(pnode &f, int pos, int key){
    pnode p = Init(key);
    Insert(f, p, pos);
}

int Kth_element(pnode t, int k){
    push(t);
    if(get_size(t->l) + 1 == k)
        return t->value;
    if(get_size(t->l) + 1 > k)
        return Kth_element(t->l, k);
    return Kth_element(t->r, k - get_size(t->l) - 1);
}
void copyFront(pnode &t, int l, int r){
    pnode l1, r1;
    Split(t, l1, r1, l - 1);
    pnode l2, r2;
    Split(r1, l2, r2, r - l + 1);
    l2->rev ^= 1;
    Merge(l2, l2, l1);
    Merge(t, l2, r2);
}
void copyBack(pnode &t, int l, int r){
    pnode l1, r1;
    Split(t, l1, r1, l - 1);
    pnode l2, r2;
    Split(r1, l2, r2, r - l + 1);
    l2->rev ^= 1;
    Merge(l1, l1, r2);
    Merge(t, l1, l2);
}

int q, t, l, r, n;
node* f;
string s;

int main() {
    cin >> s;
    n = s.length();
    for (int i=0; i<n; ++i) Insert(f, i+1, s[i]);

    scanf("%d", &q);
    while (q--){
        scanf("%d %d", &t, &l);
        if(t == 1){
            scanf("%d", &r);
            copyFront(f, l+1, r+1);
        }
        else if(t == 2){
            scanf("%d", &r);
            copyBack(f, l+1, r+1);
        }
        else printf("%c\n", Kth_element(f, l+1));
    }
    return 0;
}
