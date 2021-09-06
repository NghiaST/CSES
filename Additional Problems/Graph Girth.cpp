#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 2505;
int n, m, res, f[N], p[N];
vector<int> S[N];
queue<int> Q;
 
void BFS(int u) {
    for(int i=1; i<=n; ++i) f[i] = p[i] = 0;
    Q.push(u);
    while (!Q.empty()) {
        u = Q.front(); Q.pop();
        for(int v : S[u]) if (p[u] != v) {
            if (p[v]) res = min(res, f[u] + f[v] + 1);
            else {
                f[v] = f[u] + 1;
                p[v] = u;
                Q.push(v);
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
    res = n+1;
    for(int i=1; i<=n; ++i) BFS(i);
    if (res > n) res = -1;
    cout << res;
}
