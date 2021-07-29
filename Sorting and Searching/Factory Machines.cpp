#include <iostream>
#include <algorithm>
#include <set>
#define pii pair<int,int>
using namespace std;
const int N = 200005;
int n, a[N];
long long k;
 
void Enter() {
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
}
 
bool check(long long x) {
    long long sum = 0;
    for(int i=1; i<=n; ++i) if ((sum += x / a[i]) >= k) return true;
    return false;
}
 
void Process() {
    long long l = 1, r = 1e18, mid;
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
