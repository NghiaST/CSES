#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = 200005;
int n, k, dem, a[N];
long long res;
map<long long, int> M;
 
void Enter() {
    cin >> n >> k;
}
 
void Process() {
    ++M[0];
    for(int l=1, i=1; i<=n; ++i) {
        cin >> a[i];
        if (++M[a[i]] == 1) ++dem;
        while (dem > k) {
            if (--M[a[l++]] == 0) --dem;
        }
        res += i - l + 1;
    }
    cout << res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
