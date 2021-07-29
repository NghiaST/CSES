#include <iostream>
#include <vector>
using namespace std;
const int N = 505;
int n, m, k, cnt, res, avail[N], assigned[N];
vector<int> S[N];
 
void Enter() {
    cin >> n >> m >> k;
    int u, v;
    for(int i=1; i<=k; ++i) {
        cin >> u >> v;
        S[u].push_back(v);
    }
}
 
bool FindPath(int u) {
    for(int v : S[u]) {
        if (avail[v] == cnt) continue;
        if (!assigned[v]) {
            assigned[v] = u;
            return true;
        }
        avail[v] = cnt;
        if (FindPath(assigned[v])) {
            assigned[v] = u;
            return true;
        }
    }
    return false;
}
 
void Process() {
    for(int i=1; i<=n; ++i)
        if (++cnt, FindPath(i)) ++res;
    cout << res << '\n';
    for(int i=1; i<=m; ++i) if (assigned[i])
        cout << assigned[i] << ' ' << i << '\n';
}
 
 
int main()
{
    Enter();
    Process();
}
