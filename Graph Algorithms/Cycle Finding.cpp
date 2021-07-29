#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const long long N = 100005;
int n, m, rr, dem[N], inQ[N], trace[N], QQ[N], avail[N];
long long f[N];
vector<pair<int,int>> S[N];
 
void Enter() {
    cin >> n >> m;
    int u, v, c;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v >> c;
        S[u].emplace_back(v, c);
    }
}
 
void found(int u) {
    do {
        avail[u] = ++rr;
        QQ[rr] = u;
        u = trace[u];
    } while (!avail[u]);
    QQ[++rr] = u;
    cout << "YES\n";
    for(int i=rr; i>=avail[u]; --i) cout << QQ[i] << ' ';
 
}
 
void Process() {
    queue<int> Q;
    for(int i=1; i<=n; ++i) Q.push(i), inQ[i] = true;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop(); inQ[u] = false;
        if (++dem[u] > n) {
            found(u);
            return;
        }
        for(pair<int,int> eg : S[u]) {
            if (f[eg.first] > f[u] + eg.second) {
                f[eg.first] = f[u] + eg.second;
                trace[eg.first] = u;
                if (!inQ[eg.first]) {
                    inQ[eg.first] = true;
                    Q.push(eg.first);
                }
            }
        }
    }
    cout << "NO";
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
