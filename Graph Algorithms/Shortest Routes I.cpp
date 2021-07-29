#include <iostream>
#include <vector>
#include <queue>
#define pii pair<long long,int>
using namespace std;
const int N = 100005;
int n, m, avail[N];
long long f[N];
vector<pii> S[N];
 
void Enter() {
    cin >> n >> m;
    int u, v, c;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v >> c;
        S[u].emplace_back(v, c);
    }
}
 
void Process() {
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    Q.emplace(0, 1);
    fill(f+2, f+n+1, 1e15);
    while (!Q.empty()) {
        int u = Q.top().second; Q.pop();
        if (avail[u]) continue;
        avail[u] = true;
        for(pii eg : S[u]) {
            if (f[eg.first] > f[u] + eg.second) {
                f[eg.first] = f[u] + eg.second;
                Q.emplace(f[eg.first], eg.first);
            }
        }
    }
    for(int i=1; i<=n; ++i) cout << f[i] << ' ';
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
