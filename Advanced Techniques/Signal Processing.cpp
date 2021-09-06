#include <iostream>
#include <complex>
#include <vector>
using namespace std;
const double PI = 3.14159265358979323;
typedef complex<double> base;
typedef vector<base> vb;
vb A, B;
int n, m, Lg, SZ;
 
int reverse_BIT(int x) {
    int y = 0;
    for(int i=0; i<Lg; ++i) {
        (y<<=1) |= (x&1);
        x >>= 1;
    }
    return y;
}
 
void FFT(vb &a, bool invert) {
    for(int i=0; i<SZ; ++i) {
        int j = reverse_BIT(i);
        if (i < j) swap(a[i], a[j]);
    }
 
    vb anext(SZ), W(SZ);
    for(int step = 1; step < SZ; step <<= 1) {
        double ang = PI / step * (invert ? -1 : 1);
        base w(1), wn(cos(ang), sin(ang));
 
        for(int i=0; i<step; ++i) {
            W[i] = w;
            w *= wn;
        }
 
        for(int even = 0, odd = even + step; even < SZ; even += step * 2, odd = even + step) {
            for(int i=0; i<step; ++i) {
                anext[i + even] = a[even + i] + W[i] * a[odd + i];
                anext[i + odd] = a[even + i] - W[i] * a[odd + i];
                if (invert) {
                    anext[i + even] /= 2;
                    anext[i + odd] /= 2;
                }
            }
        }
        a = anext;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    Lg = ceilf(log2(n + m - 1));
    SZ = 1 << Lg;
    A.resize(SZ); B.resize(SZ);
    for(int i=0; i<n; ++i) cin >> A[i];
    for(int i=m-1; i>=0; --i) cin >> B[i];
    FFT(A, false);
    FFT(B, false);
    for(int i=0; i<SZ; ++i) A[i] *= B[i];
    FFT(A, true);
    for(int i=0; i<n+m-1; ++i) cout << (long long) round(A[i].real()) << ' ';
}
