#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = 200005;
int n, k, x;
long long sum, res;
map<long long, int> M;
 
void Enter() {
    cin >> n >> k;
}
 
void Process() {
    ++M[0];
    for(int i=1; i<=n; ++i) {
        cin >> x;
        sum += x;
        res += M[sum - k];
        ++M[sum];
    }
    cout << res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
