// Binary Indexed Tree
// Update: O(log n)
// Sum: O(log n)

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int n, tree[maxn];

void update(int x, int k){
    while(x<=n){
        tree[x]+=k;
        x+=(x&-x);
    }
}

int sum(int x){

    int s = 0;

    while(x>0){
        s+=tree[x];
        x-=(x&-x);
    }

    return s;
}

int main(){

    return 0;
}

