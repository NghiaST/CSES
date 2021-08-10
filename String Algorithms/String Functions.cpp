#include <iostream>
using namespace std;
string s;
int n, z[1000005], kmp[1000005];
 
int main()
{
    getline(cin, s);
    n = s.length();
    for(int i=1, l=0, r=-1; i<n; ++i) {
        if (i <= r) z[i] = min(z[i-l], r-i+1);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] > r) l = i, r = i + z[i] - 1;
    }
    kmp[0] = -1;
    for(int i=1; i<n; ++i) {
        kmp[i] = -1;
        for(int j=kmp[i-1]; j!=-1; j=kmp[j]) {
            if (s[i] == s[j+1]) {
                kmp[i] = j;
                break;
            }
        }
        if (s[i] == s[kmp[i]+1]) ++kmp[i];
    }
    for(int i=0; i<n; ++i) cout << z[i] << ' ';
    cout << '\n';
    for(int i=0; i<n; ++i) cout << kmp[i] + 1 << ' ';
}
