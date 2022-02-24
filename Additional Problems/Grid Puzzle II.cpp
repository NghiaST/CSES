#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=(l); i<=(r); ++i)
#define REP(i,l,r) for(int i=(l); i<(r); ++i)
#define FORD(i,r,l) for(int i=(r); i>=(l); --i)
#define REPD(i,r,l) for(int i=(r)-1; i>=(l); --i)
#define pii pair<int, int>
using namespace std;
const int N = 105, M = 5005, INF = 0x3c3c3c3c;
int n, m, s, t, nn, sumx, maxflow, mincost, id[N][N];
int All[M], Uses[M], C[M], trace[N], trace_eg[N], f[N], inQ[N];
vector<pii> S[N];
 
void add_edge(int u, int v, int cost, int flow) {
    All[++m] = flow;
    C[m] = cost;
    S[u].emplace_back(v, m);
    S[v].emplace_back(u, -m);
}
 
void Enter() {
    cin >> n;
    nn = n * 2 + 2;
    s = n * 2 + 1;
    t = n * 2 + 2;
    int sumy = 0, x;
    FOR(i, 1, n) {
        cin >> x;
        sumx += x;
        add_edge(s, i, 0, x);
    }
    FOR(i, 1, n) {
        cin >> x;
        sumy += x;
        add_edge(i + n, t, 0, x);
    }
    if (sumx != sumy) {
        cout << -1;
        exit(0);
    }
    FOR(i, 1, n) FOR(j, n+1, n*2) {
        cin >> x;
        add_edge(i, j, x, 1);
        id[i][j - n] = m;
    }
}
 
bool FindPath2() {
    queue<int> Q;
    fill(f + 1, f + nn + 1, INF);
    fill(inQ + 1, inQ + nn + 1, 0);
    f[s] = 0;
    Q.push(s);
    inQ[s] = 1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        inQ[u] = 0;
        for(pii eg : S[u]) {
            int v = eg.first, edge = eg.second;
            if (edge > 0) {
                if (Uses[edge] == All[edge]) continue;
                int cost = f[u] - C[edge];
                if (f[v] > cost) {
                    f[v] = cost;
                    trace[v] = u;
                    trace_eg[v] = edge;
                    if (!inQ[v]) {
                        Q.push(v);
                        inQ[v] = 1;
                    }
                }
            }
            else {
                if (Uses[-edge] == 0) continue;
                int cost = f[u] + C[-edge];
                if (f[v] > cost) {
                    f[v] = cost;
                    trace[v] = u;
                    trace_eg[v] = edge;
                    if (!inQ[v]) {
                        Q.push(v);
                        inQ[v] = 1;
                    }
                }
            }
        }
    }
    return f[t] != INF;
}
 
void IncFlow() {
    for(int u = t; u != s; u = trace[u]) {
        int edge = trace_eg[u];
        if (edge > 0) {
            mincost += C[edge];
            ++Uses[edge];
        }
        else {
            mincost -= C[-edge];
            --Uses[-edge];
        }
    }
    ++maxflow;
}
 
void Process() {
    while (FindPath2()) {
        IncFlow();
    }
    if (maxflow != sumx) {
        cout << -1;
        exit(0);
    }
    cout << mincost << '\n';
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            if (Uses[id[i][j]]) cout << 'X';
            else cout << '.';
        }
        cout << '\n';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
