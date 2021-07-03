#include <iostream>
#include <cstring>
using namespace std;
string s;
int pp, cnt[256];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> s;
    for(int i=0; i<s.length(); ++i) ++cnt[s[i]];
    for(int i='A'; i<='Z'; ++i) pp += (cnt[i] & 1);
    if (pp > 1) cout << "NO SOLUTION";
    else {
        for(int i='A'; i<='Z'; ++i)
            for(int j=1; j*2<=cnt[i]; ++j) cout << (char) i;
        for(int i='A'; i<='Z'; ++i)
            if (cnt[i] & 1) cout << (char) i;
        for(int i='Z'; i>='A'; --i)
            for(int j=1; j*2<=cnt[i]; ++j) cout << (char) i;
    }
}
