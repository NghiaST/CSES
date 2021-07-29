#include <iostream>
#include <vector>
using namespace std;
const int N = 100005;
int n, m, cnt, nNode, c[N], num[N], low[N];
vector<int> S[N], Q;
 
void Enter() {
    cin >> n >> m;
    int u, v;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v;
        S[u].push_back(v);
    }
}
 
void Tarjan(int u) {
    Q.push_back(u);
    num[u] = low[u] = ++cnt;
    for(int v : S[u]) {
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (num[u] == low[u]) {
        int v;
        ++nNode;
        do {
            v = Q.back(); Q.pop_back();
            c[v] = nNode;
            num[v] = 123456789;
        } while (v != u);
    }
}
 
void Process() {
    for(int i=1; i<=n; ++i)
        if (!num[i]) Tarjan(i);
    cout << nNode << '\n';
    for(int i=1; i<=n; ++i) cout << c[i] << ' ';
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    Enter();
    Process();
}
