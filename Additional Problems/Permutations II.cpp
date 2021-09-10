/// A002464 - OEIS
#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;
long long n, a[1005];
int main()
{
    cin >> n;
    a[0] = a[1] = 1;
    for(int i=4; i<=n; ++i) a[i] = ((i+1) * a[i-1] - (i-2) * a[i-2] - (i-5) * a[i-3] + (i-3) * a[i-4]) % MOD;
    cout << (a[n] + MOD) % MOD;
}
