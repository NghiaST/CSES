#include <iostream>
#include <queue>
using namespace std;
const int N = 505, M = 2005;
int n, m, limit, head[N], link[M], ptr[N], h[N];
long long max_flow;
struct TEdge{ int u, v, c, f; } E[M];
 
void Enter() {
    cin >> n >> m;
    for(int i=1; i<=n; ++i) head[i] = -1;
    int u, v, c;
    for(int i=0; i<m*2; i+=2) {
        cin >> u >> v >> c;
        E[i] = {u, v, c, 0};
        E[i+1] = {v, u, 0, 0};
 
        link[i] = head[u]; head[u] = i;
        link[i+1] = head[v]; head[v] = i+1;
    }
}
 
bool BFS() {
    queue<int> Q;
    for(int i=1; i<=n; ++i) h[i] = -1;
    h[1] = 0; Q.push(1);
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
    for(limit = 1<<30; limit; limit >>= 1) {
        while (BFS()) {
            for(int i=1; i<=n; ++i) ptr[i] = head[i];
            while (DFS(1)) max_flow += limit;
        }
    }
    cout << max_flow;
}
 
 
int main()
{
    Enter();
    Process();
}
