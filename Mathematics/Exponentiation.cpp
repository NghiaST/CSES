#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;
long long t, n, k;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        long long w = 1;
        while (k) {
            if (k&1) w = w*n%MOD;
            k>>=1;
            n=n*n%MOD;
        }
        cout << w << '\n';
    }
}
