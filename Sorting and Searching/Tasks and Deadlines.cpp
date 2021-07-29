#include <iostream>
#include <algorithm>
#include <set>
#define pii pair<int,int>
using namespace std;
const int N = 200005;
int n, x, a[N];
long long res;
 
void Enter() {
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i] >> x, res += x;
}
 
void Process() {
    sort(a+1, a+n+1, greater<int>());
    for(long long i=1; i<=n; ++i) res -= i * a[i];
    cout << res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
