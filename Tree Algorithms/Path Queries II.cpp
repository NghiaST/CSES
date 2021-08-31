#include <iostream>
#include <vector>
using namespace std;
const int N = 200005;
int n, q, cnt, nChain, dad[N], parent[N], high[N], p[N], nxt[N], chain[N], cL[N], w[N], val[N*4];
vector<int> S[N];
 
void ReadInt(int &x) {
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    x = 0;
    while (isdigit(c)) x = (x<<3) + (x<<1) + c - '0', c = getchar();
}
 
void Print(int x) {
    if (x > 9) Print(x / 10);
    putchar(x % 10 + 48);
}
 
void Enter() {
    ReadInt(n);
    ReadInt(q);
    for(int i=1; i<=n; ++i) ReadInt(w[i]);
    int u, v;
    for(int i=1; i<n; ++i) {
        ReadInt(u);
        ReadInt(v);
        S[u].push_back(v);
        S[v].push_back(u);
    }
}
 
void DFS1(int u) {
    for(int v : S[u]) if (v != dad[u]) {
        dad[v] = u;
        high[v] = high[u] + 1;
        DFS1(v);
        if (high[v] > high[nxt[u]]) nxt[u] = v;
    }
}
 
void DFS2(int u) {
    p[u] = ++cnt;
    chain[u] = nChain;
    if (!cL[nChain]) cL[nChain] = cnt;
    if (nxt[u]) DFS2(nxt[u]);
    for(int v : S[u]) if (v != dad[u] && v != nxt[u]) {
        parent[++nChain] = u;
        DFS2(v);
    }
}
 
void update(int l, int r, int x, int vv, int pos) {
    if (l == r) {
        val[pos] = vv;
        return;
    }
    int mid = (l+r) / 2;
    if (x <= mid) update(l, mid, x, vv, pos*2);
    else update(mid+1, r, x, vv, pos*2+1);
    val[pos] = max(val[pos*2], val[pos*2+1]);
}
 
int query(int l, int r, int x, int y, int pos) {
    if (x > r || y < l) return 0;
    if (x <= l && r <= y) return val[pos];
    int mid = (l+r) / 2;
    return max(query(l, mid, x, y, pos*2), query(mid+1, r, x, y, pos*2+1));
}
 
void Init() {
    DFS1(1);
    nChain = 1;
    DFS2(1);
    for(int i=1; i<=n; ++i) update(1, n, p[i], w[i], 1);
}
 
int LCA(int u, int v) {
    while (chain[u] != chain[v]) {
        if (chain[u] > chain[v]) u = parent[chain[u]];
        else v = parent[chain[v]];
    }
    return (high[u] < high[v] ? u : v);
}
 
int HLD_max(int u, int d) {
    if (chain[u] == chain[d]) return query(1, n, p[d], p[u], 1);
    return max(HLD_max(parent[chain[u]], d), query(1, n, cL[chain[u]], p[u], 1));
}
 
void Process() {
    int type, u, v, d;
    while (q--) {
        ReadInt(type);
        ReadInt(u);
        ReadInt(v);
        if (type == 1) update(1, n, p[u], v, 1);
        else {
            d = LCA(u, v);
            Print(max(HLD_max(u, d), HLD_max(v, d)));
            putchar(' ');
        }
    }
}
 
int main()
{
    Enter();
    Init();
    Process();
}
