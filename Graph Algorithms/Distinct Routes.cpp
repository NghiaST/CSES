#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 505, M = 2005;
int n, m, limit, max_flow, h[N], trace[N], ans[N];
int head[N], ptr[N], link[M];
struct TEdge{ int u, v, c, f; } E[M];
 
void Enter() {
    cin >> n >> m;
    int u, v;
    for(int i=1; i<=n; ++i) head[i] = -1;
    for(int i=0; i<m*2; i+=2) {
        cin >> u >> v;
        E[i] = {u, v, 1, 0};
        E[i+1] = {v, u, 0, 0};
        link[i] = head[u]; head[u] = i;
        link[i+1] = head[v]; head[v] = i+1;
    }
}
 
bool BFS() {
    for(int i=1; i<=n; ++i) h[i] = -1;
    queue<int> Q;
    Q.push(1); h[1] = 0;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for(int i = head[u]; i != -1; i = link[i]) {
            int v = E[i].v, c = E[i].c, f = E[i].f;
            if (h[v] == -1 && c - f >= limit) {
                h[v] = h[u] + 1;
                Q.push(v);
            }
        }
    }
    return h[n] != -1;
}
 
bool DFS(int u) {
    if (u == n) return true;
    for(int &i = ptr[u]; i != -1; i = link[i]) {
        int v = E[i].v, c = E[i].c, f = E[i].f;
        if (h[v] == h[u] + 1 && c - f >= limit) {
            if (DFS(v)) {
                E[i].f += limit;
                E[i^1].f -= limit;
                return true;
            }
        }
    }
    return false;
}
 
void Process() {
    for(limit = 1; limit; limit >>= 1) {
        while (BFS()) {
            for(int i=1; i<=n; ++i) ptr[i] = head[i];
            while (DFS(1)) max_flow += limit;
        }
    }
}
 
void Trace() {
    for(int i=1; i<=n; ++i) h[i] = -1;
    queue<int> Q;
    Q.push(1); h[1] = 0;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for(int i = head[u]; i != -1; i = link[i]) {
            int v = E[i].v, c = E[i].c, f = E[i].f;
            if (h[v] == -1 && c == f && c == 1) {
                h[v] = h[u] + 1;
                trace[v] = i;
                Q.push(v);
            }
        }
    }
    int res = 0;
    for(int x = n; x != 1; x = E[trace[x]].u) {
        ans[++res] = x;
        --E[trace[x]].f;
    }
    ans[++res] = 1;
    cout << res << '\n';
    while (res) cout << ans[res--] << ' ';
    cout << '\n';
}
 
void Print() {
    cout << max_flow << '\n';
    for(int i=1; i<=max_flow; ++i) Trace();
}
 
int main()
{
    Enter();
    Process();
    Print();
}
