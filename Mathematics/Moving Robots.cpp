#include <iostream>
#include <cstring>
using namespace std;
const int Gx[4] = {0, 1, 0, -1}, Gy[4] = {1, 0, -1, 0};
int n;
long double res, f[105][8][8], direct[8][8], ans[8][8];
 
int main()
{
    scanf("%d", &n);
    for(int i=0; i<8; ++i)
    for(int j=0; j<8; ++j) {
        ans[i][j] = 1;
        for(int w=0; w<4; ++w) {
            int u = i + Gx[w];
            int v = j + Gy[w];
            if (0 <= u && u < 8 && 0 <= v && v < 8) ++direct[i][j];
        }
    }
    for(int x=0; x<8; ++x)
    for(int y=0; y<8; ++y) {
        memset(f, 0, sizeof(f));
        f[0][x][y] = 1;
        for(int k=1; k<=n; ++k) {
            for(int i=0; i<8; ++i)
            for(int j=0; j<8; ++j) {
                for(int w=0; w<4; ++w) {
                    int u = i + Gx[w];
                    int v = j + Gy[w];
                    if (0 <= u && u < 8 && 0 <= v && v < 8)
                    f[k][u][v] += f[k-1][i][j] / direct[i][j];
                }
            }
        }
        for(int i=0; i<8; ++i)
        for(int j=0; j<8; ++j)
            ans[i][j] *= 1 - f[n][i][j];
    }
    for(int i=0; i<8; ++i)
    for(int j=0; j<8; ++j)
        res += ans[i][j];
    printf("%.6Lf", res);
}
