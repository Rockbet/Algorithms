#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> edge;
#define f first
#define s second
const int maxn = 5e5+10;
struct dsu{
    int pai[maxn], sz[maxn];
    stack<edge> s;
    int find(int x){return (pai[x] == x ? x : find(pai[x]));};
    void join(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return;
        if(sz[a] > sz[b]) swap(a, b);
        pai[a] = b;
        sz[b] += sz[a];
        s.push({b, a});
    }
    void rollback(){
        int u = s.top().f, v = s.top().s;
        s.pop();
        pai[v] = v;
        sz[u] -= sz[v];
    }
};
