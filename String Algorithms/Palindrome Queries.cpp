#include <iostream>
#define LL long long
using namespace std;
const LL N = 200005, MOD = 998244353, base = 123;
LL n, q, it1[N*4], it2[N*4], power1[N], power2[N];
char s[N];
 
void update(int l, int r, int x, int pos) {
    if (l == r) {
        it1[pos] = (s[l] - 'a' + 1) * power1[l] % MOD;
        it2[pos] = (s[l] - 'a' + 1) * power2[l] % MOD;
        return;
    }
    int mid = (l+r) / 2;
    if (x <= mid) update(l, mid, x, pos*2);
    else update(mid+1, r, x, pos*2+1);
    it1[pos] = it1[pos*2] + it1[pos*2+1];
    it2[pos] = it2[pos*2] + it2[pos*2+1];
}
 
void Setup() {
    power1[0] = 1;
    for(int i=1; i<=n; ++i) power1[i] = power1[i-1] * base % MOD;
    for(int i=0; i<=n; ++i) power2[i+1] = power1[n-i];
    for(int i=1; i<=n; ++i) update(1, n, i, 1);
}
 
pair<LL, LL> query(int l, int r, int x, int y, int pos) {
    if (l > y || r < x) return {0,0};
    if (x <= l && r <= y) return {it1[pos], it2[pos]};
    int mid = (l+r) / 2;
    pair<LL, LL> w1 = query(l, mid, x, y, pos*2);
    pair<LL, LL> w2 = query(mid+1, r, x, y, pos*2+1);
    return {(w1.first + w2.first) % MOD, (w1.second + w2.second) % MOD};
}
 
void Process() {
    int type, x, y;
    while (q--) {
        cin >> type >> x;
        if (type == 1) {
            cin >> s[x];
            update(1, n, x, 1);
        }
        else {
            cin >> y;
            pair<LL, LL> w = query(1, n, x, y, 1);
            (w.first *= power2[x]) %= MOD;
            (w.second *= power1[y]) %= MOD;
            cout << (w.first == w.second ? "YES\n" : "NO\n");
        }
    }
 
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q >> s + 1;
    Setup();
    Process();
}
