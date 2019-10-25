// SPOJ - QTREE
// Leonardo Paes
//
// Implementation of HLD
//
// Query O(log^2 n)
// Update O(log n)

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4+10;

typedef pair<int,int> pii;

int t, n;

int pai[maxn], nivel[maxn], size[maxn], edge[maxn];

int chain[maxn], head[maxn], pos[maxn], c, qtd;

int tree[4*maxn];

pii edge_input[maxn];

vector<pii> grafo[maxn];

void update_tree(int node, int l, int r, int pos, int v){
	if(l==r){
		tree[node] = v;
		return;
	}

	int mid = (l+r)>>1;

	if(pos<=mid) update_tree(2*node, l, mid, pos, v);
	else update_tree(2*node+1, mid+1, r, pos, v);

	tree[node] = max(tree[2*node], tree[2*node+1]);
}

int query_tree(int node, int tl, int tr, int l, int r){
	if(l>tr or r<tl) return -1;
	if(l<=tl and tr<=r) return tree[node];

	int mid = (tl+tr)>>1;

	return max(query_tree(2*node, tl, mid, l, r), query_tree(2*node+1, mid+1, tr, l, r));
}

void dfs(int u, int p){
	size[u] = 1;

	for(int i=0; i<grafo[u].size(); i++){
		int v = grafo[u][i].first, d = grafo[u][i].second;
		if(v==p) continue;
		pai[v] = u, nivel[v] = nivel[u] + 1, edge[v] = d;
        dfs(v, u);
        size[u] += size[v];
	}
}

void hld(int u){
	if(!head[c]) head[c] = u;

	chain[u] = c, pos[u] = ++qtd;

	update_tree(1, 1, n, pos[u], edge[u]);

	int maior = -1 , id = -1;

	for(int i=0; i<grafo[u].size(); i++){
		int v = grafo[u][i].first;
		if(v!=pai[u] and maior<size[v]){
			maior = size[v], id = v;
		}
	}

	if(id!=-1) hld(id);

	for(int i=0; i<grafo[u].size(); i++){
		int v = grafo[u][i].first;
		if(v!=pai[u] and v!=id){
			c++;
			hld(v);
		}
	}
}

int lca(int u, int v){
	while(chain[u]!=chain[v]){
		if(nivel[head[chain[u]]] > nivel[head[chain[v]]]) u = pai[head[chain[u]]];
		else v = pai[head[chain[v]]];
	}
	if(nivel[u] < nivel[v]) return u;
	return v;
}

void update(int u, int v){
	if(nivel[edge_input[u].first] < nivel[edge_input[u].second]) swap(edge_input[u].first, edge_input[u].second);
	edge[edge_input[u].first] = v, update_tree(1, 1, n, pos[edge_input[u].first], v);
}

int query_path(int u, int v){ // nivel[u] > nivel [v]
	int ans = 0;

	while(chain[u]!=chain[v]){
		ans = max(ans, query_tree(1, 1, n, pos[head[chain[u]]], pos[u]));
		u = pai[head[chain[u]]];
	}

    if(pos[u]==pos[v]) return ans;

	return ans = max(ans, query_tree(1, 1, n, pos[v]+1, pos[u]));
}

int query(int u, int v){
	int l = lca(u, v);
	return max(query_path(u, l), query_path(v, l));
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);

	    for(int i=1; i<n; i++){
	        int a, b, c;

	        scanf("%d %d %d", &a, &b, &c);

	        edge_input[i] = {a, b};

	        grafo[a].push_back({b, c});
	        grafo[b].push_back({a, c});
	    }

	    dfs(1, 0);

	    hld(1);

	    char s[10];

	    while(scanf("%s", &s)){
	    	if(s[0]=='D') break;

	    	int a, b;

	    	scanf("%d %d", &a, &b);

	    	if(s[0]=='C'){
	    		update(a, b);
	    	}
	    	else{
	    		printf("%d\n", query(a, b));
	    	}
	    }

	    for(int i=1; i<=n; i++) grafo[i].clear();

	    memset(tree, 0, sizeof tree);
	    memset(head, 0, sizeof head);

	    c = 0, qtd = 0;
	}

    return 0;
}
