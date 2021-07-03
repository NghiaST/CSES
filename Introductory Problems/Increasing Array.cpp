#include <iostream>
using namespace std;
int n, px, x;
long long res;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    while (n--) {
        cin >> x;
        if (px > x) res += px - x; else px = x;
    }
    cout << res;
}
