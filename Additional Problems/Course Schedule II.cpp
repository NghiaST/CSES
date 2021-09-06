#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, deg[100005];
vector<int> S[100005], Ans;
priority_queue<int> Q;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    int u, v;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v;
        S[v].push_back(u);
        ++deg[u];
    }
    for(int i=1; i<=n; ++i) if (deg[i] == 0)
        Q.push(i);
    while (!Q.empty()) {
        int u = Q.top(); Q.pop();
        Ans.push_back(u);
        for(int v : S[u]) if (--deg[v] == 0) Q.push(v);
    }
    reverse(Ans.begin(), Ans.end());
    for(int u : Ans) cout << u << ' ';
}
