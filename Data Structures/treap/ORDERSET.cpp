#include <cstdio>
#include <algorithm>

using namespace std;

const int max_q = 1e6;

int q, x, ret;
char comm[11];

struct treap
{
  struct node
  {
    int key, pri, cnt;
    node *l, *r;
    node(){}
    node(int _key)
    {
      key = _key;
      pri = rand() % max_q;
      l = r = NULL;
      cnt = 1;
    }
  } *root;
  typedef node* pnode;
  treap() {root = NULL;}
  int get_cnt(pnode t) {return t ? t->cnt : 0;}
  void update(pnode t) {t ? t->cnt = get_cnt(t->l) + get_cnt(t->r) + 1 : 31;}
  void split(pnode t, pnode &l, pnode &r, int key)
  {
    if (!t) return void(l = r = NULL);
    if (key <= t->key) split(t->l, l, t->l, key), r = t;
    else split(t->r, t->r, r, key), l = t;
    update(t);
  }
  void merge(pnode &t, pnode l, pnode r)
  {
    if (!l || !r) t = l ? l : r;
    else if (l->pri > r->pri) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    update(t);
  }
  bool find(pnode t, int key)
  {
    if (!t) return false;
    else if (key == t->key) return true;
    else if (key < t->key) return find(t->l, key);
    else return find(t->r, key);
  }
  void insert(int key)
  {
    pnode t1, t2, x = new node(key);
    if (find(root, key)) return;
    split(root, t1, t2, key);
    merge(t1, t1, x);
    merge(root, t1, t2);
  }
  void erase(int key)
  {
    pnode t1, t2, t3;
    if (!find(root, key)) return;
    split(root, t1, t2, key);
    split(t2, t2, t3, key + 1);
    merge(root, t1, t3);
  }
  int count(pnode t, int key)
  {
    if (!t) return 0;
    else if (key == t->key) return get_cnt(t->l);
    else if (key < t->key) return count(t->l, key);
    else return 1 + get_cnt(t->l) + count(t->r, key);
  }
  int kth(pnode t, int k, int add = 0)
  {
    if (!t) return -1;
    int curr = add + get_cnt(t->l) + 1;
    if (k == curr) return t->key;
    else if (k < curr) return kth(t->l, k, add);
    else return kth(t->r, k, curr);
    return -1;
  }
} S;

int main()
{
  for (scanf("%d", &q); q--;)
  {
    scanf("%s %d", comm, &x);
    if (*comm == 'I') S.insert(x);
    else if (*comm == 'D') S.erase(x);
    else if (*comm == 'C') printf("%d\n", S.count(S.root, x));
    else
    {
      ret = S.kth(S.root, x);
      if (!~ret) puts("invalid");
      else printf("%d\n", ret);
    }
  }
  return 0;
}
