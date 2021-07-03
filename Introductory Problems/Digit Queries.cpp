#include <iostream>
using namespace std;
long long t, n;
long long w[20], pow[20];
 
void Init() {
    pow[0] = 1;
    for(long long pw=9, i=1; w[i-1] <= 1e18; ++i) {
        w[i] = w[i-1] + pw * i;
        pow[i] = pow[i-1] * 10;
        pw *= 10;
    }
}
 
void get(long long x) {
    int i = 1;
    while (w[i] < n) ++i;
    n -= w[i-1];
    long long du = (n-1)%i;
    n = (n-1)/i + pow[i-1];
    long long pw = pow[i-1];
    while (du--) n %= pw, pw /= 10;
    cout << n / pw << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Init();
    cin >> t;
    while (t--) {
        cin >> n;
        get(n);
    }
}
