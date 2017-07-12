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
    freopen("ladder.in", "r", stdin);
    freopen("ladder.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    srand(time(NULL));
    lli n;
    cin >> n;
    vector<lli> a(n+1);
    a[0] = 0;
    for (lli i = 1;i <= n; i++) cin >> a[i];
    vector<lli> dp(n + 1);
    dp[0] = 0;
    dp[1] = a[1];
    for (lli i = 2; i <= n; i++) dp[i] = a[i] + max(dp[i - 1], dp[i - 2]);
    cout << dp[n];
}