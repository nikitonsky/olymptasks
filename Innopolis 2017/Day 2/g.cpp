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
 
vector<lli> r, rt;
 
 
lli get(lli v) {
    return v == rt[v] ? v : rt[v] = get(rt[v]);
}
void unite(lli a, lli b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        if (r[a] < r[b]) {
            swap(a, b);
        }
        rt[b] = a;
        if (r[a] == r[b]) {
            r[a]++;
        }
    }
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("cutting.in", "r", stdin);
    freopen("cutting.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n, m, k;
    cin >> n >> m >> k;
    r.resize(n,0);
    rt.resize(n);
    for (lli i = 0; i < n; i++) rt[i] = i;
    lli buf;
    for (lli i = 0; i < m; i++) cin >> buf >> buf;
    vector<pair<int, pair<lli, lli>>> q(k);
    for (lli i = 0; i < k; i++) {
        string t;
        cin >> t;
        if (t == "ask") {
            lli f, s;
            cin >> f >> s;
            q[i] = { 0,{--f,--s} };
        }
        else {
            lli f, s;
            cin >> f >> s;
            q[i] = { 1,{--f,--s} };
        }
    }
    vector<string> Iskander;
    for (lli i = k - 1; i >= 0; i--) {
        if (q[i].first == 1) {
            unite(q[i].second.first, q[i].second.second);
        }
        else {
            if (get(q[i].second.first) == get(q[i].second.second)) Iskander.push_back("YES\n");
            else Iskander.push_back("NO\n");
        }
    }
    for (lli i = Iskander.size() - 1; i >= 0; i--) cout << Iskander[i];
}