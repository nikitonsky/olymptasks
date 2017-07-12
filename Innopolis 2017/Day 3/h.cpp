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
 
lli mod;
 
struct mat {
    lli a, b, c, d;
};
 
mat make_mat(lli a, lli b, lli c, lli d) {
    mat res;
    res.a = a;
    res.b = b;
    res.c = c;
    res.d = d;
    return res;
}
 
lli n;
vector<mat> a;
lli ssize = 1;
 
mat foo(mat a, mat b) {
    mat res;
    res.a = (a.a*b.a + a.b*b.c)%mod;
    res.b = (a.a*b.b + a.b*b.d)%mod;
    res.c = (a.c*b.a + a.d*b.c)%mod;
    res.d = (a.c*b.b + a.d*b.d)%mod;
    return res;
}
 
void make() {
    for (; ssize < n; ssize *= 2);
    a.resize(4 * ssize, make_mat(1,0,0,1));
    for (lli i = 0; i < n; i++) cin >> a[ssize - 1 + i].a >> a[ssize - 1 + i].b >> a[ssize - 1 + i].c >> a[ssize - 1 + i].d;
    for (lli i = ssize - 2; i >= 0; i--) a[i] = foo(a[2 * i + 1], a[2 * i + 2]);
}
 
mat ffoo(lli v, lli l, lli r, lli fl, lli fr) {
    if (fr<l || fl> r) return make_mat(1,0,0,1);
    if (fl == l && fr == r) return a[v];
    lli m = (l + r) / 2;
    return foo(ffoo(2 * v + 1, l, m, fl, min(m, fr)), ffoo(2 * v + 2, m + 1, r, max(m + 1, fl), fr));
}
 
mat sum(lli l, lli r) {
    return ffoo(0, 0, ssize - 1, l, r);
}
/*
void upd(lli cur) {
    if (cur == 0) return;
    a[cur] = foo(a[2 * cur + 1], a[2 * cur + 2]);
    upd((cur - 1) / 2);
}
 
void update(lli x, lli m) {
    a[ssize + x - 1] = m;
    upd((ssize + x - 1 - 1) / 2);
}
*/
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("crypto.in", "r", stdin);
    freopen("crypto.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli m;
    cin >> mod >> n >> m;
    make();
    for (lli q = 0; q < m; q++) {
        lli l, r;
        cin >> l >> r;
        mat res = sum(--l, --r);
        cout << res.a << " " << res.b << "\n" << res.c << " " << res.d << "\n";
    }
}