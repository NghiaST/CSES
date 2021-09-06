#include <iostream>
using namespace std;
int t, n, k;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (k * k >= n) {
            while (n > 0) {
                for(int i=max(1, n-k+1); i<=n; ++i) cout << i << ' ';
                n -= k;
            }
            cout << '\n';
        }
        else cout << "IMPOSSIBLE\n";
    }
}
