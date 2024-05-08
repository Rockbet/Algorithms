// Segment Tree with Lazy Propagation
// Build: O(n)
// Update: O(log n)
// Query: O(log n)
// Leonardo Paes

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
    ll sum;
    Node(){
        sum = 0LL;
    }
    Node(ll x){
        sum = x;
    }
};
class Seg{
public:
    Node join(Node &a, Node &b){
        return Node(a.sum + b.sum);
    }
    void flush(int node, int l, int r){
        if(!lazy[node].sum) return;
        tree[node].sum += 1LL*lazy[node].sum*(r-l+1);
        if(l != r){
            lazy[2*node].sum += lazy[node].sum;
            lazy[2*node+1].sum += lazy[node].sum;
        }
        lazy[node].sum = 0;
    }
    void build(int node, int l, int r){
        if(l == r){
            tree[node] = Node();
            lazy[node] = Node();
            return;
        }
        int mid = (l + r) >> 1;
        build(2*node, l, mid), build(2*node+1, mid+1, r);
        tree[node] = join(tree[2*node], tree[2*node+1]);
    }
    void update(int node, int tl, int tr, int l, int r, ll val){
        flush(node, tl, tr);
        if(tl > r or tr < l) return;
        if(tl >= l and tr <= r){
            lazy[node].sum += val;
            flush(node, tl, tr);
            return;
        }
        int mid = (tl + tr) >> 1;
        update(2*node, tl, mid, l, r, val), update(2*node+1, mid+1, tr, l, r, val);
        tree[node] = join(tree[2*node], tree[2*node+1]);
    }
    Node query(int node, int tl, int tr, int l, int r){
        flush(node, tl, tr);
        if(tl > r or tr < l) return Node();
        if(tl >= l and tr <= r) return tree[node];
        int mid = (tl + tr) >> 1;
        Node a = query(2*node, tl, mid, l, r), b = query(2*node+1, mid+1, tr, l, r);
        return join(a, b);
    }
private:
        Node tree[1<<19], lazy[1<<19];
}seg;
