#include <iostream>
#include <queue>
using namespace std;
int n, x;
long long res;
priority_queue<int> Q;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    while (n--) {
        cin >> x;
        Q.push(x);
        res += Q.top() - x;
        Q.pop(); Q.push(x);
    }
    cout << res;
}
