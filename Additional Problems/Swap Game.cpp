#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <ctime>
using namespace std;
int n, cnt, a[9], w[9], exist[9], timer[400000];
vector<int> S[400000];
queue<int> Q;
 
struct node{
    node *c[9];
    int v;
    void New() {
        v = 0;
        for(int i=0; i<9; ++i) c[i] = NULL;
    }
} *root;
 
void build(node *&x, int h) {
    x = new node;
    x->New();
    if (h == 9) {
        x->v = ++cnt;
        return;
    }
    for(int i=0; i<9; ++i) if (!exist[i]) {
        exist[i] = true;
        build(x->c[i], h+1);
        exist[i] = false;
    }
}
 
int get_position(int w[]) {
    node *x = root;
    for(int i=0; i<9; ++i) x = x->c[w[i]];
    return x->v;
}
 
void Init() {
    build(root, 0);
    for(int i=0; i<9; ++i) w[i] = i;
    int p1 = 0, p2;
    do {
        ++p1;
        for(int i=0; i<2; ++i)
        for(int j=0; j<3; ++j) {
            swap(w[i*3+j], w[(i+1)*3+j]);
            p2 = get_position(w);
            swap(w[i*3+j], w[(i+1)*3+j]);
            S[p1].push_back(p2);
        }
        for(int i=0; i<3; ++i)
        for(int j=0; j<2; ++j) {
            swap(w[i*3+j], w[i*3+j+1]);
            p2 = get_position(w);
            swap(w[i*3+j], w[i*3+j+1]);
            S[p1].push_back(p2);
        }
    } while (next_permutation(w, w+9));
}
 
void Dijkstra() {
    int u = get_position(a);
    Q.push(u); timer[u] = 1;
    while (!timer[1] && !Q.empty()) {
        u = Q.front(); Q.pop();
        for(int v : S[u]) if (!timer[v]) {
            timer[v] = timer[u] + 1;
            Q.push(v);
        }
    }
    cout << timer[1] - 1;
}
 
int main()
{
    Init();
    for(int i=0; i<9; ++i) cin >> a[i], --a[i];
    Dijkstra();
}
