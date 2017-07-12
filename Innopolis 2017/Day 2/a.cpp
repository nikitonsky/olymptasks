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
    freopen("parking.in", "r", stdin);
    freopen("parking.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    string s;
    lli n;
    cin >> n;
    set<lli> q;
    for (lli i = 0; i < 2 * n; i++) q.insert(i);
    for (lli g = 0; g < n; g++) {
        lli cur;
        cin >> cur;
        cur--;
        lli it = *q.lower_bound(cur) + 1;
        if (it > n) it -= n;
        q.erase(it-1);
        q.erase(it + n-1);
        cout << it;
        cout << " ";
    }
}