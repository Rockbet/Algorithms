#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
vector<int> grafo[maxn], bcc[2*maxn];
int n, m, in[maxn], low[maxn], t, bccs = 1; // tempo de entrada e menor tempo de entrada de back-edge
stack<int> s;
 
void dfs(int u, int p = 0){
    in[u] = low[u] = ++t;
    s.push(u);
    ++sz;
    for(int v : grafo[u]){
        if(v == p) continue;
        if(!in[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= in[u]){
                int id = n + bccs;
                bcc[u].push_back(id);
                while(bcc[id].empty() or bcc[id].back() != v){
                    bcc[id].push_back(s.top());
                    s.pop();
                }
                bccs++;
            }
        }
        else low[u] = min(low[u], in[v]);
    }
}
