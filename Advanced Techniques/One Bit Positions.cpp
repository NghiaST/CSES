#include <iostream>
#include <vector>
#include <complex>
using namespace std;
const double PI = 3.141592653589793238462;
typedef complex<double> base;
typedef vector<base> vb;
int n, logN, leng;
string s;
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
    getline(cin, s);
    n = s.length();
    logN = (int) ceilf(log2(n) + 1);
    leng = 1 << logN;
    A.resize(leng);
    B.resize(leng);
    for(int i=0; i<n; ++i) if (s[i] == '1') {
        A[i] = 1;
        B[n - i] = 1;
    }
    FFT(A, false);
    FFT(B, false);
    for(int i=0; i<leng; ++i) A[i] *= B[i];
    FFT(A, true);
    for(int i=n+1; i<n*2; ++i) cout << (long long) round(A[i].real()) << ' ';
}
