// Union-Find
// O(alpha(n))
// Leonardo Paes
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

struct DSU{
    vector<int> pai, sz;
    void init(int n){
        pai.resize(n+1);
        sz.resize(n+1);
        for(int i=1; i<=n; i++){
            pai[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x){ return pai[x] == x ? x : pai[x] = find(pai[x]); }
    void join(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return;
        if(sz[a] > sz[b]) swap(a, b);
        pai[a] = b;
        sz[b] += sz[a];
    }
}dsu;
