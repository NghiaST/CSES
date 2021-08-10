#include <iostream>
using namespace std;
const int N = 1000005;
string s;
int n, cnt[N], p[N], pn[N], c[N], cn[N];
 
void SuffixArray() {
    int classes = 1;
    for(int i=0; i<n; ++i) ++cnt[s[i]];
    for(int i=1; i<256; ++i) cnt[i] += cnt[i-1];
    for(int i=n-1; i>=0; --i) p[--cnt[s[i]]] = i;
    for(int i=1; i<n; ++i) {
        if (s[p[i]] != s[p[i-1]]) ++classes;
        c[p[i]] = classes - 1;
    }
    fill(cnt, cnt+256, 0);
    for(int h=1; h<n && classes<n; h<<=1) {
        for(int i=0; i<n; ++i) {
            pn[i] = p[i] - h;
            if (pn[i] < 0) pn[i] += n;
        }
        fill(cnt, cnt+classes, 0);
        for(int i=0; i<n; ++i) ++cnt[c[pn[i]]];
        for(int i=1; i<classes; ++i) cnt[i] += cnt[i-1];
        for(int i=n-1; i>=0; --i) p[--cnt[c[pn[i]]]] = pn[i];
        classes = 1;
        cn[p[0]] = 0;
        for(int i=1; i<n; ++i) {
            pair<int,int> x1 = make_pair(c[p[i]], c[(p[i] +h) % n]);
            pair<int,int> x2 = make_pair(c[p[i-1]], c[(p[i]+h-1) % n]);
            if (x1 != x2) ++classes;
            cn[p[i]] = classes - 1;
        }
        for(int i=0; i<n; ++i) c[i] = cn[i];
    }
}
 
int main()
{
    getline(cin, s); n = s.length();
    SuffixArray();
    for(int i=p[0]; i<n; ++i) cout << s[i];
    for(int i=0; i<p[0]; ++i) cout << s[i];
}
