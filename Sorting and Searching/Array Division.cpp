#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200005;
int n, k, a[N];
 
void Enter() {
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
}
 
bool check(long long x) {
    long long w = 0, cnt = 1;
    for(int i=1; i<=n; ++i) {
        if (a[i] > x) return false;
        if (w + a[i] <= x) w += a[i];
        else w = a[i], ++cnt;
    }
    return cnt <= k;
}
 
void Process() {
    long long l = 1, r = 1e15, mid = (l+r) / 2;
    while (l < r) {
        mid = (l+r) / 2;
        if (check(mid)) r = mid; else l = mid + 1;
    }
    cout << l;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
