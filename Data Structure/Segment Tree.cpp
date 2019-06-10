// Segment Tree
// Build: O(n)
// Update: O(log n)
// Query: O(log n)

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int vet[maxn], tree[4*maxn];

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

void update(int node, int tl, int tr, int idx, int v){

    if(tl==tr){
        tree[node]=v;
        return;
    }
    int mid = (tl+tr)>>1;

    if(tl<=idx and idx<=mid) update(2*node,tl,mid,idx,v);
    else update(2*node+1,mid+1,tr,idx,v);

    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node, int tl, int tr, int l, int r){

    if(r<tl or l>tr) return 0;

    if(l<=tl and r>=tr) return tree[node];

    int mid = (l+r)>>1;

    return query(2*node, l, mid, l, r)+query(2*node+1, mid+1, r, l, r);
}

int main(){

    int n;

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> vet[i];
    }

    build(1,1,n);

    int q;

    cin >> q;

    for(int i=1; i<=q; i++){
        // Queries
    }

    return 0;
}

