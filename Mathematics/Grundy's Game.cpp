#include <iostream>
int f[3005], w[6005], i, j;
main()
{
    while (++i < 3e3) {
        for(j=0; (++j)*2<i;) w[f[j] ^ f[i-j]] = i;
        while (w[f[i]] == i) ++f[i];
    }
    std::cin >> i;
    while (i--) {
        std::cin >> j;
        puts(j > 2e3 || f[j] ? "first" : "second");
    }
}
