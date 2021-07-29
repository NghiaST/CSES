#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
const int MOD = 1e9 + 7;
int n, f[1000005];
deque<int> Q;
 
void Enter() {
    cin >> n;
}
 
void Process() {
    f[0] = 1;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=6 && i-j>=0; ++j) f[i] = (f[i-j] + f[i]) % MOD;
    }
    cout << f[n];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
