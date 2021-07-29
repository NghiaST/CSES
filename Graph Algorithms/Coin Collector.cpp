#include <iostream>
#include <vector>
using namespace std;
const int N = 200005;
int n, m, nLTM, avail[N], inLTM[N], c[N];
long long cLTM[N], f[N], res;
vector<int> S[N], S2[N], S3[N], Q;
 
void Enter() {
    cin >> n >> m;
    int u, v;
    for(int i=1; i<=n; ++i) cin >> c[i];
    for(int i=1; i<=m; ++i) {
        cin >> u >> v;
        S[u].push_back(v);
        S2[v].push_back(u);
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
 
void get(int u) {
    if (f[u]) return;
    f[u] = cLTM[u];
    for(int v : S3[u]) {
        get(v);
        f[u] = max(f[u], cLTM[u] + f[v]);
    }
}
 
void Process() {
    for(int i=1; i<=n; ++i) if (!avail[i])
        DFS(i);
    while (!Q.empty()) {
        int u = Q.back(); Q.pop_back();
        if (!inLTM[u]) ++nLTM, DFS2(u);
    }
    for(int i=1; i<=n; ++i) {
        for(int j : S[i]) if (inLTM[i] != inLTM[j]) S3[inLTM[j]].push_back(inLTM[i]);
        cLTM[inLTM[i]] += c[i];
    }
 
    for(int i=1; i<=nLTM; ++i) {
        get(i);
        res = max(res, f[i]);
    }
    cout << res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
