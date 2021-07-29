#include <iostream>
#include <vector>
using namespace std;
const int N = 100005;
int n, m, res, Q[N], vs[N];
vector<int> S[N];
 
void Enter() {
    cin >> n >> m;
    int u, v;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v;
        S[u].push_back(v);
        S[v].push_back(u);
    }
}
 
void visit(int u) {
    vs[u] = true;
    for(int v : S[u]) if (!vs[v])
        visit(v);
}
 
void Process() {
    visit(1);
    for(int i=2; i<=n; ++i) if (!vs[i]) {
        visit(i);
        Q[++res] = i;
    }
    cout << res << '\n';
    for(int i=1; i<=res; ++i) cout << 1 << ' ' << Q[i] << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
