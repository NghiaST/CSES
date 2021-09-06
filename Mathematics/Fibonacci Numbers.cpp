#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;
long long n;
struct matrix{
    long long x[2][2];
    matrix operator * (const matrix &p) {
        matrix C;
        for(int i=0; i<2; ++i)
        for(int j=0; j<2; ++j) {
            C.x[i][j] = 0;
            for(int w=0; w<2; ++w) C.x[i][j] = (C.x[i][j] + x[i][w] * p.x[w][j]) % MOD;
        }
        return C;
    }
};
 
matrix get(long long w) {
    if (w == 1) return {{1,1,1,0}};
    matrix p = get(w / 2);
    p = p * p;
    if (w&1) p = p * (matrix){{1,1,1,0}};
    return p;
}
 
int main()
{
    cin >> n;
    if (n<=1) cout << n;
    else cout << get(n-1).x[0][0];
}
