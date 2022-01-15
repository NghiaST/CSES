/// Centroid Decomposition
/// Complexity: O(N * log^2 N)
#include <iostream>
#include <vector>
using namespace std;
const int N = 200005;
int n, k1, k2, max_high, Size[N], centroid[N], cnt[N];
long long res;
vector<int> S[N];
 
int get_subtree_size(int u, int parent = 0) {
    Size[u] = 1;
    for(int v : S[u]) if (!centroid[v] && v != parent)
        Size[u] += get_subtree_size(v, u);
    return Size[u];
}
 
int get_Centroid(int SZ, int u, int parent = 0) {
    for(int v : S[u]) if (!centroid[v] && v != parent)
        if (Size[v] >= SZ) return get_Centroid(SZ, v, u);
    return u;
}
 
void update(int x) {
    for(++x; x; x-=x&-x) ++cnt[x];
}
 
int query(int x) {
    int ans = 0;
    for(++x; x<=k2+1; x+=x&-x) ans += cnt[x];
    return ans;
}
 
int query(int l, int r) {
    return query(max(0, l)) - query(r+1);
}
 
void visit(int u, bool add_path, int depth = 1, int parent = 0) {
    if (depth > k2) return;
    max_high = max(max_high, depth);
    if (add_path) res += query(k1 - depth, k2 - depth);
    else update(depth);
    for(int v : S[u]) if (!centroid[v] && v != parent) {
        visit(v, add_path, depth + 1, u);
    }
}
 
void Centroid_Solve(int x) {
    int SZ = get_subtree_size(x);
    int u = get_Centroid(SZ / 2, x);
    centroid[u] = 1;
    max_high = 0;
 
    for(int v : S[u]) if (!centroid[v]) {
        visit(v, 1);
        visit(v, 0);
    }
    fill(cnt + 2, cnt + max_high + 2, 0);
    for(int v : S[u]) if (!centroid[v]) Centroid_Solve(v);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k1 >> k2;
    int u, v;
    for(int i=1; i<n; ++i) {
        cin >> u >> v;
        S[u].push_back(v);
        S[v].push_back(u);
    }
    update(0);
    Centroid_Solve(1);
    cout << res;
}
