#include <iostream>
#include <vector>
using namespace std;
int n, m, cnt, pa[100005], num[100005], low[100005];
vector<int> S[100005];
 
void Enter() {
    cin >> n >> m;
    int u, v;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v;
        S[u].push_back(v);
    }
}
 
void Tarjan(int u) {
    num[u] = low[u] = ++cnt;
    for(int v : S[u]) {
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
            if (num[v] == low[v]) {
                cout << "NO\n" << v << ' ' << u;
                exit(0);
            }
        }
    }
}
 
void Process() {
    Tarjan(1);
    if (cnt == n) cout << "YES";
    else {
        for(int i=1; i<=n; ++i) if (!num[i]) {
            cout << "NO\n" << 1 << ' ' << i;
            return;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    Enter();
    Process();
}
