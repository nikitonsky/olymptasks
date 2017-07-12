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
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("pathmgep.in", "r", stdin);
    freopen("pathmgep.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n, f, t;
    cin >> n>>f>>t;
    --f, --t;
    vector < vector<pair<lli, lli>>> a(n, vector<pair<lli, lli>>());
    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < n; j++) {
            lli c;
            cin >> c;
            if (c < 1) continue;
            a[i].push_back({ j,c });
        }
    }
    vector<lli> dist(n, INT64_MAX);
    dist[f] = 0;
    set <pair<lli, lli>> q;
    q.insert({ 0,f });
    while (!q.empty()) {
        lli cur = q.begin()->second;
        q.erase(q.begin());
        for (auto now : a[cur]) {
            if (dist[now.first] > dist[cur] + now.second) {
                q.erase({ dist[now.first], now.first });
                dist[now.first] = dist[cur] + now.second;
                q.insert({ dist[now.first],now.first });
            }
        }
    }
    if (dist[t] == INT64_MAX) cout << -1;
    else cout << dist[t];
}