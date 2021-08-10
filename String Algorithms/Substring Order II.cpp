#include <iostream>
#include <cstring>
using namespace std;
const int N = 100005;
int n, cnt[N], c[N], cn[N], p[N], pn[N], L[N][20];
long long f[N], k;
string s;
 
void Enter() {
    cin >> s >> k;
    s += '@';
    n = s.length();
}
 
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
        copy(cn, cn + n, c);
    }
}
 
void LCP() {
    for(int i=0, d=0; i<n-1; ++i) {
        int j = p[c[i] - 1];
        while (s[i + d] == s[j + d]) ++d;
        L[c[i]][0] = d--;
        if (d < 0) ++d;
    }
}
 
void Init() {
    for(int j=1; j<20; ++j)
    for(int i=0; i + (1<<(j-1)) < n; ++i)
        L[i][j] = min(L[i][j-1], L[i + (1<<(j-1))][j-1]);
 
    for(int i=1; i<n; ++i)
        f[i] = f[i-1] + (n - p[i] - 1);
}
 
int get_same(int i, int len) {
    ++i;
    for(int j=19; j>=0; --j)
    if (L[i][j] >= len)
        i += (1<<j);
    return --i;
}
 
void Process() {
    long long i = 1, len = 0;
    while (k > 0) {
        ++len;
        while (f[i] - f[i-1] < len) ++i;
        int j = get_same(i, len);
        if (f[j] - f[i-1] - (len-1) * (j-i+1) < k) {
            k -= f[j] - f[i-1] - (len-1) * (j-i+1);
            i = j+1;
            --len;
        }
        else k -= j - i + 1;
    }
    cout << s.substr(p[i], len) << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Suffix();
    LCP();
    Init();
    /*for(int i=1; i<=n*(n-1)/2; ++i) k=i, Process();*/
    Process();
}
