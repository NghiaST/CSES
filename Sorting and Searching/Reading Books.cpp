#include <iostream>
using namespace std;
const int N = 200005;
int n, a[N];
long long x, maxi, res;
 
void Enter() {
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> x, res += x, maxi = max(maxi, x);
}
 
void Process() {
    cout << max(maxi*2, res);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
