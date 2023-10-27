// Xor Trie
// Leonardo Paes
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxl = 40;
class Trie{
public:
    Trie(){ b[0] = b[1] = nullptr; }
    void add(ll x){
        Trie* cur = this;
        for(int i=maxl; i>=0; i--){
            bool bit = ((1LL << i) & x);
            if(!cur->b[bit]) cur->b[bit] = new Trie();
            cur = cur->b[bit];
        }
    }
    ll mx(ll x){
        Trie* cur = this;
        ll ans = 0;
        for(int i=maxl; i>=0; i--){
            bool bit = ((1LL << i) & x);
            if(cur->b[!bit]){
                ans += (1LL << i);
                cur = cur->b[!bit];
            }
            else if(cur->b[bit]) cur = cur->b[bit];
            else return -1;
        }
        return ans;
    }
private:
    Trie* b[2];
}root;
