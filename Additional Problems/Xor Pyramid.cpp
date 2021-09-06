#include <iostream>
using namespace std;
int n, res, x;
 
int c2(int x) {
    int w = 0;
    while (x) w += x /= 2;
    return w;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> x;
        if (c2(i) + c2(n-1-i) == c2(n-1)) res ^= x;
    }
    cout << res;
}
