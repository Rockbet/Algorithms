// Merge Sort Tree
// Query: O(log^2)
//
// Solution to https://www.spoj.com/problems/KQUERYO/

#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 3e4+10;
 
int n, q, vet[maxn], lastans;
 
vector<int> tree[4*maxn];
 
void build(int node, int l, int r){
    if(l==r){
        tree[node].push_back(vet[l]);
        return;
    }
 
    int mid = (l+r) >> 1;
 
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
 
    tree[node].resize(tree[2*node].size() + tree[2*node+1].size());
 
    int i = 0, j = 0, k = 0;
 
    while(k < tree[node].size()){
        if(i < tree[2*node].size() and j < tree[2*node+1].size()){
            if(tree[2*node][i] < tree[2*node+1][j]){
                tree[node][k] = tree[2*node][i];
                i++, k++;
            }
            else{
                tree[node][k] = tree[2*node+1][j];
                j++, k++;
            }
        }
        else if(i < tree[2*node].size()){
            tree[node][k] = tree[2*node][i];
            i++, k++;
        }
        else{
            tree[node][k] = tree[2*node+1][j];
            j++, k++;
        }
    }
}
 
int query(int node, int tl, int tr, int l, int r, int k){
    if(tl > r or tr < l) return 0;
    if(tl >= l and tr <= r){
        return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
    }
 
    int mid = (tl + tr) >> 1;
 
    return query(2*node, tl, mid, l, r, k) + query(2*node+1, mid+1, tr, l, r, k);
}
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
    cin >> n;
 
    for(int i=1; i<=n; i++){
        cin >> vet[i];
    }
 
    build(1, 1, n);
 
    cin >> q;
 
    while(q--){
        int a, b, c, i, j, k;
 
        cin >> a >> b >> c;
 
        i = a ^ lastans, j = b ^ lastans, k = c ^ lastans;
 
        lastans = query(1, 1, n, i, j, k);
 
        cout << lastans << endl;
    }
 
    return 0;
}
