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
 
lli n;
vector<lli> a;
lli ssize = 1;
 
lli foo(lli a, lli b) {
    return a + b;
}
 
void make() {
    for (; ssize < n; ssize *= 2);
    a.resize(4 * ssize,0);
    for (lli i = 0; i < n; i++) cin >> a[ssize - 1 + i];
    for (lli i = ssize - 2; i >= 0; i--) a[i] = foo(a[2 * i + 1], a[2 * i + 2]);
}
 
lli ffoo(lli v, lli l, lli r, lli fl, lli fr) {
    if (fr<l || fl> r) return 0;
    if (fl == l && fr == r) return a[v];
    lli m = (l + r) / 2;
    return foo(ffoo(2 * v + 1, l, m, fl, min(m,fr)), ffoo(2 * v + 2, m + 1, r, max(m+1,fl), fr));
}
 
lli sum(lli l, lli r) {
    return ffoo(0, 0,ssize-1, l, r);
}
 
void upd(lli cur) {
    if (cur == 0) return;
    a[cur] = foo(a[2 * cur + 1], a[2 * cur + 2]);
    upd((cur - 1) / 2);
}
 
void update(lli x, lli m) {
    a[ssize + x-1] = m;
    upd((ssize + x - 1 - 1) / 2);
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("rsq.in", "r", stdin);
    freopen("rsq.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    make();
    string todo;
    while (cin >> todo) {
        if (todo == "set") {
            lli i, x;
            cin >> i >> x;
            --i;
            update(i, x);
        }
        else {
            lli l, r;
            cin >> l >> r;
            cout << sum(--l, --r) << "\n";
        }
    }
}