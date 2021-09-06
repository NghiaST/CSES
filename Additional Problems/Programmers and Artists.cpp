#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, A, B;
long long sumA[200005], sumB[200005], res;
priority_queue<int, vector<int>, greater<int>> Q;
struct Data{
    int x, y;
    bool operator < (Data &p) { return y - x < p.y - p.x; }
} a[200005];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> A >> B >> n;
    for(int i=1; i<=n; ++i) cin >> a[i].x >> a[i].y;
    sort(a+1, a+n+1);
    for(int i=1; i<=n; ++i) {
        Q.push(a[i].x);
        sumA[i] = sumA[i-1] + a[i].x;
        if (i > A) sumA[i] -= Q.top(), Q.pop();
    }
    while (!Q.empty()) Q.pop();
    for(int i=n; i; --i) {
        Q.push(a[i].y);
        sumB[i] = sumB[i+1] + a[i].y;
        if (i <= n - B) sumB[i] -= Q.top(), Q.pop();
    }
    for(int i=A; i<=n-B; ++i) res = max(res, sumA[i] + sumB[i+1]);
    cout << res;
}
