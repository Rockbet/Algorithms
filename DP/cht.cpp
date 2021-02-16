/*
  From: Simon Lindholm
  Description: Container where you can add lines of the form kx+m, and query maximum values at points x.
  Useful for dynamic programming (``convex hull trick'').
  Time: O(\log N)
  Status: stress-tested
  Leonardo Paes
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Line {
	mutable ll p, k, m;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(const ll&x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = numeric_limits<ll>::max();
	ll div(ll a, ll b) { // floored division
        return a / b - ((a<0 ^ b<0) < 0 && a % b);
    }
	bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
        isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};
