#include <iostream>
#include <vector>
using namespace std;
const int N = 100005;
int n, m, cnt, nNode, num[N], low[N], Node[N], avail[N];
int End, top[N], In[N], Out[N];
vector<int> S[N], Q, Scc[N], Scc2[N];
vector<pair<int,int>> Ans;
 
void Enter() {
    cin >> n >> m;
    int u, v;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v;
        S[u].push_back(v);
    }
}
 
void Tarjan(int u) {
    num[u] = low[u] = ++cnt;
    Q.push_back(u);
    for(int v : S[u]) {
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (num[u] == low[u]) {
        top[++nNode] = u;
        int v;
        do {
            v = Q.back(); Q.pop_back();
            Node[v] = nNode;
            num[v] = 1e9;
        } while (v != u);
    }
}
 
void DFS(int u) {
    avail[u] = true;
    if (!Out[u]) End = u;
    for(int v : Scc[u]) if (!avail[v])
        DFS(v);
}
 
void DFS2(int u) {
    avail[u] = true;
    if (!In[u]) End = u;
    for(int v : Scc2[u]) if (!avail[v])
        DFS2(v);
}
 
void addEdge(int u, int v) {
    Out[u] = In[v] = true;
    Scc[u].push_back(v);
    Scc2[v].push_back(u);
    Ans.emplace_back(top[u], top[v]);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    for(int u=1; u<=n; ++u) if (!num[u]) Tarjan(u);
    if (nNode == 1) return cout << 0, 0;
 
    for(int u=1; u<=n; ++u) {
        for(int v : S[u]) if (Node[u] != Node[v]) {
            Scc[Node[u]].push_back(Node[v]);
            Scc2[Node[v]].push_back(Node[u]);
            Out[Node[u]] = In[Node[v]] = true;
        }
    }
 
    int v_In = 0;
    for(int u=1; u<=nNode; ++u) if (In[u] == 0) {
        End = 0;
        if (!avail[u]) DFS(u);
        if (End) {
            if (v_In) addEdge(End, v_In);
            v_In = u;
        }
    }
 
    fill(avail+1, avail+nNode+1, 0);
    int v_Out = 0;
    for(int u=1; u<=nNode; ++u) if (Out[u] == 0) {
        End = 0;
        if (!avail[u]) DFS2(u);
        if (End) {
            if (v_Out) addEdge(v_Out, End);
            v_Out = u;
        }
    }
 
    if (v_In && v_Out) addEdge(v_Out, v_In);
    for(int u=1, v=1; u<=nNode; ++u) {
        if (Out[u]) continue;
        while (v<=nNode && In[v]) ++v;
        if (v<=nNode) addEdge(u, v);
    }
 
 
    for(int u=1; u<=nNode; ++u) {
        if (!In[u]) addEdge(v_Out, u);
        if (!Out[u]) addEdge(u, v_In);
    }
 
    cout << Ans.size() << '\n';
    for(auto [u, v] : Ans) cout << u << ' ' << v << '\n';
}
