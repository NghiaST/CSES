#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 100005;
int n, m, cnt, res, num[N], low[N], ok[N];
vector<int> S[N], S2[N];
 
void visit(int u) {
    num[u] = ++cnt, low[u] = 0x3c3c3c3c;
    for(int v : S[u]) {
        if (!num[v]) {
            visit(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }
    if (low[u] == num[u]) ok[u] = true;
    num[u] = 0x3c3c3c3c;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    int u, v;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v;
        S[u].push_back(v);
        S2[v].push_back(u);
    }
    for(int i=1; i<=n; ++i) if (!num[i]) visit(i);
    for(int i=1; i<=n; ++i) if (num[i] && ok[i]) {
        queue<int> Q;
        Q.push(i); num[i] = 0;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for(int v : S[u]) if (num[v]) num[v] = 0, Q.push(v);
            for(int v : S2[u]) if (num[v]) num[v] = 0, Q.push(v);
            ++res;
        }
    }
    for(int i=1; i<=n; ++i) if (num[i]) {
        queue<int> Q;
        Q.push(i); num[i] = 0;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for(int v : S[u]) if (num[v]) num[v] = 0, Q.push(v);
            for(int v : S2[u]) if (num[v]) num[v] = 0, Q.push(v);
            ++res;
        }
        --res;
    }
    cout << res;
}
