#include <iostream>
using namespace std;
const int N = 1000005, MOD = 1e9 + 7;
string s;
long long f[N], f2[N], f3[N], c[26];
 
int main()
{
    f[0] = f[1] = f2[0] = f2[1] = f3[0] = f3[1] = 1;
    for(int i=2; i<=1000000; ++i) {
        f[i] = f[i-1] * i % MOD;
        f2[i] = MOD - MOD / i * f2[MOD % i] % MOD;
        f3[i] = f3[i-1] * f2[i] % MOD;
    }
    getline(cin, s);
    for(int i=0; i<s.length(); ++i) ++c[s[i] - 'a'];
    long long res = f[s.length()];
    for(int i=0; i<26; ++i) res = res * f3[c[i]] % MOD;
    cout << res;
}
