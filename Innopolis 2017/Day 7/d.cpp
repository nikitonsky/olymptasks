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
vector<char> used;
lli en = -1, st = -1;
vector<lli> ans;
 
void dfs(lli cur) {
    used[cur] = 1;
    for (auto now : a[cur]) {
        if (!used[now]) {
            dfs(now);
        }
        else if (used[now] == 1) {
            en = cur;
            st = now;
        }
    }
    used[cur] = 2;
    ans.push_back(cur + 1);
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("hamiltonian.in", "r", stdin);
    freopen("hamiltonian.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n, m;
    cin >> n >> m;
    map<pair<lli, lli>,bool> p;
    a.resize(n, vector<lli>());
    for (lli i = 0; i < m; i++) {
        lli f, t;
        cin >> f >> t;
        --f, --t;
        a[f].push_back(t);
        p[{f + 1, t + 1}] = 1;
    }
    used.resize(n, 0);
    for (lli i = 0; i < n; i++)
        if (!used[i])
            dfs(i);
    reverse(ans.begin(), ans.end());
    for (lli i = 0; i < n - 1; i++) {
        if (p[{ans[i], ans[i + 1]}]) continue;
        cout << "NO";
        return 0;
    }
    cout << "YES";
}