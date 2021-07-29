#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
const int N = 200005;
int n, len, L, R;
long long a[N], res;
deque<int> Q;
 
void Enter() {
    cin >> n >> L >> R;
    len = R - L + 1;
    for(int i=1; i<=n; ++i) cin >> a[i], a[i] += a[i-1];
}
 
void Process() {
    res = -1e18;
    for(int i=0; i+L<=n; ++i) {
        while (!Q.empty() && a[Q.back()] >= a[i]) Q.pop_back();
        while (!Q.empty() && Q.front() <= i - len) Q.pop_front();
        Q.push_back(i);
        res = max(res, a[i + L] - a[Q.front()]);
    }
    cout << res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
