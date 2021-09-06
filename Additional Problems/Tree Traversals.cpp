#include <iostream>
using namespace std;
const int N = 100005;
int n, w, a[N], pos[N], ans[N];
 
void Solve(int La, int Lpos, int leng) {
    if (leng == 0) return;
    int leng_L = pos[a[La]] - Lpos;
    Solve(La + 1, Lpos, leng_L);
    Solve(La + leng_L + 1, Lpos + leng_L + 1, leng - leng_L - 1);
    ans[++w] = a[La];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    int x;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) cin >> x, pos[x] = i;
    Solve(1, 1, n);
    for(int i=1; i<=w; ++i) cout << ans[i] << ' ';
}
