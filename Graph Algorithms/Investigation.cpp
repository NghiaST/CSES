#include <bits/stdc++.h>
#define P pair<L,L>
using namespace std;
using L=long;
const L N = 1e6, D = 1e9+7;
L n, m, u, v, e, f[N], c[N], p[N], q[N];
vector<P> S[N];
 
main()
{
    cin >> n >> m;
    while (m--)
        cin >> u >> v >> e,
        S[u].push_back({v, e});
 
    c[1] = 1;
    priority_queue<P> Q;
    Q.push({0, 1});
    while (Q.size()) {
        tie(e,u) = Q.top(); Q.pop();
        if (e == f[u])
            for(auto [v,w] : S[u]) {
                if (!f[v] || f[v] < f[u] - w)
                    f[v] = f[u] - w,
                    Q.push({f[v], v}),
                    c[v] = q[v] = 0,
                    p[v] = N;
 
                if (f[v] == f[u] - w)
                    (c[v] += c[u]) %= D,
                    p[v] = min(p[v], p[u] + 1),
                    q[v] = max(q[v], q[u] + 1);
 
            }
    }
    cout << -f[n] << ' ' << c[n] << ' ' << p[n] << ' ' << q[n];
}
