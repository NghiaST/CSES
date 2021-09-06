#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
using namespace std;
const double PI = 3.14159265358979323;
typedef complex<double> base;
typedef vector<base> VB;
string s;
int n, m, bit;
long long r0;
 
int revert(int x) {
    int y = 0;
    for(int i=0; i<bit; ++i) {
        y = (y<<1) | (x&1);
        x >>= 1;
    }
    return y;
}
 
 
void FFT(VB &a, bool invert) {
    for(int i=0; i<n; ++i) {
        int j = revert(i);
        if (i < j) swap(a[i], a[j]);
    }
    VB anext(n), W(n);
 
    for(int step = 1; step < n; step <<= 1) {
        double z = PI / step * (invert ? -1 : 1);
        base w(1), wn(cos(z), sin(z));
        for(int i=0; i<step; ++i) {
            W[i] = w;
            w *= wn;
        }
        for(int even = 0, odd = step; even < n; even += step * 2, odd += step * 2) {
            for(int i=0; i<step; ++i) {
                anext[even + i] = a[even + i] + a[odd + i] * W[i];
                anext[odd + i] = a[even + i] - a[odd + i] * W[i];
                if (invert) {
                    anext[odd + i] /= 2;
                    anext[even + i] /= 2;
                }
            }
        }
        a = anext;
    }
}
 
int main()
{
    getline(cin, s);
    m = s.length();
    bit = ceilf(log2(m*2 + 1));
    n = 1 << bit;
    VB A(n), B(n);
    A[0] += 1;
    for(int i=0, w=0; i<m; ++i) {
        w += (s[i] == '1');
        A[w] += 1;
    }
    for(int i=0; i<=m; ++i) B[i] = A[m - i];
    FFT(A, false);
    FFT(B, false);
    for(int i=0; i<n; ++i) A[i] *= B[i];
    FFT(A, true);
    r0 = 1LL * m * (m+1) / 2;
    for(int i=m+1; i<=m*2; ++i) r0 -= (long long) roundf(A[i].real());
    cout << r0 << ' ';
    for(int i=m+1; i<=m*2; ++i) cout << (long long) roundf(A[i].real()) << ' ';
}
