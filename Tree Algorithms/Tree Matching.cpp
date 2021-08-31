#include <iostream>
#include <vector>
using namespace std;
int n, res, avail[200005], c[200005];
vector<int> S[200005];
 
void visit(int u) {
    avail[u] = true;
    for(int v : S[u]) if (!avail[v]) {
        visit(v);
        c[u] = max(c[u], c[v]);
    }
    if (++c[u] == 2) ++res, c[u] = 0;
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
    for(int i=1; i<=n; ++i) if (!avail[i])
        visit(i);
    cout << res;
}
