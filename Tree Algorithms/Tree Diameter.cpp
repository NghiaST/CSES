#include <iostream>
#include <vector>
using namespace std;
int n, res, avail[200005], c[200005];
vector<int> S[200005];
 
void visit(int u, int d) {
    int max1 = 0, max2 = 0;
    for(int v : S[u]) if (v != d) {
        visit(v, u);
        if (c[v] > max2) max2 = c[v];
        if (max1 < max2) swap(max1, max2);
    }
    res = max(res, max1 + max2);
    c[u] = max1 + 1;
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
    cout << res;
}
