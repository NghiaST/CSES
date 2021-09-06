#include <iostream>
using namespace std;
int n, cnt;
long long ans1, ans2, ans3, ans4;
int a[200005], Q[200005], choice[200005], bit[200005];
 
void update(int x) {
    for(; x; x-=x&-x) ++bit[x];
}
 
int query(int x) {
    int val = 0;
    for(++x; x<=n; x+=x&-x) val += bit[x];
    return val;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
 
    ans4 = n;
    for(int i=n; i; --i)
        if (a[i] == ans4) --ans4;
 
    for(int i=1; i<=n; ++i) {
        if (a[i] > Q[cnt]) Q[++cnt] = a[i];
        else *lower_bound(Q+1, Q+cnt+1, a[i]) = a[i];
    }
    ans3 = n - cnt;
 
    for(int i=1; i<=n; ++i) if (!choice[i]) {
        int dem = -1;
        for(int j=i; !choice[j]; j=a[j]) ++dem, choice[j] = 1;
        ans2 += dem;
    }
 
    for(int i=1; i<=n; ++i) {
        ans1 += query(a[i]);
        update(a[i]);
    }
 
    cout << ans1 << ' ' << ans2 << ' ' << ans3 << ' ' << ans4;
}
