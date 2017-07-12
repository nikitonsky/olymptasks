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
lli en = -1,st=-1;
vector<lli> ans;
 
void dfs(lli cur) {
    used[cur] = 1;
    for (auto now : a[cur]) {
        if (!used[now]) {
            dfs(now);
        }
        else if(used[now]==1){
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
    used.resize(n, 0);
    for (lli i = 0; i < n; i++)
        if (!used[i]) dfs(i);
    if (st != -1) cout << -1;
    else {
        for (lli i = n - 1; i >= 0; i--) cout << ans[i] << " ";
    }
}