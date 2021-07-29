#include <iostream>
using namespace std;
int n, q, u, v, a[200005];
 
int main()
{
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> a[i], a[i] ^= a[i-1];
    while (q--) {
        cin >> u >> v;
        cout << (a[v] ^ a[u-1]) << '\n';
    }
}
