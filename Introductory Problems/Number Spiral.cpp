#include <iostream>
using namespace std;
long long t, x, y;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> x >> y;
        if (max(x,y)&1) {
            if (x > y) cout << (x-1)*(x-1) + y << '\n';
             else cout << y*y - x + 1 << '\n';
        }
        else {
            if (x < y) cout << (y-1)*(y-1) + x << '\n';
             else cout << x*x - y + 1 << '\n';
        }
    }
}
