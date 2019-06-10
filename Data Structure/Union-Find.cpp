// Union-Find
// O(alpha(n))

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+10;

int qtd[maxn], pai[maxn];

int acha(int x){
    if(pai[x]==x){
        return x;
    }
    return pai[x]=acha(pai[x]);
}

void une( int a, int b){
    a = acha(a), b = acha(b);

    if(a==b) return;

    if(qtd[a]<qtd[b])swap(a,b);

    qtd[a]+=qtd[b], pai[b]=a;
}
