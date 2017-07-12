#include<iostream>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<algorithm>
#include<deque>
#include<queue>
#include<string>
#include<stack>
#include<iomanip>
#include<fstream> 
#include<ctime>
#define lli long long int
using namespace std;
 
lli n, l;
vector < vector<lli> > g;
vector<lli> tin, tout;
lli timer=0;
vector < vector<lli> > up;
 
void dfs(lli v, lli p = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (lli i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];
    for (lli i = 0; i<g[v].size(); ++i) {
        lli to = g[v][i];
        if (to != p)
            dfs(to, v);
    }
    tout[v] = ++timer;
}
 
bool upper(lli a, lli b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}
 
int lca(lli a, lli b) {
    if (upper(a, b))  return a;
    if (upper(b, a))  return b;
    for (lli i = l; i >= 0; --i)
        if (!upper(up[a][i], b))
            a = up[a][i];
    return up[a][0];
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("evacuation.in", "r", stdin);
    //freopen("evacuation.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n;
    cin >> n;
    g.resize(n, vector<lli>());
    for (lli i = 1; i < n; i++) {
        lli p;
        cin >> p;
        g[--p].push_back(i);
    }
    tin.resize(n), tout.resize(n), up.resize(n);
    l = 1;
    while ((1 << l) <= n)  ++l;
    for (int i = 0; i<n; ++i)  up[i].resize(l + 1);
    dfs(0);
    lli m;
    cin >> m;
    for (lli q = 0; q < m;q++) {
        lli a, b;
        cin >> a >> b;
        cout << lca(--a, --b)+1 << "\n";
    }
}