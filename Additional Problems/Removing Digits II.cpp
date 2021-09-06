#include <iostream>
#include <map>
#define pii pair<long long, long long>
using namespace std;
map<long long, pii> D[10];
long long n;
 
pii get(long long cMax, long long val) {
    if (val < 10) return {cMax || val, val - max(cMax, val)};
    if (D[cMax].count(val)) return D[cMax][val];
 
    long long p = 1;
    while (p <= val / 10) p *= 10;
    pii Z = get(max(cMax, val / p), val % p);
    pii Z2 = get(cMax, val / p * p + Z.second);
    return D[cMax][val] = {Z.first + Z2.first, Z2.second};
}
 
int main()
{
    cin >> n;
    cout << get(0, n).first;
}
