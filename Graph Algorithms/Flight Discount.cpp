#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const long long N = 100005, INF = 1e15;
int n, m;
long long f[N][2];
vector<pair<int,int>> S[N];
struct Data{
    long long x, val, ok;
    bool operator < (const Data &p) const {
        return val > p.val;
    }
};
 
void Enter() {
    cin >> n >> m;
    int u, v, c;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v >> c;
        S[u].emplace_back(v, c);
    }
}
 
void Process() {
    for(int i=2; i<=n; ++i) f[i][0] = f[i][1] = INF;
    priority_queue<Data> Q;
    Q.push({1,0,0});
    while (!Q.empty()) {
        Data w = Q.top(); Q.pop();
        if (w.val != f[w.x][w.ok]) continue;
        int u = w.x, ok = w.ok;
        for(pair<int,int> eg : S[u]) {
            int v = eg.first;
            if (f[v][ok] > f[u][ok] + eg.second) {
                f[v][ok] = f[u][ok] + eg.second;
                Q.push({v, f[v][ok], ok});
            }
            if (!ok && f[v][1] > f[u][0] + eg.second / 2) {
                f[v][1] = f[u][0] + eg.second / 2;
                Q.push({v, f[v][1], 1});
            }
        }
    }
    cout << f[n][1];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
