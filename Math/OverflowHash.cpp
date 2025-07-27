typedef unsigned long long ull;
constexpr ull p = 10133, pinv = 9118695456943762365;

vector<ull> pot(n+1), potInv(n+1);
pot[0] = potInv[0] = 1;
for(int i=1; i<=n; i++){
    pot[i] = pot[i-1] * p;
    potInv[i] = potInv[i-1] * pinv;
}
