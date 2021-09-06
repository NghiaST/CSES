#include <iostream>
using namespace std;
int t, n, k;
 
int get(int x, int k) {
    if (k*2 <= x) return k*2;
    int w = get(x/2, k - (x+1)/2);
    if (x & 1) return w * 2 + 1;
    else return w * 2 - 1;
}
 
int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << get(n, k) << '\n';
    }
}
