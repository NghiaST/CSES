#include <iostream>
#include <iomanip>
using namespace std;
int n, k;
long double res;
 
int main()
{
    cin >> n >> k;
    for(int i=1; i<=k; ++i) {
        long double x = 1, y = 1;
        for(int j=1; j<=n; ++j) {
            x = x * i / k;
            y = y * (i - 1) / k;
        }
        res += i * (x - y);
    }
    cout << setprecision(6) << fixed << res;
}
