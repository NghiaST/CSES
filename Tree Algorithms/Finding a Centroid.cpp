#include <iostream>
#include <algorithm>
#include <vector>
const int N = 200005;
using namespace std;
int n, c[N], c_max[N];
vector<int> S[N];
 
void visit(int u, int d) {
    for(int v : S[u]) if (v != d)
        visit(v, u);
    ++c[u];
    c[d] += c[u];
    c_max[d] = max(c_max[d], c[u]);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    int u, v;
    for(int i=1; i<n; ++i) {
        cin >> u >> v;
        S[u].push_back(v);
        S[v].push_back(u);
    }
    visit(1, 0);
    int x = 1, d = 0;
    while (c_max[x] > n/2) {
        for(int v : S[x]) if (v != d) {
            if (n - c[v] <= n/2) {
                d = x;
                x = v;
                break;
            }
        }
    }
    cout << x;
}
