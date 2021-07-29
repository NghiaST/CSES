#include <iostream>
#include <algorithm>
#define getBIT(x,i) ((x>>i)&1)
#define offBIT(x,i) (x ^ (1<<i))
using namespace std;
const int N = 1048580;
int n, W, a[25];
struct Data{
    int cnt, w;
    bool operator < (Data &p) { return cnt < p.cnt || cnt == p.cnt && w < p.w; }
} dp[N];
 
void Enter() {
    cin >> n >> W;
    for(int i=0; i<n; ++i) cin >> a[i];
}
 
void Process() {
    dp[0].cnt = 1;
    for(int i=1; i<(1<<n); ++i) {
        dp[i].cnt = n;
        for(int j=0; j<n; ++j) if (getBIT(i, j)) {
            Data p = dp[offBIT(i, j)];
            p.w += a[j];
            if (p.w > W) {
                ++p.cnt;
                p.w = a[j];
            }
            if (p < dp[i]) dp[i] = p;
        }
    }
    cout << dp[(1<<n)-1].cnt;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
