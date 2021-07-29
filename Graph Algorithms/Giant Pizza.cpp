/// 2_SAT
#include <iostream>
#include <vector>
using namespace std;
const int N = 200005;
int n, m, sz, nLTM, avail[N], inLTM[N], ans[N];
vector<int> S[N], S2[N], Q;
 
void Enter() {
    cin >> m >> n;
    sz = n*2 + 1;
    char cu, cv;
    int u, v;
    for(int i=1; i<=m; ++i) {
        cin >> cu >> u >> cv >> v;
        if (cu == '-') u = sz - u;
        if (cv == '-') v = sz - v;
        S[sz - u].push_back(v);
        S[sz - v].push_back(u);
        S2[v].push_back(sz - u);
        S2[u].push_back(sz - v);
    }
}
 
void DFS(int u) {
    avail[u] = true;
    for(int v : S[u]) if (!avail[v])
        DFS(v);
    Q.push_back(u);
}
 
void DFS2(int u) {
    inLTM[u] = nLTM;
    for(int v : S2[u]) if (!inLTM[v])
        DFS2(v);
}
 
void Process() {
    for(int i=1; i<sz; ++i) if (!avail[i])
        DFS(i);
    while (!Q.empty()) {
        int u = Q.back(); Q.pop_back();
        if (!inLTM[u]) ++nLTM, DFS2(u);
    }
    for(int i=1; i<=n; ++i) {
        if (inLTM[i] == inLTM[sz - i]) return (void) (cout << "IMPOSSIBLE");
        if (inLTM[i] > inLTM[sz - i]) ans[i] = 1;
    }
    for(int i=1; i<=n; ++i) cout << (ans[i] == 1 ? "+ " : "- ");
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    Enter();
    Process();
}
