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
#define lli long long int
using namespace std;
 
vector<lli> a;
 
// 1 3 4 10 10
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // _DEBUG
//#ifndef _DEBUG
//  freopen("excess.in", "r", stdin);
//  freopen("excess.out", "w", stdout);
//#endif // !_DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n;
    cin >> n;
    a.resize(n);
    for (lli i = 0; i < n; i++) cin >> a[i];
    lli m;
    cin >> m;
    sort(a.begin(), a.end());
    for (lli i = 0; i < m; i++) {
        lli l, r;
        cin >> l >> r;
        cout << upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l) << " ";
    }
}