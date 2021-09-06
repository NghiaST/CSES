#include <iostream>
const int M = 1e9 + 7;
long n, i, x, y, z;
 
int main()
{
    std::cin >> n;
    x = (n > 1);
    for(i=2; i<n; ++i) {
        z = (x + y) * i % M;
        y = x; x = z;
    }
    std::cout << x;
}
