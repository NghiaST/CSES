#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;
long long n, f[5005];
string s, w;
 
struct node{
    int cnt;
    node *p[26];
};
node *root;
 
void New(node *&x) {
    x = new node;
    x->cnt = 0;
    for(int i=0; i<26; ++i) x->p[i] = NULL;
}
 
void add(string w) {
    node *x = root;
    for(int i=w.length()-1; i>=0; --i) {
        if (x->p[w[i] - 'a'] == NULL) New(x->p[w[i] - 'a']);
        x = x->p[w[i] - 'a'];
    }
    ++x->cnt;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    New(root);
    cin >> s >> n;
    for(int i=1; i<=n; ++i) {
        cin >> w;
        add(w);
    }
    f[0] = 1;
    for(int i=0; i<s.length(); ++i) {
        node *x = root;
        for(int j=i; j>=0; --j) {
            if (x->p[s[j] - 'a'] == NULL) break;
            x = x->p[s[j] - 'a'];
            f[i+1] = (f[i+1] + f[j] * x->cnt) % MOD;
        }
    }
    cout << f[s.length()];
}
