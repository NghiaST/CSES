#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200005;
int n;
long long x;
pair<long long,int> a[N];
 
void Enter() {
    cin >> n >> x;
    for(int i=1; i<=n; ++i) cin >> a[i].first, a[i].second = i;
}
 
void Process() {
    sort(a+1, a+n+1);
    for(int i=1; i<=n; ++i) {
        for(int j=i+1, r=n; j<r; ++j) {
            while (r > j && a[i].first + a[j].first + a[r].first > x) --r;
            if (r == j) break;
            if (a[i].first + a[j].first + a[r].first == x) {
                cout << a[i].second << ' ' << a[j].second << ' ' << a[r].second;
                exit(0);
            }
        }
    }
    cout << "IMPOSSIBLE";
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
