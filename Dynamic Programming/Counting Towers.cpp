#include <iostream>
#include <algorithm>
#define getBIT(x,i) ((x>>(i))&1)
#define xorBIT(x,i) (x ^ (1<<(i)))
using namespace std;
const int MOD = 1e9 + 7;
int t, x, dp[1000005][2];
 
/**             _ _
    dp[i][0] : |   |
                _ _
    dp[i][1] : | | |
                   _ _     _ _     _ _
     _ _          |   |   |_|_|   |_ _|
    |   |   =>    |   | , |   | , |   |
 
                   _ _     _ _     _ _     _ _     _ _
     _ _          | | |   |_|_|   |_ _|   |_| |   | |_|
    | | |   =>    | | | , | | | , | | | , | | | , | | |
*/
 
void Init() {
    dp[1][0] = dp[1][1] = 1;
    for(int i=2; i<=1000000; ++i) {
        dp[i][0] = (dp[i-1][0] * 2ll + dp[i-1][1]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1] * 4ll) % MOD;
    }
}
 
void Process() {
    cin >> t;
    while (t--) {
        cin >> x;
        cout << (dp[x][0] + dp[x][1]) % MOD << '\n';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Init();
    Process();
}
