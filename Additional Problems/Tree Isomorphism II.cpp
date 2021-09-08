#include <iostream>
#include <vector>
using namespace std;
const int N = 100005, MOD = 998244353, base = 12345, base2 = 76543219;
int t, n, sz[N];
vector<int> S[N];
 
void DFS(int u, int pa) {
    sz[u] = 1;
    for(int v : S[u]) if (v != pa) {
        DFS(v, u);
        sz[u] += sz[v];
    }
}
 
pair<int,int> Centroid() {
    DFS(1, 0);
    int i = 1, j, pa = 1, ok = true;
    while (ok) {
        ok = false;
        for(int v : S[i])
        if (v != pa && sz[v] * 2 > n) {
            pa = i;
            i = v;
            ok = true;
            break;
        }
    }
    j = i;
    for(int v : S[i])
    if (v != pa && sz[v] * 2 == n) {
        j = v;
        break;
    }
    return {i, j};
}
 
long long Compress(int u, int pa) {
    long long code = 0, cnt = 1;
    for(int v : S[u]) if (v != pa) {
        long long x = Compress(v, u);
        code = (code + x * x) % MOD;
        ++cnt;
    }
    code = (code * base + cnt * base2) % MOD;
    return code;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    int u, v;
    long long ansxx, ansxy, ansyx, ansyy;
    while (t--) {
        cin >> n;
        for(int i=1; i<n; ++i) {
            cin >> u >> v;
            S[u].push_back(v);
            S[v].push_back(u);
        }
        pair<int,int> PairA = Centroid();
        ansxx = Compress(PairA.first, 0);
        ansxy = Compress(PairA.second, 0);
        if (ansxx > ansxy) swap(ansxx, ansxy);
        for(int i=1; i<=n; ++i) S[i].clear();
 
        for(int i=1; i<n; ++i) {
            cin >> u >> v;
            S[u].push_back(v);
            S[v].push_back(u);
        }
        pair<int,int> PairB = Centroid();
        ansyx = Compress(PairB.first, 0);
        ansyy = Compress(PairB.second, 0);
        if (ansyx > ansyy) swap(ansyx, ansyy);
        for(int i=1; i<=n; ++i) S[i].clear();
 
        cout << (ansxx == ansyx && ansxy == ansyy ? "YES\n" : "NO\n");
    }
}
