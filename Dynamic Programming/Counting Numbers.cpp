#include <iostream>
#include <algorithm>
#define getBIT(x,i) ((x>>(i))&1)
#define xorBIT(x,i) (x ^ (1<<(i)))
using namespace std;
long long L, R, f[20][10][2];
 
void Enter() {
    cin >> L >> R;
}
 
long long get(long long x) {
    string s = "0" + to_string(x);
    int sz = s.length() - 1;
    if (x < 0) return 0;
    f[0][0][1] = 1;
    for(int i=1; i<=sz; ++i) {
        for(int j=0; j<=9; ++j) {
            f[i][j][0] = f[i][j][1] = 0;
            for(int w=0; w<=9; ++w) if (j != w) {
                f[i][j][0] += f[i-1][w][0];
                if (s[i] - '0' == j) f[i][j][1] += f[i-1][w][1];
                if (s[i] - '0' > j) f[i][j][0] += f[i-1][w][1];
            }
        }
        ++f[i][0][0];
    }
    long long sum = 0;
    for(int i=0; i<=9; ++i) sum += f[sz][i][0] + f[sz][i][1];
    return sum;
}
 
void Process() {
    cout << get(R) - get(L - 1);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
