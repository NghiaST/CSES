#include <iostream>
#include <vector>
using namespace std;
const int N = 2e5 + 5;
int n, m, high[N], deg[N];
vector<int> S[N];
vector<pair<int,int>> Ans;
 
void DFS(int u, int pa) {
    high[u] = high[pa] + 1;
    for(int v : S[u]) if (v != pa) {
        if (high[v]) {
            if (high[v] < high[u]) {
                Ans.emplace_back(u, v);
                deg[u] ^= 1;
            }
        }
        else {
            DFS(v, u);
            if (deg[v]) {
                Ans.emplace_back(v, u);
                deg[v] ^= 1;
            }
            else {
                Ans.emplace_back(u, v);
                deg[u] ^= 1;
            }
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    int u, v;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v;
        S[u].push_back(v);
        S[v].push_back(u);
    }
    for(int i=1; i<=n; ++i) if (!high[i]) DFS(i, 0);
    for(int i=1; i<=n; ++i) if (deg[i]) return cout << "IMPOSSIBLE", 0;
    for(auto [u,v] : Ans) cout << u << ' ' << v << '\n';
}
