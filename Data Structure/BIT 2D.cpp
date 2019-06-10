// Binary Indexed Tree 2D
// Sum: O(log n * log m)
// Update: O(log n * log m)

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+10, maxm = 1e3+10;

int n, m, tree[maxn][maxm];

void update(int x, int y, int k){
    for(int i=x; i<maxn; i+=(i&-i))
        for(int j=y; j<maxm; j+=(j&-j))
            tree[i][j]+=k;
}

int sum(int x, int y){
    int s = 0;
    for(int i=x; i>0; i-=(i&-i))
        for(int j=y; j>0; j-=(j&-j))
            s += tree[i][j];
    return s;
}
