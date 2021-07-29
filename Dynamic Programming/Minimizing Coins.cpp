#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 0x3c3c3c3c;
int n, m, x, f[1000005];
 
void Enter() {
    cin >> n >> m;
}
 
void Process() {
    for(int i=1; i<=m; ++i) f[i] = INF;
    for(int i=1; i<=n; ++i) {
        cin >> x;
        for(int j=x; j<=m; ++j) f[j] = min(f[j], f[j-x] + 1);
    }
    if (f[m] == INF) f[m] = -1;
    cout << f[m];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
