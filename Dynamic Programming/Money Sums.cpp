#include <iostream>
#include <cstring>
using namespace std;
const int N = 105;
int n, res, a[N], f[100005];
 
void Enter() {
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
}
 
void Process() {
    f[0] = 1;
    for(int i=1; i<=n; ++i)
        for(int j=100000; j; --j)
            if (j >= a[i]) f[j] |= f[j - a[i]];
    for(int i=1; i<=100000; ++i) if (f[i]) ++res;
    cout << res << '\n';
    for(int i=1; i<=100000; ++i) if (f[i]) cout << i << ' ';
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
