#include <iostream>
#include <algorithm>
#include <set>
#define iter multiset<int>::iterator
using namespace std;
const int N = 200005;
int n, k, res;
pair<int,int> a[N];
multiset<int> S;
 
void Enter() {
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i].first >> a[i].second;
    sort(a+1, a+n+1);
}
 
void Process() {
    for(int i=1; i<=k; ++i) S.insert(0);
    for(int i=1; i<=n; ++i) {
        if (*S.begin() <= a[i].first) {
            S.erase(S.begin());
            S.insert(a[i].second);
            ++res;
        }
        else if (*S.rbegin() > a[i].second) {
            S.erase(--S.end());
            S.insert(a[i].second);
        }
    }
    cout << res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
