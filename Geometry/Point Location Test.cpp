#include <iostream>
using namespace std;
const long long MOD = 1e9 + 7;
int t;
struct point{long long x, y;} a, b, c;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        long long w = a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y);
        if (w < 0) cout << "LEFT\n";
        else if (w > 0) cout << "RIGHT\n";
        else cout << "TOUCH\n";
    }
}
