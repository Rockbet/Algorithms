// Struct for Matrix Expo by Leonardo Paes 
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll mod = 1e9+7;
struct matrix{
    int n, m;
    vector<vector<ll>> v;
    matrix(){};
    matrix(int l, int c){
        n = l;
        m = c;
        v.resize(n, vector<ll>(m));
    }
};
matrix operator*(const matrix &a, const matrix &b){
    matrix ans(a.n, b.m);
    for(int i=0; i<a.n; i++){
        for(int j=0; j<b.m; j++){
            for(int k=0; k<a.m; k++){
                ans.v[i][j] = (ans.v[i][j] + (a.v[i][k] * b.v[k][j])%mod)%mod;
            }
        }
    }
    return ans;
}
matrix expo(matrix a, ll b){
    matrix ans(a.n, a.m);
    for(int i=0; i<a.n; i++) ans.v[i][i] = 1;
    while(b){
        if(b&1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}
