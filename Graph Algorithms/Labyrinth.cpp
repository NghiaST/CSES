#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1005;
const int Gx[4] = {1, 0, 0, -1}, Gy[4] = {0, -1, 1, 0};
const char P[] = "DLRU";
int n, m, res, vs[N][N], trace[N][N], high[N][N];
char s[N][N];
 
void Enter() {
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> s[i] + 1;
}
 
void Trace(int x, int y) {
    if (s[x][y] == 'B') return;
    int ans = trace[x][y];
    cout << P[3 - ans];
    Trace(x - Gx[ans], y - Gy[ans]);
}
 
void BFS(int x, int y) {
    queue<pair<int,int>> Q;
    Q.emplace(x, y);
    high[x][y] = 1;
    while (!Q.empty()) {
        pair<int,int> w = Q.front(); Q.pop();
        if (s[w.first][w.second] == 'A') {
            cout << "YES\n" << high[w.first][w.second] - 1 << '\n';
            Trace(w.first, w.second);
            return;
        }
        for(int i=3; i>=0; --i) {
            int u = w.first + Gx[i];
            int v = w.second + Gy[i];
            if ((s[u][v] == '.' || s[u][v] == 'A') && !high[u][v]) {
                high[u][v] = high[w.first][w.second] + 1;
                trace[u][v] = i;
                Q.emplace(u, v);
            }
        }
    }
    cout << "NO\n";
}
 
void Process() {
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if (s[i][j] == 'B')
                BFS(i, j);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
