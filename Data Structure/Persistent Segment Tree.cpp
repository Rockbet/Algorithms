// Persistent Segment Tree
// Update: (log n)
// Query: (log n)

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

struct Node{
    int v = 0;
    Node *l = this, *r = this;
};

Node *root[maxn];

Node* update(Node *root, int l, int r, int idx, int val){
    Node *node = new Node();

    *node = *root;

    int mid = (l + r) >> 1;

    node->v += val;

    if(l != r){
        if(idx <= mid) node->l = update(root->l, l, mid, idx, val);
        else node->r = update(root->r, mid+1, r, idx, val);
    }

    return node;
}

int query(Node *node, int tl, int tr, int l, int r){
    if(tl > r or tr < l) return 0;
    if(tl >= l and tr <= r) return node->v;

    int mid = (tl+tr) >> 1;

    return query(node->l, tl, mid, l, r) + query(node->r, mid+1, tr, l, r);
}
