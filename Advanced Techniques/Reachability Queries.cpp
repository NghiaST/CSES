#include <iostream>
#include <vector>
using namespace std;
const int N = 50005;
int n, m, q, cnt, block, nNode, num[N], low[N], root[N], vs[N];
unsigned long long f[N][790];
vector<int> S[N], S2[N], Q;
 
void Enter() {
    cin >> n >> m >> q;
    int u, v;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v; --u, --v;
        S[u].push_back(v);
    }
}
 
void Tarjan(int u) {
    num[u] = low[u] = ++cnt;
    Q.push_back(u);
    for(int v : S[u]) {
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == num[u]) {
        int v;
        do {
            v = Q.back(); Q.pop_back();
            root[v] = nNode;
            num[v] = 0x3c3c3c3c;
        } while (v != u);
        ++nNode;
    }
}
 
void visit(int u) {
    f[u][u >> 6] = 1LL << (u % 64);
    vs[u] = true;
    for(int v : S2[u]) {
        if (!vs[v]) visit(v);
        for(int i=0; i<block; ++i) f[u][i] |= f[v][i];
    }
}
 
void Init() {
    for(int i=0; i<n; ++i) if (!num[i])
        Tarjan(i);
    for(int i=0; i<n; ++i)
    for(int v : S[i]) if (root[i] != root[v])
        S2[root[i]].push_back(root[v]);
    block = (nNode + 63) >> 6;
    for(int i=0; i<n; ++i) if (!vs[i]) visit(i);
}
 
void Process() {
    int u, v;
    while (q--) {
        cin >> u >> v; --u, --v;
        if (root[u] == root[v]) cout << "YES\n";
        else {
            u = root[u]; v = root[v];
            if ((f[u][v >> 6] >> (v % 64)) & 1) cout << "YES\n"; else cout << "NO\n";
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Init();
    Process();
}
