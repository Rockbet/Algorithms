#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define x first
#define y second
#define ar array
const int maxn = 5210, mod = 998244353;
ll nck[maxn][maxn];
ll pot(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}
ll inv(ll a){ return pot(a, mod-2); }
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    nck[0][0] = 1;
    for(int i=1; i<maxn; i++){
        for(int j=0; j<=i; j++){
            nck[i][j] = (nck[i-1][j] + (j == 0 ? 0 : nck[i-1][j-1]))%mod;
        }
    }
    return 0;
}
