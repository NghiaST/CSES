#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long n, res = 1, x = 2;
    cin >> n;
    while (n) {
        if (n&1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    cout << res;
}
