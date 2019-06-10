// Segment Tree with Lazy Propagation
// Build: O(n)
// Update: O(log n)
// Query: O(log n)


#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int vet[maxn], tree[4*maxn], lazy[4*maxn];

void build(int node, int l, int r){

    if(l==r){
        tree[node]=vet[l];
        return;
    }

    int mid = (l+r)>>1;

    build(2*node,l,mid);
    build(2*node+1,mid+1,r);

    tree[node] = tree[2*node] + tree[2*node+1];
}

void flush(int node, int l, int r){

    if(!lazy[node]){
        return;
    }

    tree[node] += lazy[node]*(r-l+1);

    if(l!=r){
        lazy[2*node] += lazy[node];
        lazy[2*node+1] += lazy[node];
    }

    lazy[node]=0;
}

void update(int node, int tl, int tr, int l, int r, int v){

    if(tl>r or l>tr)return;

    flush(node,tl,tr);

    if(tl>=l and tr<=r){
        lazy[node]+=v;
        flush(node,tl,tr);
        return;
    }

    int mid = (tl+tr) >> 1;

    update(2*node, tl, mid, l, r, v);
    update(2*node+1, mid+1, tr, l, r, v);

    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node, int tl, int tr, int l, int r){

    if(tl>r or l>tr)return 0;

    flush(node,tl,tr);

    if(tl>=l and tr<=r)return tree[node];

    int mid = (tl+tr) >> 1;

    return query(2*node, tl, mid, l, r) + query(2*node+1, mid+1, tr, l ,r);
}

int main(){

    int n, q;

    cin >> n >> q;

    for(int i=1; i<=n; i++){
        cin >> vet[i];
    }

    build(1,1,n);

    for(int i=1; i<=q; i++){
        // Queries
    }
}
