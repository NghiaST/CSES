#include <iostream>
using namespace std;
string s, s2;
int n, res, z[1000005], f[1000005];
 
int main()
{
    getline(cin, s); n = s.length();
    for(int i=1, l=0, r=-1; i<n; ++i) {
        if (i <= r) z[i] = min(r-i+1, z[i-l]);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) ++z[i];
        if (i + z[i] > r) l = i, r = i + z[i] - 1;
        if (i + z[i] == n) f[++res] = z[i];
    }
    while (res) cout << f[res--] << ' ';
}
