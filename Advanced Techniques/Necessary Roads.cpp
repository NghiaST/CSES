#include <iostream>
#include <vector>
using namespace std;
const int N = 100005;
int n, m, cnt, num[N], low[N];
vector<int> S[N];
vector<pair<int,int>> Ans;
 
void Enter() {
    cin >> n >> m;
    int u, v;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v;
        S[u].push_back(v);
        S[v].push_back(u);
    }
}
 
void Tarjan(int u, int d) {
    num[u] = low[u] = ++cnt;
    for(int v : S[u]) if (v != d) {
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) Ans.emplace_back(u, v);
        }
    }
}
 
void Process() {
    for(int i=1; i<=n; ++i) if (!num[i])
        Tarjan(i, i);
    cout << Ans.size() << '\n';
    for(auto [u, v] : Ans) cout << u << ' ' << v << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
