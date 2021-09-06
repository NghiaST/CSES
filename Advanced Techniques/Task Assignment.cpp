#include <iostream>
using namespace std;
const int N = 205, INF = 0x3c3c3c3c;
int n, cnt, ans, a[N][N], row[N], column[N], asR[N], asC[N], avail[N], assigned[N];
 
void Enter() {
    cin >> n;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j) cin >> a[i][j];
}
 
bool Match(int u) {
    avail[u] = cnt;
    for(int v=1; v<=n; ++v) if (!assigned[v] && !a[u][v]) {
        assigned[v] = u;
        asR[u] = v;
        return true;
    }
    for(int v=1; v<=n; ++v) if (!a[u][v]) {
        if (avail[assigned[v]] != cnt && Match(assigned[v])) {
            assigned[v] = u;
            asR[u] = v;
            return true;
        }
    }
    return false;
}
 
bool Matching() {
    cnt = 0;
    fill(asR+1, asR+n+1, 0);
    fill(asC+1, asC+n+1, 0);
    fill(assigned+1, assigned+n+1, 0);
    fill(avail+1, avail+n+1, 0);
    for(int i=1; i<=n; ++i) //if (!asR[i])
        ++cnt, Match(i);
    for(int i=1; i<=n; ++i) if (!asR[i])
    for(int j=1; j<=n; ++j) if (!a[i][j])
        asC[j] = 1;
    for(int i=1; i<=n; ++i) if (!asR[i])
        return false;
    return true;
}
 
void Process() {
    int val = INF;
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j)
        val = min(val, a[i][j]);
    for(int i=1; i<=n; ++i)
        row[i] += val;
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j)
        a[i][j] -= val;
    while (!Matching()) {
        val = INF;
        for(int i=1; i<=n; ++i) if (!asR[i])
        for(int j=1; j<=n; ++j) if (!asC[j])
            val = min(val, a[i][j]);
        for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j) {
            if (!asR[i]) a[i][j] -= val;
            if (asC[j]) a[i][j] += val;
        }
        for(int i=1; i<=n; ++i) {
            if (!asR[i]) row[i] += val;
            if (asC[i]) column[i] -= val;
        }
    }
}
 
void Print() {
    for(int i=1; i<=n; ++i) ans += row[i] + column[asR[i]];
    cout << ans << '\n';
    for(int i=1; i<=n; ++i) cout << i << ' ' << asR[i] << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
    Print();
}
