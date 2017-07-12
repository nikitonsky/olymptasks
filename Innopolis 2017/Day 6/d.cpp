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
 
bool foo(char a, char b) {
    return (a == ')'&& b == '(') || (a == ']'&&b == '[') || (a == '}'&&b == '{');
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("aquarium.in", "r", stdin);
    freopen("aquarium.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n;
    cin >> n;
    vector<vector<lli>> a(n, vector<lli>(n));
    for (lli i = 0; i < n; i++)
        for (lli j = 0; j < n; j++) cin >> a[i][j];
    vector<vector<lli>> dp((1 << n)+1, vector<lli>(n, INT64_MAX));
    vector<vector<lli>> p((1 << n) + 1, vector<lli>(n, INT64_MAX));
    for (lli i = 0; i < n; i++) dp[1<<i][i] = 0;
    for (lli mask = 1; mask < 1 << n; mask++) {
        for (lli i = 0; i < n; i++) {
            if (!(mask & (1 << i))) continue;
            for (lli j = 0; j < n; j++) {
                if (mask & 1 << j) continue;
                if (dp[mask | (1 << j)][j] > dp[mask][i] + a[i][j]) {
                    dp[mask | (1 << j)][j] = dp[mask][i] + a[i][j];
                    p[mask | (1 << j)][j] = i;
                }
                 
            }
        }
    }
    lli res = INT64_MAX;
    lli it = -1;
    for (lli i = 0; i < n; i++) {
        if (res > dp[(1 << n) - 1][i]) it = i;
        res = min(res, dp[(1 << n) - 1][i]);
    }
    vector<lli> r;
    cout << res<<"\n";
    for (lli mask = (1 << n)-1; mask != 0;) {
        r.push_back(it);
        it = p[mask][it];
        mask ^= 1 << r.back();
    }
    for (lli i = r.size()-1; i >= 0; i--) cout << r[i]+1 << " ";
}