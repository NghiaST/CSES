#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;
long long n, a, b, c, d, res;
 
long long power(long long x, long long k) {
    long long ans = 1;
    while (k > 0) {
        if (k & 1) (ans *= x) %= MOD;
        (x *= x) %= MOD;
        k >>= 1;
    }
    return ans;
}
 
int main()
{
    cin >> n;
    a = power(2, n*n);
    b = (n%2==0 ? power(2, n*n/4) : power(2, (n*n-1)/4) * 2 % MOD);
    c = (n%2==0 ? power(2, n*n/2) : power(2, (n*n-1)/2) * 2 % MOD);
    d = b;
    cout << (a + b + c + d) * 250000002 % MOD;
}
