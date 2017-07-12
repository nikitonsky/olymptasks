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
#endif // _DEBUG
    #ifndef _DEBUG
        freopen("excess.in", "r", stdin);
        freopen("excess.out", "w", stdout);
    #endif // !_DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n;
    cin >> n;
    lli res = 0;
    for (lli i = 0; i < n; i++) {
        lli cur;
        cin >> cur;
        res ^= cur;
    }
    cout << res;
}