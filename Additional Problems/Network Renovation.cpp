#include <iostream>
#include <vector>
using namespace std;
const int N = 100005;
int n, r, Q[N];
vector<int> S[N];
 
void Enter() {
    cin >> n;
    int u, v;
    for(int i=2; i<=n; ++i) {
        cin >> u >> v;
        S[u].push_back(v);
        S[v].push_back(u);
    }
}
 
void DFS(int u, int d) {
    for(int v : S[u]) if (v != d) DFS(v, u);
    if (S[u].size() == 1) Q[++r] = u;
}
 
void Process() {
    if (r&1) Q[++r] = Q[1];
    cout << r/2 << '\n';
    for(int i=1; i<=r/2; ++i) cout << Q[i] << ' ' << Q[i+r/2] << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    DFS(1, 0);
    Process();
}
