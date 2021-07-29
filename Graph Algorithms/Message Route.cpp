#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 100005;
int n, m, trace[N];
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
 
void found(int x, int h) {
    if (x == 1) cout << h << '\n';
    else found(trace[x], h+1);
    cout << x << ' ';
}
 
void Process() {
    queue<int> Q;
    Q.push(1);
    trace[1] = -1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (u == n) break;
        for(int v : S[u]) if (!trace[v]) {
            trace[v] = u;
            Q.push(v);
        }
    }
    if (!trace[n]) cout << "IMPOSSIBLE";
    else found(n, 1);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
