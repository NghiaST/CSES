#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = 200005;
int n, k, x;
long long sum, res;
map<long long, int> M;
 
void Enter() {
    cin >> n;
}
 
void Process() {
    ++M[0];
    for(int i=1; i<=n; ++i) {
        cin >> x;
        sum = ((sum + x) % n + n) % n;
        res += M[sum]++;
    }
    cout << res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
