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
 
const int N = 100009;
 
int comp;
int c[N];
int cap[N];
 
int deg[N];
 
vector<bool> used;
 
vector<vector<lli>> g,r;
vector<lli> order;
 
void dfs(int v) {
    used[v] = 1;
    for (auto now : g[v]) {
        if (!used[now]) {
            dfs(now);
        }
    }
    order.push_back(v);
}
 
void go(int v) {
    c[v] = comp;
    cap[comp] = v;
    for (int to : r[v]) {
        if (!c[to]) {
            go(to);
        }
    }
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("firesafe.in", "r", stdin);
    freopen("firesafe.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n, m;
    cin >> n >> m;
    g.resize(n, vector<lli>());
    r.resize(n, vector<lli>());
    for (lli i = 0; i < m; i++) {
        lli a, b; 
        cin >> a >> b; 
        --a; --b;
        g[a].push_back(b);
        r[b].push_back(a);
    }
    used.resize(n,0);
    for (lli i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    reverse(order.begin(), order.end());
    for (lli i = 0; i < n; i++) {
        int v = order[i];
        if (!c[v]) {
            ++comp;
            go(v);
        }
    }
    for (lli v = 0; v < n; v++) {
        for (auto now : g[v]) {
            if (c[v] != c[now]) {
                deg[c[v]]++;
            }
        }
    }
    vector<lli> ans;
    for (lli i = 1; i <= comp; i++) {
        if (deg[i] == 0) {
            ans.push_back(cap[i]);
        }
    }
    cout << ans.size() << "\n";
    for (auto v : ans) {
        cout << v + 1 << " ";
    }
}