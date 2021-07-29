#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;
int n, m, a[1005], b[1005], f[100005];
 
void Enter() {
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) cin >> b[i];
}
 
void Process() {
    for(int i=1; i<=n; ++i) {
        for(int j=m; j>=a[i]; --j) f[j] = max(f[j], f[j-a[i]] + b[i]);
    }
    cout << f[m];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
