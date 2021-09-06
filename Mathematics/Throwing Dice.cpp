#include <iostream>
using namespace std;
const int MOD = 1e9 + 7, G[6] = {16,8,4,2,1,1};
long long n, res, f[1005];
struct matrix{
    long long x[6][6];
    matrix operator * (const matrix &p) {
        matrix C;
        for(int i=0; i<6; ++i)
        for(int j=0; j<6; ++j) {
            C.x[i][j] = 0;
            for(int w=0; w<6; ++w) C.x[i][j] = (C.x[i][j] + x[i][w] * p.x[w][j]) % MOD;
        }
        return C;
    }
} root;
 
matrix get(long long w) {
    if (w == 1) return root;
    matrix p = get(w / 2);
    p = p * p;
    if (w&1) p = p * root;
    return p;
}
 
int main()
{
    root.x[0][0] = 1;
    for(int i=1; i<6; ++i) root.x[0][i] = root.x[i][i-1] = 1;
    cin >> n;
    if (n<6) cout << G[5-n];
    else {
        matrix ans = get(n-5);
        for(int i=0; i<6; ++i) res = (res + ans.x[0][i] * G[i]) % MOD;
        cout << res;
    }
}
