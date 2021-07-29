#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 100005;
int n, m, color[N];
vector<int> S[N];
 
void Enter() {
    cin >> n >> m;
    int u, v;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v;
        S[u].push_back(v);
        S[v].push_back(u);
    }
}
 
void visit(int u, int CL) {
    color[u] = CL;
    for(int v : S[u]) {
        if (!color[v]) visit(v, 3 - CL);
        else if (color[u] + color[v] != 3) {
            cout << "IMPOSSIBLE";
            exit(0);
        }
    }
}
 
void Process() {
    for(int i=1; i<=n; ++i)
        if (!color[i]) visit(i, 1);
    for(int i=1; i<=n; ++i) cout << color[i] << ' ';
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
