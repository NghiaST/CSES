#include <bits/stdc++.h>
using namespace std;
int n, m, i, u, v, d[1<<18];
vector<int> S[1<<18], A;
 
void E(int u) {
    while (S[u].size())
        v = S[u].back(), S[u].pop_back(),
        E(v);
    A.push_back(u);
}
 
main()
{
    cin >> n >> m;
    for(i=1; i<=m; ++i)
        cin >> u >> v,
        S[v].push_back(u),
        ++d[u], --d[v];
    E(n);
    if (d[1]-1 | d[n]+1 | A.size()-m-1 | A[0]-1) cout << "IMPOSSIBLE";
    else for(int v : A) cout << v << ' ';
}
