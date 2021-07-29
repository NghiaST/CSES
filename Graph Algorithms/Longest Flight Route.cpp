#include <iostream>
#include <vector>
using namespace std;
const int N = 100005;
int n, m, visit[N], f[N], nxt[N];
vector<int> S[N];
 
void Enter() {
    cin >> n >> m;
    int u, v;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v;
        S[u].push_back(v);
    }
}
 
void Topo(int u) {
    if (visit[u]) return;
    visit[u] = true;
    for(int v : S[u]) {
        Topo(v);
        if (f[u] < f[v]) f[u] = f[v], nxt[u] = v;
    }
    if (f[u]) ++f[u];
}
 
void Process() {
    visit[n] = f[n] = 1;
    Topo(1);
    if (!f[1]) return (void) (cout << "IMPOSSIBLE");
    cout << f[1] << '\n';
    for(int u=1; u; u=nxt[u]) cout << u << ' ';
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
