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
    freopen("evacuation.in", "r", stdin);
    freopen("evacuation.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n, k;
    cin >> n >> k;
    vector<lli> exit(k);
    for (lli i = 0; i < k; i++) cin >> exit[i];
    lli m;
    cin >> m;
    vector<vector<lli>> a(n, vector<lli>());
    for (lli i = 0; i < m; i++) {
        lli f, t;
        cin >> f >> t;
        --f, --t;
        a[f].push_back(t);
        a[t].push_back(f);
    }
    vector<lli> d(n, INT64_MAX), p(n, -1);
    queue<lli> q;
    for (auto now : exit) {
        now--;
        p[now] = now;
        d[now] = 0;
        q.push(now);
    }
    while (!q.empty()) {
        lli cur = q.front();
        q.pop();
        for (auto now : a[cur]) {
            if (d[now] > d[cur] + 1 || (d[now] == d[cur] + 1 && p[now] > p[cur])) {
                d[now] = d[cur] + 1;
                p[now] = p[cur];
                q.push(now);
            }
        }
    }
    for (auto now : d) cout << now << " ";
    cout << "\n";
    for (auto now : p) cout << now + 1 << " ";
}