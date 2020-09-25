// Codeforces - 959F
// Leonardo Paes
//
// Implementation of Gaussian Xor Elimination
//
// Build O(n log n)
// Query O(log n)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10, maxl = 20, mod = 1e9+7;
int v[maxn], b[maxn][maxl], qtdb[maxn];
ll power(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> v[i];
    memset(b, -1, sizeof b);
    qtdb[0] = 0;
    for(int i=1; i<=n; i++){ // create basis for online queries
        for(int j=0; j<maxl; j++) b[i][j] = b[i-1][j];
        qtdb[i] = qtdb[i-1];
        for(int j=maxl-1; j>=0; j--){
            if(!(v[i]&(1<<j))) continue;
            if(b[i][j] == -1){
                b[i][j] = v[i];
                qtdb[i]++;
            }
            v[i] ^= b[i][j];
        }
    }
    while(q--){
        int l, x;
        cin >> l >> x;
        for(int j=maxl-1; j>=0; j--){ // checking if it is possible to get x
            if(!(x&(1<<j))) continue;
            if(b[l][j] == -1) break;
            x ^= b[l][j];
        }
        if(!x) cout << power(2, l - qtdb[l]) << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}
