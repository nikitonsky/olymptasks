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
    lli w, n;
    cin >> w >> n;
    vector<lli> a(n+1);
    for (lli i = 1; i <= n; i++) cin >> a[i];
    vector<vector<lli>> dp(n+1, vector<lli>(w+1,0));                                       
    for (lli k = 1; k <= n; k++) {
        for (lli s = 1; s <= w; s++) {
            if (s >= a[k]) {
                dp[k][s] = max(dp[k - 1][s], dp[k - 1][s - a[k]] + a[k]);
            }
            else
                dp[k][s] = dp[k - 1][s];
        }
    }
    cout << dp[n][w];
}