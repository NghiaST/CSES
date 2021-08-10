#include <iostream>
using namespace std;
int n, res1, res2, z[1000005], z2[1000005];
string s;
 
int main()
{
    getline(cin, s);
    n = s.length();
    for(int i=0, l=0, r=-1; i<n; ++i) {
        if (i <= r) z[i] = min(r-i+1, z[l + r - i]);
        while (i + z[i] < n && i - z[i] >= 0 && s[i + z[i]] == s[i - z[i]]) ++z[i];
        if (i + z[i] > r) l = i - z[i] + 1, r = i + z[i] - 1;
        if (z[res1] < z[i]) res1 = i;
    }
    for(int i=1, l=0, r=-1; i<n; ++i) {
        if (i <= r) z2[i] = min(r-i, z2[l + r - i]);
        while (i + z2[i] < n && i - z2[i] - 1 >= 0 && s[i + z2[i]] == s[i - z2[i] - 1]) ++z2[i];
        if (i + z2[i] > r) l = i - z2[i], r = i + z2[i] - 1;
        if (z2[res2] < z2[i]) res2 = i;
    }
    if (z[res1] * 2 - 1 > z2[res2] * 2) {
        for(int i = res1 - z[res1] + 1; i < res1 + z[res1]; ++i) cout << s[i];
    }
    else {
        for(int i = res2 - z2[res2]; i < res2 + z2[res2]; ++i) cout << s[i];
    }
}
