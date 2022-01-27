// Fast Kuhn
// O(magic)
// Solution to https://judge.yosupo.jp/submission/75960
// Leonardo Paes 
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

vector<int> grafo[maxn];
int matchA[maxn], matchB[maxn];
bool mark[maxn];

bool kuhn(int u){
	for(int v : grafo[u]){
		if(mark[v]) continue;
		mark[v] = 1;
		if(matchB[v] == -1 or kuhn(matchB[v])){
			matchA[u] = v;
			matchB[v] = u;
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int l, r, m;
	cin >> l >> r >> m;
	for(int i=0; i<m; i++){
		int u, v;
		cin >> u >> v;
		grafo[u].push_back(v);
	}
	for(int i=0; i<l; i++) matchA[i] = -1;
	for(int i=0; i<r; i++) matchB[i] = -1;	
	bool aux = true;
	int ans = 0;
	while(aux){
		for(int i=0; i<r; i++) mark[i] = 0;
		aux = false;
		for(int i=0; i<l; i++){
			if(matchA[i] != -1) continue;
			if(kuhn(i)){
				ans++;
				aux = true;
			}
		}
	}
	cout << ans << "\n";
	for(int i=0; i<l; i++) if(~matchA[i]) cout << i << " " << matchA[i] << "\n";
	return 0;
}
