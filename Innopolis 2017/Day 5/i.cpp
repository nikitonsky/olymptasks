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
    freopen("numbers.in", "r", stdin);
    freopen("numbers.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n;
    cin >> n;
    vector<vector<lli>> a(n+1, vector<lli>(10));
    for (lli i = 0; i < 10; i++) {
        a[0][i] = 0;
        a[1][i] = 1;
    }
    a[1][0] = 0;
    for (lli i = 2; i <= n; i++) {
        a[i][9] = a[i-1][8]+a[i-1][9];
        a[i][0] = a[i - 1][1]+a[i-1][0];
        for (lli j = 1; j < 9; j++) a[i][j] = a[i - 1][j] + a[i - 1][j - 1] + a[i - 1][j + 1];
    }
    lli res = 0;
    for (lli i = 0; i < 10; i++) res += a[n][i];
    cout << res;
}