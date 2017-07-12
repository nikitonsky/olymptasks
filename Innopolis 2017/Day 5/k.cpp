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
    freopen("phones.in", "r", stdin);
    freopen("phones.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n;
    const lli mod = 1e9;
    cin >> n;
    vector<vector<lli>> a(n+1, vector<lli>(10,0));
    for (lli i = 1; i < 10; i++) a[1][i] = 1;
    a[1][8] = 0;
    for (lli i = 2; i <= n; i++) {
        a[i][0] = (a[i - 1][4] + a[i - 1][6]) % mod;
        a[i][1] = (a[i - 1][6] + a[i - 1][8]) % mod;
        a[i][2] = (a[i - 1][7] + a[i - 1][9]) % mod;
        a[i][3] = (a[i - 1][4] + a[i - 1][8]) % mod;
        a[i][4] = (a[i - 1][9] + a[i - 1][3] + a[i - 1][0]) % mod;
        a[i][5] = 0;
        a[i][6] = (a[i - 1][7] + a[i - 1][1] + a[i - 1][0]) % mod;
        a[i][7] = (a[i - 1][2] + a[i - 1][6]) % mod;
        a[i][8] = (a[i - 1][1] + a[i - 1][3]) % mod;
        a[i][9] = (a[i - 1][4] + a[i - 1][2]) % mod;
    }
    cout << (a[n][0] + a[n][1] + a[n][2] + a[n][3] + a[n][4] + a[n][5] + a[n][6] + a[n][7] + a[n][8] + a[n][9])%mod;
 
}