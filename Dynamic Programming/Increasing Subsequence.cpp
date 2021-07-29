#include <iostream>
#include <algorithm>
using namespace std;
int n, r, x, Q[200005];
 
void Enter() {
    cin >> n;
}
 
void Process() {
    for(int i=1; i<=n; ++i) {
        cin >> x;
        if (!r || Q[r] < x) Q[++r] = x;
        else *lower_bound(Q+1, Q+r, x) = x;
    }
    cout << r;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
