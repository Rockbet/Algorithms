// Color Update
// Time Complexity: O(n log n) amortized
//
// Leonardo Paes

#include <bits/stdc++.h>

using namespace std;

struct tfg{
    int l, r, v;

    tfg(int l = 0){
        this -> l = l;
    }

    tfg(int l, int r, int v){
        this -> l = l;
        this -> r = r;
        this -> v = v;
    }

    bool operator < (const tfg &a) const{
        return l < a.l;
    }
};

set<tfg> ranges;

vector<tfg> update(int l, int r, int v){ // [l, r)
    vector<tfg> ans;

    if(l >= r) return ans;

    auto it = ranges.lower_bound(l);

    if(it != ranges.begin()){
        it--;
        if(it -> r > l){
            auto aux = *it;
            ranges.erase(it);
            ranges.insert(tfg(aux.l, l, aux.v));
            ranges.insert(tfg(l, aux.r, aux.v));
        }
    }

    it = ranges.lower_bound(r);

    if(it != ranges.begin()){
        it--;
        if(it -> r > r){
            auto aux = *it;
            ranges.erase(it);
            ranges.insert(tfg(aux.l, r, aux.v));
            ranges.insert(tfg(r, aux.r, aux.v));
        }
    }

    for(it = ranges.lower_bound(l); it != ranges.end() and it -> l < r; it++){
        ans.push_back(*it);
    }

    ranges.erase(ranges.lower_bound(l), ranges.lower_bound(r));

    ranges.insert(tfg(l, r, v));

    return ans;
}
