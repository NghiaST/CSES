#include <iostream>
#include <vector>
using namespace std;
vector<string> ans;
int n;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    ans.push_back("0");
    ans.push_back("1");
    for(int i=2; i<=n; ++i)
        for(int j=(1<<(i-1))-1; j>=0; --j) {
            ans.push_back(ans[j] + "1");
            ans[j] += "0";
        }
    for(string v : ans) cout << v << '\n';
}
