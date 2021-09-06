#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200005;
int n, a[N], b[N], bitL[N], bitR[N];
long long res;
 
void updateL(int x) {
    for(; x<=n; x+=x&-x) ++bitL[x];
}
 
void updateR(int x) {
    for(; x; x-=x&-x) ++bitR[x];
}
 
int queryL(int x) {
    int val = 0;
    for(; x; x-=x&-x) val += bitL[x];
    return val;
}
 
int queryR(int x) {
    int val = 0;
    for(; x<=n; x+=x&-x) val += bitR[x];
    return val;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i], b[i] = i;
    sort(b+1, b+n+1, [] (int A, int B) { return a[A] < a[B]; });
    for(int i=1; i<=n; ++i) a[b[i]] = i;
    for(int i=1; i<=n; ++i) {
            int L = b[i] - 1 - queryL(b[i]);
            int R = n - b[i] - queryR(b[i]);
        res += min(b[i] - 1 - queryL(b[i]), n - b[i] - queryR(b[i]));
        updateL(b[i]);
        updateR(b[i]);
    }
    cout << res;
}
