// Struct for Point in 2D Geometry by Leonardo Paes 
#include <bits/stdc++.h>
using namespace std;
struct pt{
    typedef long long ll;
    ll x, y;
    pt(){ x = 0LL, y = 0LL; }
    pt(ll x, ll y){ this->x = x, this->y = y; }
    pt operator +(const pt &p) const{ return pt(x+p.x, y+p.y); }
    pt operator -(const pt &p) const{ return pt(x-p.x, y-p.y); }
    pt operator *(ll v)        const{ return pt(x*v, y*v);     }
    ll operator *(const pt &p) const{ return x*p.x + y*p.y;    } // dot product
    ll operator %(const pt &p) const{ return x*p.y - y*p.x;    } // cross product
    bool operator <(const pt &p) const{ return (x == p.x ? y < p.y : x < p.x); }
    bool operator ==(const pt &p) const{ return (x == p.x and y == p.y); }
};
