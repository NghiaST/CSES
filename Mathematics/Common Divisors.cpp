#include <iostream>
using namespace std;
int n, x, res, f[1000005];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    while (n--) {
        cin >> x;
        ++f[x];
    }
    for(int i=1; i<=1000000; ++i) {
        x = 0;
        for(int j=i; j<=1000000; j+=i) x += f[j];
        if (x > 1) res = i;
    }
    cout << res;
}
