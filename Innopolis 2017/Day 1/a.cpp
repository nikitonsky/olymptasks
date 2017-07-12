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
 
struct team{
    lli s,t,id;
};
 
bool cmp(team a, team b) {
    if (a.s != b.s) return a.s > b.s;
    if (a.t != b.t) return a.t < b.t;
    return a.id < b.id;
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // _DEBUG
    #ifndef _DEBUG
        freopen("ejudge.in", "r", stdin);
        freopen("ejudge.out", "w", stdout);
    #endif // !_DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n;
    cin >> n;
    vector<team> a(n);
    for (lli i = 0; i < n; i++) {
        lli s, t;
        cin >> s >> t;
        a[i].s = s;
        a[i].t = t;
        a[i].id = i + 1;
    }
    sort(a.begin(), a.end(), cmp);
    for (auto now : a) cout << now.id << " ";
}