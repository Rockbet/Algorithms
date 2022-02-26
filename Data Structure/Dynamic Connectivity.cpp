// Dynamic Connectivity
// O(q log n log q)
// Solution to: https://codeforces.com/gym/100551/problem/A
// Leonardo Paes

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f first
#define s second
const int maxn = 3e5+10;

struct edge{
	int l, r, u, v;
	edge(){ l = r = u = v = 0; }
	edge(int l, int r, int u, int v){
		this -> l = l;
		this -> r = r;
		this -> u = u;
		this -> v = v;
	}
};

int n, q;
vector<edge> e;
map<pii,int> m;
bool query[maxn];

class DSU{
private:
	int pai[maxn], sz[maxn], cc;
	stack<pii> s;
public:
	void init(int n){
		for(int i=1; i<=n; i++) pai[i] = i, sz[i] = 1; cc = n; 
	}
	int find(int x){ return pai[x] == x ? x : find(pai[x]); }
	void join(int a, int b){
		a = find(a), b = find(b);
		if(a == b){
			s.push({0, 0});
			return;
		}
		if(sz[a] > sz[b]) swap(a, b);
		cc--;
		pai[a] = b;
		sz[b] += sz[a];
		s.push({a, b});
	}
	void rollback(){
		int a = s.top().f, b = s.top().s;
		s.pop();
		if(a) cc++;
		pai[a] = a;
		sz[b] -= sz[a];
	}
	int query(){ return cc; }
}dsu;

class SEG{
private:
	vector<pii> tree[1<<20];
public:
	void update(int node, int tl, int tr, edge x){
		if(tl > x.r or tr < x.l) return;
		if(tl >= x.l and tr <= x.r){
			tree[node].push_back({x.u, x.v});
			return;
		}
		int mid = (tl + tr) >> 1;
		update(2*node, tl, mid, x), update(2*node+1, mid+1, tr, x);
	}
	void solve(int node, int tl, int tr){
		for(pii x : tree[node]) dsu.join(x.f, x.s);
		if(tl == tr){ if(query[tl]) cout << dsu.query() << "\n"; }
		else{
			int mid = (tl + tr) >> 1l;
			solve(2*node, tl, mid); solve(2*node+1, mid+1, tr);
		}
		for(pii x : tree[node]) dsu.rollback();
	}
}seg;

int main(){
	freopen("connect.in", "r", stdin);
	freopen("connect.out", "w", stdout);
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> q;
	dsu.init(n);
	for(int i=1; i<=q; i++){
		char op;
		cin >> op;
		if(op == '?'){
			query[i] = 1;
			continue;
		}
		int u, v;
		cin >> u >> v;
		if(u > v) swap(u, v);
		pii x = {u, v};
		if(m.count(x)){
			e.push_back(edge(m[x], i, u, v));
			m.erase(x);
		}
		else m[x] = i;
	}
	q++;
	for(auto x : m) e.push_back(edge(x.s, q, x.f.f, x.f.s));
	for(auto x : e) seg.update(1, 1, q, x);
	seg.solve(1, 1, q);
	return 0;
}
