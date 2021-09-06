/// mobius function
#include <iostream>
#include <algorithm>
using namespace std;
int n, x, cnt[1000005], pr[1000005], mobius[1000005];
long long res;
 
void min_prime_factor() {
    for(int i=2; i<=1000000; ++i) {
        if (!pr[i]) {
            for(int j=i; j<=1000000; j+=i)
                if (!pr[j]) pr[j] = i;
        }
    }
}
 
void Mobius_function() {
    mobius[1] = 1;
    for(int i=2; i<=1000000; ++i)
        if (pr[i] != pr[i / pr[i]]) mobius[i] = -mobius[i / pr[i]];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    while (n--) cin >> x, ++cnt[x];
    min_prime_factor();
    Mobius_function();
    for(int i=1; i<=1000000; ++i) if (mobius[i]) {
        long long w = 0;
        for(int j=i; j<=1000000; j+=i) w += cnt[j];
        res += w * (w-1) / 2 * mobius[i];
    }
    cout << res;
}
