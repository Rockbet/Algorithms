#include<bits/stdc++.h>
using namespace std;
// Solution to https://judge.yosupo.jp/problem/enumerate_palindromes
class Manacher{
public:
    Manacher(string &s){
        ms = "$";
        for(char c : s){
            ms += "#" + string(1, c);
        }
        ms += "#^";
        computeP();
    }

    void computeP(){
        int n = ms.size();
        p.resize(n, 0);
        int c = 2, r = 0;
        for(int i=2; i<n-2; i++){
            if(i < r){
                p[i] = min(r - i, p[c - (i - c)]);
            }
            while(ms[i + p[i] + 1] == ms[i - p[i] - 1]){
                p[i]++;
            }
            if(i + p[i] > r){
                c = i;
                r = i + p[i];
            }
        }
    }

    vector<int> getP(){
        return p;
    }

    bool isPalindrome(int l, int r){
        int len = r - l + 1;
        int c = (l + r) / 2;
        return getLongest(c, len & 1);
    }

    // odd-lengthed centered at c VS even-lengthed with left center at c
    int getLongest(int c, bool odd){
        return p[2 + 2 * c + !odd];
    }
private:
    string ms;
    vector<int> p;
};

int main(){
    string s;
    cin >> s;
    Manacher m(s);
    vector<int> p = m.getP();
    for(int i=2; i<p.size() - 2; i++) cout << p[i] << " ";
}
