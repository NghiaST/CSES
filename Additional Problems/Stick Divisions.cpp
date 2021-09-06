#include <iostream>
#include <queue>
using namespace std;
long long k, n, x, res;
priority_queue<long long, vector<long long>, greater<long long>> Q;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> k >> n;
    for(int i=0; i<n; ++i) cin >> x, Q.push(x);
    while (--n) {
        long long x = Q.top(); Q.pop();
        long long y = Q.top(); Q.pop();
        res += x + y;
        Q.push(x + y);
    }
    cout << res;
}
