#include <iostream>
#include <queue>
using namespace std;
const int N = 1e5 + 5, MOD = 123456789, MOD2 = 987654321;
int n, m;
long long f[N], avail[N];
pair<int,int> cnt[N], cnt2[N];
vector<pair<int,int>> S[N];
vector<int> S2[N], S3[N], Ans;
 
void Dijkstra() {
    #define pii pair<long long, int>
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    fill(f+2, f+n+1, 1e15);
    Q.emplace(0, 1);
    while (!Q.empty()) {
        auto [cost, u] = Q.top(); Q.pop();
        if (cost != f[u]) continue;
        for(auto [v, c] : S[u]) {
            if (f[v] > cost + c) {
                f[v] = cost + c;
                Q.emplace(f[v], v);
            }
        }
    }
}
 
pair<int,int> DFS(int u) {
    avail[u] = 1;
    for(int v : S3[u]) {
        if (avail[v] != 1)
            DFS(v);
        (cnt[u].first += cnt[v].first) %= MOD;
        (cnt[u].second += cnt[v].second) %= MOD2;
    }
    return cnt[u];
}
 
pair<int,int> DFS2(int u) {
    avail[u] = 2;
    for(int v : S2[u]) {
        if (avail[v] != 2) DFS2(v);
        (cnt2[u].first += cnt2[v].first) %= MOD;
        (cnt2[u].second += cnt2[v].second) %= MOD2;
    }
    return cnt2[u];
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    int u, v, c;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v >> c;
        S[u].emplace_back(v, c);
    }
    Dijkstra();
 
    for(int u=1; u<=n; ++u)
    for(auto [v, c] : S[u]) {
        if (f[v] == f[u] + c) {
            S2[u].push_back(v);
            S3[v].push_back(u);
        }
    }
 
    cnt[1] = {1,1}; avail[1] = 1; DFS(n);
    cnt2[n] = {1,1}; avail[n] = 2; DFS2(1);
    for(int i=1; i<=n; ++i) {
        if (1LL * cnt[i].first * cnt2[i].first % MOD == cnt[n].first &&
            1LL * cnt[i].second * cnt2[i].second % MOD2 == cnt[n].second) Ans.push_back(i);
    }
 
    cout << Ans.size() << '\n';
    for(int v : Ans) cout << v << ' ';
}
