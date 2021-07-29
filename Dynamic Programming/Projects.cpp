#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200005;
int n, b[N];
long long f[N];
struct Data{
    int x, y, z;
    bool operator < (Data &p) { return y < p.y; }
} a[N];
 
void Enter() {
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i].x >> a[i].y >> a[i].z;
    sort(a+1, a+n+1);
    for(int i=1; i<=n; ++i) b[i] = a[i].y;
}
 
void Process() {
    for(int i=1; i<=n; ++i) {
        f[i] = max(f[i-1], f[lower_bound(b+1, b+i, a[i].x) - b - 1] + a[i].z);
    }
    cout << f[n];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
