// Persistent Segment Tree
// Update: (log n)
// Query: (log n)


#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

int vet[maxn];

struct Node{
    int v;
    Node *l, *r;

    Node(){
        v = 0;
        l = r = nullptr;
    }
};

void build(Node *node, int l, int r){
    if(l == r){
        node->v = vet[l];
        return;
    }

    int mid = (l+r) >> 1;

    node->l = new Node(), node->r = new Node();

    build(node->l, l, mid);
    build(node->r, mid+1, r);

    node->v = node->l->v + node->r->v;
}

void update(Node *prev, Node *node, int l, int r, int idx ,int val){
    if(l == r){
        node->v = val;
        return;
    }

    int mid = (l+r) >> 1;

    if(idx<=mid){
        node->r = prev->r;

        if(!node->l) node->l = new Node();

        update(prev->l, node->l, l, mid, idx, val);
    }
    else{
        node->l = prev->l;

        if(!node->r) node->r = new Node();

        update(prev->r, node->r, mid+1, r, idx, val);
    }

    node->v = node->l->v + node->r->v;
}

int query(Node *node, int tl, int tr, int l, int r){
    if(tl > r or tr < l) return 0;
    if(tl >= l and tr <= r) return node->v;

    int mid = (tl+tr) >> 1;

    return query(node->l, tl, mid, l, r) + query(node->r, mid+1, tr, l, r);
}
