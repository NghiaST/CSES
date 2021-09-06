#include <iostream>
#include <map>
#include <ctime>
#define pii pair<long long, long long>
using namespace std;
map<pii, long long> Map;
const long long MOD = 998244353, base = 987654321, base2 = 123456789;
long long res, p[256], c[256], exist[256];
string s;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    srand(time(NULL));
    for(int i='a'; i<='z'; ++i) p[i] = rand() % MOD;
    cin >> s;
    ++Map[{0,0}];
    for(int i=0; i<s.length(); ++i) exist[s[i]] = 1;
    for(int i=0; i<s.length(); ++i) {
        ++c[s[i]];
        long long maxi = 0;
        for(int j='a'; j<='z'; ++j) if (exist[j]) maxi = max(maxi, c[j]);
        for(int j='a'; j<='z'; ++j) if (exist[j]) c[j] -= maxi;
        long long x = 0, x2 = 0;
        for(int j='a'; j<='z'; ++j) if (exist[j]) {
            x = (x * base + c[j] * p[j]) % MOD;
            x2 = (x2 * base2 + c[j] * p[j]) % MOD;
        }
        res += Map[{x, x2}]++;
    }
    cout << res;
}
