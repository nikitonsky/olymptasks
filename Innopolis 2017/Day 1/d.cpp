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
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("queries.in", "r", stdin);
    freopen("queries.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n;
    cin >> n;
    map<lli,vector<lli>> a;
    for (lli i = 0; i < n; i++) {
        lli buf;
        cin >> buf;
        a[buf].push_back(i+1);
    }
    lli m;
    cin >> m;
    for (lli q = 0; q < m; q++) {
        lli l, r, x;
        cin >> l >> r >> x;
        if (upper_bound(a[x].begin(), a[x].end(), r) - lower_bound(a[x].begin(), a[x].end(), l)) cout << 1;
        else cout << 0;
    }
     
}