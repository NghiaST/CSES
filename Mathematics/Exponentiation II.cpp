#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;
long long t, a, b, c;
 
long long power(long long x, long long k, long long MOD) {
    long long w = 1;
    while (k) {
        if (k&1) w = w*x%MOD;
        k>>=1;
        x=x*x%MOD;
    }
    return w;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        cout << power(a, power(b, c, MOD - 1), MOD) << '\n';
    }
}
