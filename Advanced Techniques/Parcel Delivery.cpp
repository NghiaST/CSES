#include <iostream>
#include <vector>
#include <queue>
#define pii pair<long long,int>
using namespace std;
const long long N = 505, M = 1005, INF = 1e15;
int n, m, k, trace[N];
int All[M], Uses[M], cost[M], U[M], V[M];
long long minCost, f[N], label[N];
vector<int> S[N];
 
void Enter() {
    cin >> n >> m >> k;
    for(int i=1; i<=m; ++i) {
        cin >> U[i] >> V[i] >> All[i] >> cost[i];
        S[U[i]].push_back(i);
        S[V[i]].push_back(-i);
    }
}
 
bool FindPath() {
    if (!k) return false;
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    fill(trace+1, trace+n+1, 0);
    fill(f+1, f+n+1, INF);
    f[1] = 0;
    Q.emplace(0, 1);
    int u, v;
    while (!Q.empty()) {
        int w = Q.top().first;
        u = Q.top().second; Q.pop();
        if (w != f[u]) continue;
        if (u == n) return true;
        for(int eg : S[u]) {
            if (eg > 0) {
                v = V[eg];
                long long W = cost[eg] + label[u] - label[v];
                if (Uses[eg] < All[eg] && f[u] + W < f[v]) {
                    trace[v] = eg;
                    f[v] = f[u] + W;
                    Q.emplace(f[v], v);
                }
            }
            else {
                v = U[-eg];
                long long W = -cost[-eg] + label[u] - label[v];
                if (Uses[-eg] > 0 && f[u] + W < f[v]) {
                    trace[v] = eg;
                    f[v] = f[u] + W;
                    Q.emplace(f[v], v);
                }
            }
        }
    }
    return false;
}
 
void IncFlow() {
    int eg, v = n, flow = k;
    while (v != 1) {
        eg = trace[v];
        if (eg > 0) {
            flow = min(flow, All[eg] - Uses[eg]);
            v = U[eg];
        }
        else {
            flow = min(flow, Uses[-eg]);
            v = V[-eg];
        }
    }
    v = n;
    while (v != 1) {
        eg = trace[v];
        if (eg > 0) {
            Uses[eg] += flow;
            v = U[eg];
            minCost += cost[eg] * flow;
        }
        else {
            Uses[-eg] -= flow;
            v = V[-eg];
            minCost -= cost[-eg] * flow;
        }
    }
    k -= flow;
}
 
void Process() {
    while (FindPath()) {
        IncFlow();
        for(int i=1; i<=n; ++i) if (f[U[i]] != INF)
            label[i] += f[i];
    }
    if (k) minCost = -1;
    cout << minCost;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
