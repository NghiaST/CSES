#include <iostream>
#include <vector>
using namespace std;
int n, avail[1<<15];
vector<int> Q;
 
int main()
{
    cin >> n;
    int x = 0;
    for(int i=1; i<n; ++i) cout << 0;
    while (!avail[x]) {
        cout << (x&1);
        avail[x] = true;
        Q.push_back(x);
        x <<= 1;
        if ((x>>n)&1) x ^= (1<<n);
        if (!avail[x^1]) x^=1;
        else if (!avail[x]);
        else break;
    }
}
