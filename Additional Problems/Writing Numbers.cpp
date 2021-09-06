#include <iostream>
using namespace std;
long long n, l, r, mid, d[10];
 
bool check(long long x) {
    for(int i=1; i<10; ++i) {
        d[i] = 0;
        for(long long multiply=1, sum=0, j=x; j; ) {
            if (i < j%10) d[i] += multiply;
            if (i == j%10) d[i] += sum + 1;
            sum += j%10 * multiply;
            j /= 10;
            if (j > 0) d[i] += (j - (i==0)) * multiply;
            multiply *= 10;
        }
    }
    for(int i=1; i<10; ++i) if (d[i] > n) return false;
    return true;
}
 
int main()
{
    cin >> n;
    l = 1, r = 6e17;
    while (l < r) {
        mid = (l+r+1) / 2;
        if (check(mid)) l = mid; else r = mid - 1;
    }
    cout << l;
}
