#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
const int N = 105;
int n;
long double a[N], res;
 
int main()
{
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i) {
        for(int j=0; j<i; ++j) {
            long double D;
            if (a[i] < a[j]) D = a[i] * (a[i] - 1) / 2 + (a[j] - a[i]) * a[i];
            else D = a[j] * (a[j] - 1) / 2;
            res += D / a[i] / a[j];
        }
    }
    cout << setprecision(6) << fixed << res << '\n';
}
