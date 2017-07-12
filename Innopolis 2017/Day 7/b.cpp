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
vector<lli> p;
vector<char> used;
lli en = -1, st = -1;
 
void dfs(lli cur) {
    used[cur] = 1;
    for (auto now : a[cur]) {
        if (!used[now]) {
            p[now] = cur;
            dfs(now);
        }
        else if (used[now] == 1) {
            en = cur;
            st = now;
        }
    }
    used[cur] = 2;
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("select.in", "r", stdin);
    //freopen("select.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n, m;
    cin >> n >> m;
    a.resize(n, vector<lli>());
    for (lli i = 0; i < m; i++) {
        lli f, t;
        cin >> f >> t;
        --f, --t;
        a[f].push_back(t);
    }
    p.resize(n, -1);
    used.resize(n, 0);
    for (lli i = 0; i < n; i++)
        if (!used[i])
            dfs(i);
    if (st == -1) cout << "NO";
    else {
        vector<lli> res;
        res.push_back(st + 1);
        for (lli v = en; v != st; v = p[v]) res.push_back(v + 1);
        cout << "YES\n";
        for (lli i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";
    }
}