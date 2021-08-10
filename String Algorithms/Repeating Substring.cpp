#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100005;
string s;
int n, k, res, L[N], c[N], cn[N], p[N], pn[N], cnt[N];
 
void Suffix() {
    for(int i=0; i<n; ++i) ++cnt[s[i]];
    for(int i=1; i<256; ++i) cnt[i] += cnt[i-1];
    for(int i=n-1; i>=0; --i) p[--cnt[s[i]]] = i;
    int classes = 1;
    for(int i=1; i<n; ++i) {
        if (s[p[i]] != s[p[i-1]]) ++classes;
        c[p[i]] = classes - 1;
    }
    fill(cnt, cnt + 256, 0);
    for(int h=1; h<n && classes<n; h<<=1) {
        for(int i=0; i<n; ++i) {
            pn[i] = p[i] - h;
            if (pn[i] < 0) pn[i] += n;
        }
        fill(cnt, cnt + classes, 0);
        for(int i=0; i<n; ++i) ++cnt[c[pn[i]]];
        for(int i=1; i<classes; ++i) cnt[i] += cnt[i-1];
        for(int i=n-1; i>=0; --i) p[--cnt[c[pn[i]]]] = pn[i];
        classes = 1;
        for(int i=1; i<n; ++i) {
            pair<int,int> x1 = make_pair(c[p[i]], c[(p[i] + h) % n]);
            pair<int,int> x2 = make_pair(c[p[i-1]], c[(p[i-1] + h) % n]);
            if (x1 != x2) ++classes;
            cn[p[i]] = classes - 1;
        }
        for(int i=0; i<n; ++i) c[i] = cn[i];
    }
}
 
void LCP() {
    for(int i=0, d=0; i<n-1; ++i) {
        int j = p[c[i] - 1];
        while (s[i + d] == s[j + d]) ++d;
        L[c[i]] = d--;
        if (d < 0) ++d;
    }
}
 
void Process() {
    for(int i=1; i<n; ++i) if (L[res] < L[i]) res = i;
    if (L[res] < 2) cout << -1;
    else cout << s.substr(p[res], L[res]);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> s; s += '@'; n = s.length();
    Suffix();
    LCP();
    Process();
}
