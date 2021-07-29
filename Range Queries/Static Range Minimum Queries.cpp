#include <iostream>
#include <cmath>
using namespace std;
long long n, q, u, v, p[200005][20];
 
int main()
{
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> p[i][0];
    for(int i=1; 1<<i <= n; ++i)
        for(int j=1; j + (1<<i) - 1 <= n; ++j)
            p[j][i] = min(p[j][i-1], p[j + (1<<(i-1))][i-1]);
    while (q--) {
        cin >> u >> v;
        int lg = trunc(log2(v - u + 1));
        cout << min(p[u][lg], p[v - (1<<lg) + 1][lg]) << '\n';
    }
}
