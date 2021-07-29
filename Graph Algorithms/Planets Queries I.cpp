#include <iostream>
#define F(i,r) for(int i=0; i<r; ++i)
#define I std::cin >>
int n, q, x, p[1<<18][32];
 
main()
{
    I n >> q;
    F(i,n) I p[i+1][0];
    F(i,31) F(j,n) p[j+1][i+1] = p[p[j+1][i]][i];
    while (q--) {
        I n >> x;
        F(i,31)
            if (x>>i&1) n = p[n][i];
        std::cout << n << '\n';
    }
}
