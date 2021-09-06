#include <iostream>
using namespace std;
int t, n;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        int x = 0, y;
        while (n--) cin >> y, x ^= y;
        cout << (x&3 ? "first\n" : "second\n");
    }
}
