// Digit DP
// Time Complexity: O(d) 
// Leonardo Paes

#include <bits/stdc++.h>
using namespace std;
const int maxd = 10;
vector<int> num; // d0, d1, ... dn. num.size() == n+1
int dp[maxd][2];
int solve(int d, bool flag){ // 0 == ?, 1 == garantido <= b
    if(d == num.size()) return 1;
    if(dp[d][flag] != -1) return dp[d][flag];
    int tot = 0;
    if(flag){// 0, 1, 2, 3, ..., 9 == 10
        for(int i=0; i<10; i++){
            tot += solve(d+1, flag);
        }
    }
    else{// 0, 1, 2, ..., num[d]
        for(int i=0; i<num[d]; i++){
            tot += solve(d+1, 1);
        }
        tot += solve(d+1, 0);
    }
    return dp[d][flag] = tot;
}
int calc(int x){
    num.clear();
    while(x){ // enquanto x diff de 0
        num.push_back(x%10);
        x /= 10;
    }
    reverse(num.begin(), num.end());
    // te amo muito Pietra
    memset(dp, -1, sizeof dp);
    return solve(0, 0);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    cout << calc(b) - calc(a-1) << "\n";
	return 0;
}
