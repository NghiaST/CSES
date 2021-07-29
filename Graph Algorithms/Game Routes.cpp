#include <iostream>
#include <vector>
using namespace std;
const int N = 100005, MOD = 1e9 + 7;
int n, m, visit[N], f[N];
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
        f[u] = (f[u] + f[v]) % MOD;
    }
}
 
void Process() {
    visit[n] = f[n] = 1;
    Topo(1);
    cout << f[1];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
