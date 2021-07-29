#include <iostream>
#include <queue>
using namespace std;
const int N = 1005;
const int Gx[4] = {1, 0, 0, -1}, Gy[4] = {0, -1, 1, 0};
const char P[] = "DLRU";
int n, m, avail[N][N], trace[N][N];
char s[N][N];
struct point{int x, y;};
 
void Enter() {
    cin >> n >> m;
    for(int i=0; i<n; ++i) cin >> s[i];
}
 
void Trace(int x, int y, int h) {
    if (s[x][y] == 'A') {
        cout << "YES\n" << h << '\n';
        return;
    }
    int ans = trace[x][y];
    Trace(x - Gx[ans], y - Gy[ans], h + 1);
    cout << P[ans];
}
 
void Process() {
    queue<point> Q1, Q2, Q3, Q4;
    for(int i=0; i<n; ++i)
    for(int j=0; j<m; ++j) {
        if (s[i][j] == 'A') avail[i][j] = 1, Q1.push({i, j});
        if (s[i][j] == 'M') avail[i][j] = 2, Q2.push({i, j});
        if (s[i][j] == '#') avail[i][j] = 3;
    }
    while (!Q1.empty()) {
        while (!Q1.empty()) {
            point w = Q1.front(); Q1.pop();
            if (avail[w.x][w.y] == 2) continue;
            if (w.x == 0 || w.x + 1 == n || w.y == 0 || w.y + 1 == m) {
                Trace(w.x, w.y, 0);
                return;
            }
            for(int i=0; i<4; ++i) {
                int u = w.x + Gx[i];
                int v = w.y + Gy[i];
                if (!avail[u][v]) {
                    trace[u][v] = i;
                    avail[u][v] = 1;
                    Q3.push({u,v});
                }
            }
        }
        while (!Q2.empty()) {
            point w = Q2.front(); Q2.pop();
            for(int i=0; i<4; ++i) {
                int u = w.x + Gx[i];
                int v = w.y + Gy[i];
                if (0 <= u && u < n && 0 <= v && v < m && avail[u][v] != 2 && avail[u][v] != 3) {
                    avail[u][v] = 2;
                    Q4.push({u,v});
                }
            }
        }
        Q1 = Q3; while (!Q3.empty()) Q3.pop();
        Q2 = Q4; while (!Q4.empty()) Q4.pop();
    }
    cout << "NO";
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
