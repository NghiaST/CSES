#include <iostream>
#include <cstring>
using namespace std;
string s, s2;
int n, n2, res, z[1000005];
 
int main()
{
    getline(cin, s2); n2 = s2.length();
    getline(cin, s); n = s.length();
    for(int i=1, l=0, r=-1; i<n; ++i) {
        if (i <= r) z[i] = min(r-i+1, z[i-l]);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) ++z[i];
        if (i + z[i] > r) l = i, r = i + z[i] - 1;
    }
    for(int i=0, l=0, r=-1; i<n2; ++i) {
        int w = 0;
        if (i <= r) w = min(r-i+1, z[i-l]);
        while (i + w < n2 && w < n && s2[i + w] == s[w]) ++w;
        if (i + w > r) l = i, r = i + w - 1;
        if (w == n) ++res;
    }
    cout << res;
}
