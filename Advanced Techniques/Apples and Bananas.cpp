#include <iostream>
#include <vector>
#include <complex>
using namespace std;
const double PI = 3.141592653589793238462;
typedef complex<double> base;
typedef vector<base> vb;
int n, m, k, logN, leng;
vb A, B;
 
int reverse_BIT(int x) {
    int w = 0;
    for(int i=0; i<logN; ++i) {
        w = (w<<1) | (x&1);
        x >>= 1;
    }
    return w;
}
 
void FFT(vb &a, bool invert) {
    vb anext(leng), W(leng);
 
    for(int i=0; i<leng; ++i) {
        int j = reverse_BIT(i);
        if (i < j) swap(a[i], a[j]);
    }
 
    for(int step = 1; step < leng; step <<= 1) {
        double ang = PI / step * (invert ? -1 : 1);
        base w(1), wn(cos(ang), sin(ang));
 
        for(int i = 0; i < step; ++i) {
            W[i] = w;
            w *= wn;
        }
 
        for(int even = 0, odd = even + step; even < leng; even += step * 2, odd += step * 2) {
            for(int i = 0; i < step; ++i) {
                anext[even + i] = a[even + i] + W[i] * a[odd + i];
                anext[odd + i] = a[even + i] - W[i] * a[odd + i];
                if (invert) {
                    anext[even + i] /= 2;
                    anext[odd + i] /= 2;
                }
            }
        }
 
        for(int i = 0; i < leng; ++i) a[i] = anext[i];
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> k >> n >> m;
    logN = (int) ceilf(log2(k) + 1);
    leng = 1 << logN;
    A.resize(leng);
    B.resize(leng);
    int x;
    for(int i=0; i<n; ++i) cin >> x, A[--x] += 1;
    for(int i=0; i<m; ++i) cin >> x, B[--x] += 1;
    FFT(A, false);
    FFT(B, false);
    for(int i=0; i<leng; ++i) A[i] *= B[i];
    FFT(A, true);
    for(int i=0; i<=(k-1)*2; ++i) cout << (long long) round(A[i].real()) << ' ';
}
