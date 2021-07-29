#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 0x3c3c3c3c;
int n, a[105], f[1000005];
 
void Enter() {
    cin >> n;
}
 
void Process() {
    for(int i=1; i<=n; ++i) {
        f[i] = INF;
        for(int j=i; j; j/=10) f[i] = min(f[i], f[i-j%10] + 1);
    }
    cout << f[n];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
