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
    //freopen("ladder.in", "r", stdin);
    //freopen("ladder.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n;
    cin >> n;
    vector<lli> a(n);
    for (lli i = 0; i < n; i++) cin >> a[i];
    vector<lli> dp(n), p(n);
    for (lli i = 0; i < n; i++) {
        dp[i] = 1;
        p[i] = -1;
        for (lli j = i - 1; j >= 0; j--) {
            if (a[j]<a[i] && dp[j] + 1>dp[i]) {
                p[i] = j;
                dp[i] = dp[j] + 1;
            }
        }
    }
    lli m = 0, r=0;
    for (lli i = 0; i < n; i++) {
        if (dp[i] > r) {
            r = dp[i];
            m = i;
        }
    }
    cout << dp[m]<<"\n";
    vector<lli>res;
    for (lli i = m; i != -1; i = p[i]) res.push_back(a[i]);
    for (lli i = res.size()-1; i >= 0; i--) cout << res[i] << " ";
}