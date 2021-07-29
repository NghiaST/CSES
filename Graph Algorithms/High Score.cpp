#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const long long N = 2505, INF = 1e15;
int n, m, inQ[N], dem[N];
long long f[N];
vector<pair<int,int>> S[N];
 
void Enter() {
    cin >> n >> m;
    int u, v, c;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v >> c;
        S[u].emplace_back(v, c);
    }
}
 
void Process() {
    for(int i=2; i<=n; ++i) f[i] = -INF;
    queue<int> Q;
    Q.push(1);
    inQ[1] = true;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        inQ[u] = false;
        if (++dem[u] > n) f[u] = INF;
        for(pair<int,int> eg : S[u]) {
            if (f[eg.first] < min(INF, f[u] + eg.second)) {
                f[eg.first] = min(INF, f[u] + eg.second);
                if (!inQ[eg.first]) {
                    inQ[eg.first] = true;
                    Q.push(eg.first);
                }
            }
        }
    }
    if (f[n] > 5e14) f[n] = -1;
    cout << f[n];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
