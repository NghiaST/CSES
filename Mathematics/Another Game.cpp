#include <iostream>
using namespace std;
int t, n, x;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        bool ans = 0;
        while (n--) {
            cin >> x;
            if (x&1) ans = 1;
        }
        cout << (ans ? "first\n" : "second\n");
    }
}
