#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 100005, K = 500005;
string str, s;
pair<string, int> ask[K];
int n, k, L[N], c[N], cn[N], p[N], pn[N], cnt[N], d[N][20], pmin[N][20];
int ans[K];
 
void Enter() {
    cin >> str; str += '@'; n = str.length();
    cin >> k;
    for(int i=1; i<=k; ++i) cin >> ask[i].first, ask[i].second = i;
    sort(ask+1, ask+k+1);
}
 
void Suffix() {
    for(int i=0; i<n; ++i) ++cnt[str[i]];
    for(int i=1; i<256; ++i) cnt[i] += cnt[i-1];
    for(int i=n-1; i>=0; --i) p[--cnt[str[i]]] = i;
    int classes = 1;
    for(int i=1; i<n; ++i) {
        if (str[p[i]] != str[p[i-1]]) ++classes;
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
        while (str[i + d] == str[j + d]) ++d;
        L[c[i]] = d--;
        if (d < 0) ++d;
    }
}
 
void RMQ() {
    for(int i=1; i<=n; ++i) d[i][0] = L[i], pmin[i][0] = p[i];
    for(int j=1; j<20; ++j)
    for(int i=1; i + (1<<(j-1)) <=n; ++i) {
        d[i][j] = min(d[i][j-1], d[i + (1<<(j-1))][j-1]);
        pmin[i][j] = min(pmin[i][j-1], pmin[i + (1<<(j-1))][j-1]);
    }
}
 
int getRMQ(int l, int r) {
    int Lg = log2(r - l + 1);
    return min(pmin[l][Lg], pmin[r - (1<<Lg) + 1][Lg]);
}
 
void Process() {
    for(int iTest=1, w=1; iTest<=k; ++iTest) {
        s = ask[iTest].first;
        bool ok = true;
        for(int i=0; i<s.length(); ++i) {
            while (w <= n && L[w+1] >= i && s[i] > str[i + p[w]]) ++w;
            if (w <= n && s[i] > str[i + p[w]]) {
                ++w;
                ok = false;
                break;
            }
            if (w > n || s[i] != str[i + p[w]]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            int i = w;
            for(int j=19; j>=0; --j)
                if (i < n && d[i+1][j] >= s.length()) i += 1<<j;
            ans[ask[iTest].second] = getRMQ(w, i) + 1;
        }
        else ans[ask[iTest].second] = -1;
    }
    for(int i=1; i<=k; ++i) cout << ans[i] << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Suffix();
    LCP();
    RMQ();
    Process();
}
