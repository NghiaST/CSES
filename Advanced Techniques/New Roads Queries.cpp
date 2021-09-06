#include <iostream>
#include <vector>
using namespace std;
const int N = 200005, INF = 0x3c3c3c3c;
int n, m, q;
int dad[N], parent[N], depth[N], child[N], valchild[N];
int cnt, nChain, Chain[N], pChain[N], pos[N], Num[N], R[N], prefixChain[N], it[N * 4];
vector<pair<int,int>> S[N];
 
int DAD(int u) {
    if (dad[u]) return dad[u] = DAD(dad[u]);
    return u;
}
 
bool Union(int u, int v) {
    u = DAD(u);
    v = DAD(v);
    if (u == v) return 0;
    dad[u] = v;
    return 1;
}
 
void Enter() {
    cin >> n >> m >> q;
    int u, v;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v;
        if (Union(u, v)) {
            S[u].emplace_back(v, i);
            S[v].emplace_back(u, i);
        }
    }
    for(int i=1; i<n; ++i) if (Union(i, i+1)) {
        S[i].emplace_back(i+1, INF);
        S[i+1].emplace_back(i, INF);
    }
}
 
void visit(int u, int pa) {
    dad[u] = pa;
    parent[u] = pa;
    depth[u] = depth[pa] + 1;
    for(auto[v,i] : S[u]) if (v != pa) {
        visit(v, u);
        if (depth[v] > depth[child[u]]) child[u] = v, valchild[u] = i;
    }
}
 
void HLD(int u, int pa, int val) {
    Chain[u] = nChain;
    pos[u] = ++cnt;
    Num[cnt] = val;
    R[nChain] = cnt;
    if (child[u]) HLD(child[u], u, valchild[u]);
    for(auto [v,i] : S[u]) if (v != pa && v != child[u]) {
        pChain[++nChain] = u;
        HLD(v, u, i);
    }
}
 
void Build(int l, int r, int pos) {
    if (l == r) {
        it[pos] = Num[l];
        return;
    }
    int mid = (l + r) / 2;
    Build(l, mid, pos*2);
    Build(mid+1, r, pos*2+1);
    it[pos] = max(it[pos*2], it[pos*2+1]);
}
 
int getIT(int x, int y, int l = 1, int r = n, int pos = 1) {
    if (l > y || x > r) return 0;
    if (x <= l && r <= y) return it[pos];
    int mid = (l+r) / 2;
    return max(getIT(x, y, l, mid, pos*2), getIT(x, y, mid+1, r, pos*2+1));
}
 
int LCA(int u, int v) {
    if (Chain[u] == Chain[v]) return (depth[u] < depth[v] ? u : v);
    if (Chain[u] < Chain[v]) return LCA(u, pChain[Chain[v]]);
    else return LCA(pChain[Chain[u]], v);
}
 
int query(int u, int pa) {
    if (Chain[pa] == Chain[u]) return getIT(pos[pa] + 1, pos[u]);
    return max(prefixChain[pos[u]], query(pChain[Chain[u]], pa));
}
 
void BuildHLD() {
    nChain = 1;
    visit(1, 0);
    HLD(1, 0, 0);
    Build(1, n, 1);
    for(int i=nChain; i; --i)
        for(int j=R[i-1]+1; j<=R[i]; ++j) prefixChain[j] = max(prefixChain[j-1], Num[j]);
}
 
int Solve(int u, int v) {
    int pa = LCA(u, v);
    int ans = max(query(u, pa), query(v, pa));
    if (ans == INF) ans = -1;
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    BuildHLD();
    int u, v;
    while (q--) {
        cin >> u >> v;
        cout << Solve(u, v) << '\n';
    }
}
