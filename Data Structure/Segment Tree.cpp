// Segment Tree
// Build: O(n)
// Update: O(log n)
// Query: O(log n)
// Leonardo Paes

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+10;
const ll inf = 2e18;
int v[maxn];
struct Node{
    ll mn;
    Node(){
        mn = inf;
    }
    Node(int x){
        mn = x;
    }
};
struct Seg{
    Node tree[1<<19];
    Node join(Node &a, Node &b){
        return Node(min(a.mn, b.mn));
    }
    void build(int node, int l, int r){
        if(l == r){
            tree[node] = Node(v[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(2*node, l, mid), build(2*node+1, mid+1, r);
        tree[node] = join(tree[2*node], tree[2*node+1]);
    }
    Node query(int node, int tl, int tr, int l, int r){
        if(tl > r or tr < l) return Node();
        if(tl >= l and tl <= r) return tree[node];
        int mid = (tl + tr) >> 1;
        Node a = query(2*node, tl, mid, l, r), b = query(2*node+1, mid+1, tr, l, r);
        return join(a, b);
    }
}seg;
