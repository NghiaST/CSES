#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = 1005;
int n;
long long x;
map<long long, pair<int,int>> List;
pair<long long,int> a[N];
 
void Enter() {
    cin >> n >> x;
    for(int i=1; i<=n; ++i) cin >> a[i].first, a[i].second = i;
}
 
void Process() {
    sort(a+1, a+n+1);
    for(int i=1; i<=n; ++i) {
        for(int j=i+1; j<=n; ++j) {
            if (List.count(x - a[i].first - a[j].first)) {
                cout << a[i].second << ' ' << a[j].second << ' '
                     << List[x - a[i].first - a[j].first].first << ' ' << List[x - a[i].first - a[j].first].second;
                exit(0);
            }
        }
        for(int j=1; j<i; ++j) List[a[i].first + a[j].first] = {a[i].second, a[j].second};
    }
    cout << "IMPOSSIBLE";
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
