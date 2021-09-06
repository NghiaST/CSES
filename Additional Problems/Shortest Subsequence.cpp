#include <iostream>
using namespace std;
int dem, w[256];
string s;
int main()
{
    getline(cin, s);
    for(int i=0; i<s.length(); ++i) {
        if (++w[s[i]] == 1) ++dem;
        if (dem == 4) {
            cout << s[i];
            dem = 0;
            w['A'] = w['C'] = w['G'] = w['T'] = 0;
        }
    }
    if (!w['A']) cout << 'A';
    else if (!w['C']) cout << 'C';
    else if (!w['G']) cout << 'G';
    else if (!w['T']) cout << 'T';
}
