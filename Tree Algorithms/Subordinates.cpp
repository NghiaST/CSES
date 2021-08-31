#include <iostream>
#include <vector>
using namespace std;
int n, x, c[200005];
vector<int> S[200005];
 
void visit(int u) {
    for(int v : S[u]) {
        visit(v);
        c[u] += c[v] + 1;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=2; i<=n; ++i) {
        cin >> x;
        S[x].push_back(i);
    }
    visit(1);
    for(int i=1; i<=n; ++i) cout << c[i] << ' ';
}
