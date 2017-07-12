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
#define lli long long int
using namespace std;
 
struct edge
{
    lli f, t, c, id;
};
 
bool cmp(edge a, edge b) {
    return a.c < b.c;
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("oil.in", "r", stdin);
    freopen("oil.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n, m, s;
    cin >> n >> m>>s;
    vector < edge> a(m);
    for (lli i = 0; i < m; i++) {
        lli f, t, c;
        cin >> f >> t >> c;
        --f, --t;
        a[i].c = c;
        a[i].f = f;
        a[i].t = t;
        a[i].id = i + 1;
    }
    vector<lli> id(n);
    for (lli i = 0; i < n; i++) id[i] = i;
    sort(a.begin(), a.end(),cmp);
    vector<edge> mid;
    for (lli i = m - 1; i >= 0;i--) {
        if (id[a[i].f] != id[a[i].t]) {
            lli nid = id[a[i].f], oid = id[a[i].t];
            for (lli i = 0; i < n; i++) if (id[i] == oid) id[i] = nid;
        }
        else {
            mid.push_back(a[i]);
        }
    }
    set<lli> res;
    lli su = 0;
    for (lli i = mid.size() - 1; i >= 0; i--) {
        if (su + mid[i].c <= s) {
            su += mid[i].c;
            res.insert(mid[i].id);
        }
    }
    cout << res.size() << "\n";
    for (auto now : res) cout << now << " ";
}