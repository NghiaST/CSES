#include <iostream>
using namespace std;
int t, m, n, m2, n2, cnt, c[9], a[105][105];
 
void color(int x, int y) {
    ++c[a[x][y-1]];
    ++c[a[x][y+1]];
    ++c[a[x-1][y]];
    ++c[a[x+1][y]];
}
 
void add(int x, int y, int fx, int fy) {
    for(int i=1; i<=8; ++i) c[i] = 0;
    color(x, y);
    color(x + fx, y);
    color(x, y + fy);
    int i;
    for(i=1; i<=8; ++i) if (c[i] == 0) break;
    a[x][y] = a[x + fx][y] = a[x][y + fy] = i;
}
 
void Set2x3(int x, int y) {
    add(x, y, 1, 1);
    add(x+1, y+2, -1, -1);
}
 
void Set3x2(int x, int y) {
    add(x, y, 1, 1);
    add(x+2, y+1, -1, -1);
}
 
void Set5x9(int x, int y) {
    Set3x2(x, y);
    Set2x3(x, y+2);
    Set3x2(x, y+5);
    Set3x2(x, y+7);
    Set2x3(x+3, y+6);
    add(x+4, y, -1, 1);
    add(x+3, y+2, -1, -1);
    add(x+2, y+4, 1, -1);
    add(x+4, y+3, -1, -1);
    add(x+4, y+5, -1, -1);
}
 
void Set2xn(int x, int y, int y2) {
    for(int i=y; i<=y2; i+=3) Set2x3(x, i);
}
 
void Setnx2(int x, int y, int x2) {
    for(int i=x; i<=x2; i+=3) Set3x2(i, y);
}
 
void Set3xn(int x, int y, int y2) {
    for(int i=y; i<=y2; i+=2) Set3x2(x, i);
}
 
void Setmxn(int m, int n) {
    bool ok = false;
    if (n%3!=0 || n%3==0 && m%3==0 && m>n) ok = true, swap(m, n);
    if (m%2 != 0) {
        if (n%2 == 0) {
            while (m > 3) Set2xn(m - 1, 1, n), m -= 2;
            Set3xn(1, 1, n);
        }
        else {
            while (m > 9) Set2xn(m - 1, 1, n), m -= 2;
            while (n > 9) Setnx2(1, n - 1, m), n -= 2;
            while (m > 5) Set2xn(m - 1, 1, n), m -= 2;
            Set5x9(1, 1);
        }
    }
    else {
        while (m > 0) Set2xn(m - 1, 1, n), m -= 2;
    }
    if (ok) {
        for(int i=1; i<=max(m2,n2); ++i)
        for(int j=i+1; j<=max(m2,n2); ++j) swap(a[i][j], a[j][i]);
    }
}
 
int main()
{
    cin >> t;
    while (t--) {
        cin >> m >> n; m2 = m; n2 = n;
        if (min(m,n) == 1 || min(m,n) <= 3 && m*n%6 || m*n%3) {
            puts("NO");
            continue;
        }
        puts("YES");
        Setmxn(m, n);
        for(int i=1; i<=m; ++i) {
            for(int j=1; j<=n; ++j) putchar(a[i][j] + 'A');
            putchar('\n');
        }
        for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j) a[i][j] = 0;
    }
}
