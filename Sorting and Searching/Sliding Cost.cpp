#include <iostream>
#include <algorithm>
#include <set>
#define iter multiset<int>::iterator
using namespace std;
const int N = 200005;
int n, k, cL, cR, a[N];
long long ans[N], sum;
iter p;
multiset<int> S;
 
void Enter() {
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
}
 
iter prv(iter p) { return --p; }
 
void goR() {
    sum -= *(++p) * 2;
    ++cL; --cR;
}
 
void goL() {
    sum += *(p--) * 2;
    --cL; ++cR;
}
 
void Process() {
    S.insert(0);
    S.insert(1000000001);
    for(int i=1; i<=k; ++i) S.insert(a[i]);
 
    p = S.begin();
    cL = (k-1) / 2;
    cR = k / 2;
    for(int i=0; i<=cL; ++i) sum -= *(++p);
    iter w = p;
    for(int i=1; i<=cR; ++i) sum += *(++w);
    if (cL < cR) ++cL;
 
    ans[k] = sum + (k&1) * *p;
 
    for(int i=k+1; i<=n; ++i) {
        if (a[i-k] == *p) {
            goR();
            S.erase(prv(p));
        }
        else S.erase(a[i-k]);
        S.insert(a[i]);
        if (a[i-k] <= *p) {
            --cL;
            sum += a[i-k];
        }
        else {
            --cR;
            sum -= a[i-k];
        }
        if (a[i] < *p) {
            ++cL;
            sum -= a[i];
        }
        else {
            ++cR;
            sum += a[i];
        }
        if (cL < cR) goR();
        if (cL > cR) goL();
 
        ans[i] = sum + (k&1) * *p;
    }
    for(int i=k; i<=n; ++i) cout << ans[i] << ' ';
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
