// Leonardo Paes
//
// Implementation of Sack (DSU on Tree)
//
// Time Complexity: O(n log n)

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

vector<int> grafo[maxn]; // 1-indexed

int cor[maxn], cnt[maxn], freq[maxn], sz[maxn], big[maxn];

void dfs(int u, int p){
    sz[u] = 1;
    for(auto v : grafo[u]){
        if(v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void add(int u, int p, int x){
    int c = cor[u];
    freq[cnt[c]]--;
    cnt[c] += x;
    freq[cnt[c]]++;
    for(auto v : grafo[u]){
        if(v == p or big[v]) continue;
        add(v, u, x);
    }
}

void sack(int u, int p, bool keep){
    int idmax = 0;
    for(auto v : grafo[u]){
        if(v == p or sz[idmax] > sz[v]) continue;
        idmax = v;
    }
    for(auto v : grafo[u]){
        if(v == p or v == idmax) continue;
        sack(v, u, 0);
    }
    if(idmax) sack(idmax, u, 1), big[idmax] = 1;
    add(u, p, 1);
    big[idmax] = 0;
    if(!keep) add(u, p, -1);
}
