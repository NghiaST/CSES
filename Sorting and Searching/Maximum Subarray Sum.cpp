#include <iostream>
#include <algorithm>
using namespace std;
long long n, x, sum, res;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    res = -9e9;
    while (n--) {
        cin >> x;
        sum += x;
        res = max(res, sum);
        if (sum < 0) sum = 0;
    }
    cout << res;
}
