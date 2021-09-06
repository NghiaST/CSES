#include <iostream>
#include <vector>
using namespace std;
int n, m, cnt, low[200005], num[200005], avail[200005];
vector<pair<int,int>> S[200005];
 
void Tarjan(int u, int d) {
    num[u] = low[u] = ++cnt;
    for(auto [v,i] : S[u]) if (v != d) {
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
    }
}
 
void visit(int u) {
    num[u] = 0;
    for(auto [v,i] : S[u]) {
        if (!avail[i]) avail[i] = 1, cout << u << ' ' << v << '\n';
        if (num[v]) visit(v);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    int u, v;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v;
        S[u].emplace_back(v, i);
        S[v].emplace_back(u, i);
    }
    Tarjan(1, 1);
    for(int i=2; i<=n; ++i) if (num[i] == low[i]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    visit(1);
}
