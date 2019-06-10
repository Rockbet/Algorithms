// Treap 
// Build in O(n) and other operations in O(log n)

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int vet[maxn];

struct node{

    int v, p, sz;
    node *l, *r;

    node(int value){
        v = value, p=rand(), sz=1;
        l = r = NULL;
    }
};

void make_heap(node *t){

    if(!t) return;

    node *aux = t;

    if(t->l != NULL and t->l->p > aux->p) aux = t->l;
    if(t->r != NULL and t->r->p > aux->p) aux = t->r;

    if(aux!=t){
        swap(t->p, aux->p);
        make_heap(aux);
    }
}

node* build(int l, int r){

    if(l>r) return NULL;

    int mid = (l+r)>>1;

    node *t = new node(vet[mid]);

    t->l = build(l, mid-1);
    t->r = build(mid+1, r);

    make_heap(t);

    return t;
}

int sz(node* t){return (t ? t->sz : 0);}

void op(node *t){
    t->sz = sz(t->l) + sz(t->r) + 1;
}

void merge(node*& t, node *l, node *r){
    if(!l or !r) t = (l ? l : r);
    if(l->p > r->p) merge(l->r, l->r, r), t=l;
    else merge(r->l, l, r->l);
    op(t);
}

void split(node*& t, node *l, node *r, int v){
    if(!t) return void(l=r=NULL);
    if(t->v < v) split(t->r, t->r, r, v);
    else split(t->l, l, t->l, v);
    op(t);
}

void insert(node*& t, node *aux){
    if(!t) t = aux;
    else if(aux->p > t->p) split(t, aux->l, aux->r, aux->v);
    else insert((aux->v > t->v ? t->r : t->l), aux);
    op(t);
}

void erase(node*& t, int x){
    if(t->v==x) merge(t, t->l, t->r);
    else erase(( t->v < x ? t->r : t->l ), x);
    op(t);
}
