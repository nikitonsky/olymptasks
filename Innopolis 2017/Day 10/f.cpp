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
#define ulli unsigned lli
using namespace std;
 
const int c = 100003;
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("cubes.in", "r", stdin);
    freopen("cubes.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n, m;
    cin >> n >> m;
     
    vector<lli> t(2*n+1);
    for (lli i = 0; i < n; i++) cin >> t[i];
    t[n] =m+228;
    for (lli i = 0; i < n; i++) t[2 * n - i] = t[i];
    n = 2 * n + 1;
    vector<lli> z(n);
    for (lli i = 1, l = 0, r = 0; i<n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && t[z[i]] == t[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    cout << (n - 1) / 2 << " ";
    lli res = 0;
    for (lli i = (n - 1) / 2; i < n; i++) if (z[i]%2==0 && z[i] && z[i] + i == n) cout <<(n-1)/2- z[i] / 2 << " ";
}