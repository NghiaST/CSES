/// Centroid Decomposition
/// Complexity: O(N * log N)
#include <iostream>
#include <vector>
using namespace std;
const int N = 200005;
int n, k1, k2, Size[N], centroid[N], tmp[N];
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

void visit(int u, bool add, int depth = 1, int parent = 0) {
    if (add) tmp[depth] += Size[u];
    else res += tmp[max(0, k1 - depth)] - tmp[max(0, k2 - depth)];
    for(int v : S[u]) if (!centroid[v] && v != parent) {
        visit(v, add, depth + 1, u);
    }
}

void Centroid_Solve(int x) {
    int SZ = get_subtree_size(x);
    int u = get_Centroid(SZ / 2, x);
    get_subtree_size(u);
    centroid[u] = 1;

    tmp[0] = 1;
    for(int v : S[u]) if (!centroid[v]) {
        visit(v, 0);
        visit(v, 1);
        tmp[0] += Size[v];
    }
    fill(tmp, tmp + SZ, 0);
    for(int v : S[u]) if (!centroid[v])
        Centroid_Solve(v);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k1 >> k2; ++k2;
    int u, v;
    for(int i=1; i<n; ++i) {
        cin >> u >> v;
        S[u].push_back(v);
        S[v].push_back(u);
    }
    Centroid_Solve(1);
    cout << res;
}
