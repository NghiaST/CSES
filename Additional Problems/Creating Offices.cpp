#include <iostream>
#include <vector>
using namespace std;
int n, d, ans, choice[200005], maxdepth[200005], save[200005];
vector<int> S[200005];

void DFS(int u, int pa) {
    int big = 0, small = 0;
    for(int v : S[u]) if (v != pa) {
        DFS(v, u);
        if (maxdepth[v] * 2 + 2 < d) {
            if (small == 0 || maxdepth[small] < maxdepth[v]) swap(small, v);
            if (v != 0) --ans, choice[save[v]] = 0;
        }
        else {
            if (big == 0 || maxdepth[big] > maxdepth[v]) big = v;
        }
    }
    if (big && small && maxdepth[big] + maxdepth[small] + 2 < d) {
        --ans, choice[save[small]] = 0, small = 0;
    }
    if (small) maxdepth[u] = maxdepth[small] + 1, save[u] = save[small];
    else if (big) maxdepth[u] = maxdepth[big] + 1, save[u] = save[big];
    else maxdepth[u] = d, save[u] = u;
    if (maxdepth[u] == d) {
        maxdepth[u] = 0;
        save[u] = u;
        ++ans, choice[u] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> d;
    int u, v;
    for(int i=1; i<n; ++i) {
        cin >> u >> v;
        S[u].push_back(v);
        S[v].push_back(u);
    }
    DFS(1, 0);
    cout << ans << '\n';
    for(int i=1; i<=n; ++i) if (choice[i]) cout << i << ' ';
}
