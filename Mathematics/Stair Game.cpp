#include <iostream>
using namespace std;
int t, n, x, y;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        x = 0;
        for(int i=0; i<n; ++i) {
            cin >> y;
            if (i&1) x ^= y;
        }
        cout << (x ? "first\n" : "second\n");
    }
}
