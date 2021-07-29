#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const long long N = 505, INF = 1e15;
int n, m, q;
long long f[N][N];
 
void Enter() {
    cin >> n >> m >> q;
    int u, v, c;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            if (i != j) f[i][j] = INF;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v >> c;
        if (f[u][v] > c) f[u][v] = f[v][u] = c;
    }
}
 
void Process() {
    for(int w=1; w<=n; ++w)
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j)
                f[i][j] = min(f[i][j], f[i][w] + f[w][j]);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            if (f[i][j] == INF) f[i][j] = -1;
    int u, v;
    while (q--) {
        cin >> u >> v;
        cout << f[u][v] << '\n';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
