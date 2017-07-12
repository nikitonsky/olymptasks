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
    srand(time(NULL));
    lli n, m;
    cin >> n >> m;
    vector<vector<lli>> a(n, vector<lli>(m));
    for (lli i = 0; i < n; i++)
        for (lli j = 0; j < m; j++)
            cin >> a[i][j];
    vector<vector<lli>> dp(n, vector<lli>(m, INT64_MAX));
    dp[0][0] = a[0][0];
    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            if (j + 1 < m) dp[i][j + 1] = min(dp[i][j + 1], a[i][j + 1] + dp[i][j]);
            if (i + 1 < n) dp[i + 1][j] = min(dp[i + 1][j], a[i + 1][j] + dp[i][j]);
        }
    }
    cout << dp[n - 1][m - 1];
}