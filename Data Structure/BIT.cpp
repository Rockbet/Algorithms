// Binary Indexed Tree
// Update: O(log n)
// Sum: O(log n)

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6+10;
struct bit{
    int tree[maxn] = {};
    void update(int x, int v){
        for(; x<maxn; x+=(x&-x)) tree[x] += v;
    }
    int query(int x){
        int ans = 0;
        for(; x>0; x-=(x&-x)) ans += tree[x];
        return ans;
    }
    int query(int x, int y){
        return query(y) - query(x-1);
    }
};
