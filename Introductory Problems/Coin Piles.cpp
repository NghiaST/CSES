#include <iostream>
using namespace std;
int t, x, y;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> x >> y;
        if ((x + y) % 3 != 0 || x > 2*y || y > 2*x) cout << "NO\n";
        else cout << "YES\n";
    }
}
