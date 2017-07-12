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
 
vector<vector<lli>> a;
vector<lli> fup, tin;
set<lli> res;
map<pair<lli, lli>,lli> b;
vector<bool> used;
lli timer = 0;
 
void IS_BRIDGE(lli f,lli t) {
    res.insert(b[{f, t}]);
}
 
void dfs(int v, int p = -1) {
    used[v] = 1;
    tin[v] = fup[v] = timer++;
    for (lli i = 0; i<a[v].size(); ++i) {
        int to = a[v][i];
        if (to == p)  continue;
        if (used[to])
            fup[v] = min(fup[v], tin[to]);
        else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("hamiltonian.in", "r", stdin);
    //freopen("hamiltonian.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n, m;
    cin >> n >> m;
    vector<lli> cnt(n, 0);
    a.resize(n, vector<lli>());
    for (lli i = 0; i < m; i++) {
        lli f, t;
        cin >> f >> t;
        --f, --t;
        a[f].push_back(t);
        a[t].push_back(f);
        b[{f, t}] = i;
        b[{t, f}] = i;
    }
    used.resize(n, 0);
    tin.resize(n);
    fup.resize(n);
    for (lli i = 0; i < n; i++)
        if (!used[i])
            dfs(i);
    cout << res.size() << "\n";
    for (auto now : res) cout << now+1 << " ";
}