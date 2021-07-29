#include <iostream>
#include <vector>
using namespace std;
const int N = 200005;
int n, m, avail[N], deg[N];
vector<int> Q;
vector<pair<int,int>> S[N];
 
void Enter() {
    cin >> n >> m;
    int u, v;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v;
        S[u].emplace_back(v, i);
        S[v].emplace_back(u, i);
        ++deg[u];
        ++deg[v];
    }
}
 
void Euler(int u) {
    while (!S[u].empty()) {
        int v = S[u].back().first, eg = S[u].back().second; S[u].pop_back();
        if (!avail[eg]) {
            avail[eg] = true;
            Euler(v);
        }
    }
    Q.push_back(u);
}
 
void Process() {
    for(int i=1; i<=n; ++i) if (deg[i] & 1) return (void) (cout << "IMPOSSIBLE");
    Euler(1);
    if (Q.size() != m+1) return (void) (cout << "IMPOSSIBLE");
    for(int v : Q) cout << v << ' ';
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
