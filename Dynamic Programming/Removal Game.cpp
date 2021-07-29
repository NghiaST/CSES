#include <iostream>
#include <cstring>
using namespace std;
const int N = 5005;
int n, a[N], ok[N][N];
long long sum, f[N][N];
 
void Enter() {
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i], sum += a[i];
}
 
long long get(int l, int r) {
    if (l == r) return a[l];
    if (l > r) return 0;
    if (ok[l][r]) return f[l][r];
    ok[l][r] = true;
    return f[l][r] = max(a[l] - get(l+1, r), a[r] - get(l, r-1));
}
 
void Process() {
    cout << (sum + get(1, n)) / 2;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
