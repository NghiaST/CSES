#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=(l); i<=(r); ++i)
#define REP(i,l,r) for(int i=(l); i<(r); ++i)
#define FORD(i,r,l) for(int i=(r); i>=(l); --i)
#define REPD(i,r,l) for(int i=(r)-1; i>=(l); --i)
using namespace std;
const int N = 2e5 + 5;
int n, q, a[N], a2[N], pos[N], qx[N], qy[N];
long long bit[N], ans[N];
vector<int> Q[N];

void Enter() {
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, q) cin >> qx[i] >> qy[i];
}

void update(int x, int val) {
    for(; x <= n; x += x&-x) bit[x] += val;
}

long long query(int x) {
    long long val = 0;
    for(; x; x -= x&-x) val += bit[x];
    return val;
}

void Process() {
    FOR(i, 1, n) pos[i] = i;
    sort(pos + 1, pos + n + 1, [] (int x, int y) { return a[x] < a[y]; });
    FOR(i, 1, n) a2[i] = a[pos[i]];
    FOR(i, 1, q) Q[0].push_back(i);
    FOR(i, 0, n) {
        if (i) update(pos[i], a2[i]);
        for(int v : Q[i]) {
            ans[v] = query(qy[v]) - query(qx[v] - 1) + 1;
            int p = upper_bound(a2 + 1, a2 + n + 1, ans[v]) - a2 - 1;
            if (p > i) Q[p].push_back(v);
        }
    }
    FOR(i, 1, q) cout << ans[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
