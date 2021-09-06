#include <iostream>
using namespace std;
int n, cnt[256], p[1000005];
string s;
 
int main()
{
    getline(cin, s);
    n = s.length();
 
    for(int i=0; i<n; ++i) ++cnt[s[i]];
    for(int i=1; i<256; ++i) cnt[i] += cnt[i-1];
    for(int i=n-1; i>=0; --i) p[--cnt[s[i]]] = i;
    for(int i=p[0], dem=1; dem<n; ++dem) {
        i = p[i];
        putchar(s[i]);
    }
}
