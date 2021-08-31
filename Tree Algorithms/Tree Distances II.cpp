#include <iostream>
#include <vector>
using namespace std;
int n;
long long c[200005], cnt[200005], ans[200005];
vector<int> S[200005];
 
void visit(int u, int d) {
    int max1 = 0, max2 = 0;
    for(int v : S[u]) if (v != d) {
        visit(v, u);
        c[u] += c[v] + cnt[v];
        cnt[u] += cnt[v];
    }
    ++cnt[u];
}
 
void visit2(int u, int d, long long val) {
    ans[u] = c[u] + val;
    for(int v : S[u]) if (v != d) {
        visit2(v, u, val + (c[u] - c[v] - cnt[v]) + (n - cnt[v]));
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    int u, v;
    for(int i=2; i<=n; ++i) {
        cin >> u >> v;
        S[u].push_back(v);
        S[v].push_back(u);
    }
    visit(1, 1);
    visit2(1, 1, 0);
    for(int i=1; i<=n; ++i) cout << ans[i] << ' ';
}
