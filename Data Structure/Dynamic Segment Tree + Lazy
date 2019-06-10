// Dynamic Segment Tree with Lazy Propagation <3 <3 <3
// Update: (log n)
// Query: (log n)

#include <bits/stdc++.h>

int node_cur=0;

std::vector<int> left, right, lazy;

std::vector<long long> sum;

void create(){
    left.push_back(0);
    right.push_back(0);
    sum.push_back(0);
    lazy.push_back(0);
}

void flush(int node, int l, int r){

    if(lazy[node]==0){
        return;
    }
    sum[node]+=(r-l+1)*lazy[node];

    if(l!=r){
        if(left[node]==0){
            create();
            left[node] = ++node_cur;
        }
        if(right[node]==0){
            create();
            right[node] = ++node_cur;
        }
        lazy[left[node]]+=lazy[node];
        lazy[right[node]]+=lazy[node];
    }
    lazy[node]=0;

    return;
}

void update(int node, int tl, int tr, int l, int r, int val){

    flush(node, tl, tr);

    if(l>tr or tl>r)return;

    if(l<=tl and tr<=r){
        lazy[node]+=val;
        flush(node, tl, tr);
        return;
    }

    int mid = (tl+tr)>>1;

    if(tl==tr-1)mid=tl;

    if(left[node]==0){
        create();
        left[node] = ++node_cur;
    }
    update(left[node], tl, mid, l, r, val);
    if(right[node]==0){
        create();
        right[node] = ++node_cur;
    }
    update(right[node], mid+1, tr, l, r, val);

    sum[node]=(((left[node]==0) ? 0:sum[left[node]]) + (right[node]==0) ? 0:sum[right[node]]);
}

int query(int node, int l, int r, int idx){

    flush(node, l, r);

    if(node==0 or idx<l or idx>r){
        return 0;
    }

    if(l==r){
        return sum[node];
    }

    int mid = (l+r)>>1;

    if(l==r-1)mid=l;

    return query(left[node], l, mid, idx) + query(right[node], mid+1, r, idx);
}

