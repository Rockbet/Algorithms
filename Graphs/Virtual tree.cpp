#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10, maxl = 17;
int n, in[maxn], t;
typedef pair<int,int> pii;
#define f first
#define s second
vector<int> grafo[maxn];
vector<int> tree[maxn];
bool mark[maxn];
struct binarylift{
    int tab[maxn][maxl], nivel[maxn];
    void dfs(int u, int p){
        tab[u][0] = p;
        in[u] = t++;
        for(int v : grafo[u]){
            if(v == p) continue;
            nivel[v] = nivel[u] + 1;
            dfs(v, u);
        }
    }
    void init(){
        dfs(1, 0);
        for(int j=1; j<maxl; j++){
            for(int i=1; i<=n; i++){
                tab[i][j] = tab[tab[i][j-1]][j-1];
            }
        }
    }
    int lca(int u, int v){
        if(u == v) return u;
        if(nivel[u] < nivel[v]) swap(u, v);
        for(int i=maxl-1; i>=0; i--){
            if(nivel[u] - (1<<i) >= nivel[v]) u = tab[u][i];
        }
        if(u == v) return u;
        for(int i=maxl-1; i>=0; i--){
            if(tab[u][i] != tab[v][i]){
                u = tab[u][i], v = tab[v][i];
            }
        }
        return tab[u][0];
    }
}b;
void build_virtual_tree(vector<int> &k){
    auto c = [&](int u, int v){
        return in[u] < in[v];
    };
    sort(k.begin(), k.end(), c);
    int sz = (int)k.size();
    for(int i=1; i<sz; i++) k.push_back(b.lca(k[i-1], k[i]));
    sort(k.begin(), k.end(), c);
    k.erase(unique(k.begin(), k.end()), k.end());
    for(int i=1; i<k.size(); i++){
        int aux = b.lca(k[i-1], k[i]);
        tree[aux].push_back(k[i]);
    }
}
