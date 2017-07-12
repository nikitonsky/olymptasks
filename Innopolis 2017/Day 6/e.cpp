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
    //freopen("phones.in", "r", stdin);
    //freopen("phones.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n;
    cin >> n;
    vector<vector<bool>> a(n, vector<bool>(n, 0));
    for (lli i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (lli j = 0; j < n; j++) a[i][j] = s[j] == 'Y';
    }
    lli m = INT64_MIN;
    lli x = 1 << n;
    vector<lli> dp(x, 0);
    for (int i = x - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (((i >> j) & 1) && ((i >> k) & 1) && a[j][k]) {
                    lli z = 1;
                    for (lli kk = 0; kk < j; kk++) {
                        z *= 2;
                    }
                    lli y = 1;
                    for (lli kk = 0; kk < k; kk++) {
                        y *= 2;
                    }
                    lli t = i ^ y ^ z;
                    dp[t] = max(dp[t], dp[i] + 2);
                    m = max(dp[t], m);
                }
            }
        }
    }
    cout << m;
}