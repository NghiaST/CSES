#include <iostream>
using namespace std;
long long n, res;
int main()
{
    cin >> n;
    for(long long i=0; 1ll<<i <= n; ++i) {
        res += n >> (i+1) << i;
        if ((n >> i) & 1) res += (((1ll<<i)-1) & n) + 1;
    }
    cout << res;
}
