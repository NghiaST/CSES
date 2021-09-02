/// Alien's trick
/// https://rezwanarefin01.github.io/posts/ioi16-aliens-trick/
/// Complexity : O(N * log Sum(Ai^2))
#include <iostream>
using namespace std;
const int N = 3005;
int n, k, lft, rgt, timer[N];
long long a[N], dp[N];

struct Data{
    long long x, y, z;
    long long get(long long val) {
        return x * val + y;
    }
} Q[N];

bool check(Data a, Data b, Data c) {
    return (a.y - b.y) * (c.x - a.x) >= (b.x - a.x) * (a.y - c.y);
}

void update(int u, long long C) {
    Data w = {-2 * a[u], dp[u] + a[u] * a[u] + C, timer[u]};
    while (rgt > lft && check(Q[rgt - 1], Q[rgt], w)) --rgt;
    Q[++rgt] = w;
}

long long query(long long val) {
    while (rgt > lft && Q[lft].get(val) > Q[lft+1].get(val)) ++lft;
    return Q[lft].get(val);
}

pair<long long, int> solve(long long C) {
    lft = 1, rgt = 0;
    update(0, C);
    for(int i=1; i<=n; ++i) {
        dp[i] = query(a[i]) + a[i] * a[i];
        timer[i] = Q[lft].z + 1;
        update(i, C);
    }
    return {dp[n], timer[n]};
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i], a[i] += a[i-1];
    long long lft = 0, rgt = 1e15, mid;
    while (lft < rgt) {
        mid = (lft + rgt) / 2;
        if (solve(mid).second <= k) rgt = mid;
        else lft = mid + 1;
    }
    cout << solve(lft).first - k * lft;
}
