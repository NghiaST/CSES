#include <iostream>
#include <vector>
using namespace std;
const int N = 100005, MOD = 998244353, base = 12345, base2 = 76543219;
int t, n;
vector<int> S[N];
 
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
    long long ansx, ansy;
    while (t--) {
        cin >> n;
        for(int i=1; i<n; ++i) {
            cin >> u >> v;
            S[u].push_back(v);
            S[v].push_back(u);
        }
        ansx = Compress(1, 0);
        for(int i=1; i<=n; ++i) S[i].clear();
 
        for(int i=1; i<n; ++i) {
            cin >> u >> v;
            S[u].push_back(v);
            S[v].push_back(u);
        }
        ansy = Compress(1, 0);
        for(int i=1; i<=n; ++i) S[i].clear();
 
        cout << (ansx == ansy ? "YES\n" : "NO\n");
    }
}
