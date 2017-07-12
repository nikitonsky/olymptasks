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
 
vector<vector<lli>> dp;
vector<lli> ans,a;
void findAns(int k, int s) {
    if (dp[k][s] == 0) return;
    if (dp[k - 1][s] == dp[k][s])
        findAns(k - 1, s);
    else {
        findAns(k - 1, s - a[k]);
        ans.push_back(k);
    }
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("lepus.in", "r", stdin);
    freopen("lepus.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n;
    cin >> n;
    string s;
    cin >> s;
    vector<lli> a(n, INT64_MIN);
    a[0] = 0;
    for (lli i = 1; i < n; i++) {
        if (s[i] == 'w') continue;
        if (i <= 2) {
            if (s[i] == '\"') {
                if (s[i - 1] != 'w') a[i] = max(a[i], a[i - 1] + 1);
            }
            else {
                if (s[i - 1] != 'w') a[i] = max(a[i], a[i - 1]);
            }
        }
        else if (i <= 4) {
            if (s[i] == '\"') {
                if (s[i - 1] != 'w') a[i] = max(a[i], a[i - 1] + 1);
                if (s[i - 3] != 'w') a[i] = max(a[i], a[i - 3] + 1);
            }
            else {
                if (s[i - 1] != 'w') a[i] = max(a[i], a[i - 1]);
                if (s[i - 3] != 'w') a[i] = max(a[i], a[i - 3]);
            }
        }
        else {
            if (s[i] == '\"') {
                if (s[i - 1] != 'w') a[i] = max(a[i], a[i - 1] + 1);
                if (s[i - 3] != 'w') a[i] = max(a[i], a[i - 3] + 1);
                if (s[i - 5] != 'w') a[i] = max(a[i], a[i - 5] + 1);
            }
            else {
                if (s[i - 1] != 'w') a[i] = max(a[i], a[i - 1]);
                if (s[i - 3] != 'w') a[i] = max(a[i], a[i - 3]);
                if (s[i - 5] != 'w') a[i] = max(a[i], a[i - 5]);
            }
        }
    }
    if (a[n - 1] <0) cout << -1;
    else cout << a[n - 1];
}