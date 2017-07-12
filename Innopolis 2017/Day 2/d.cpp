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
 
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("spantree2.in", "r", stdin);
    freopen("spantree2.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n, m;
    cin >> n >> m;
    vector < pair<lli, pair<lli, lli>>> a(m);
    for (lli i= 0; i < m; i++) {
        lli f, t, c;
        cin >> f >> t >> c;
        --f, --t;
        a[i] = { c,{f,t} };
    }
    vector<lli> id(n);
    for (lli i = 0; i < n; i++) id[i] = i;
    lli res = 0;
    sort(a.begin(), a.end());
    for (lli i = 0; i < m; i++) {
        if (id[a[i].second.first] != id[a[i].second.second]) {
            res += a[i].first;
            lli nid = id[a[i].second.second], oid = id[a[i].second.first];
            for (lli i = 0; i < n; i++) if (id[i] == oid) id[i] = nid;
        }
    }
    cout << res;
}