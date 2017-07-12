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
 
struct dot
{
    lli x, y;
};
lli n;
vector<dot> a;
 
vector<lli> fup, tin;
bool flag = 0;
vector<bool> used;
lli timer = 0;
double rr;
 
 
void IS_CUTPOINT(lli n) {
    flag = 0;
}
 
double bet(dot a, dot b) {
    return sqrt(abs(a.x - b.x)*abs(a.x - b.x) + abs(a.y - b.y)*abs(a.y - b.y));
}
 
void dfs(lli v, lli p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    lli children = 0;
    for (lli to = 0;to < n; to++) {
        if (to == v) continue;
        if (bet(a[to], a[v]) / 2 > rr) continue;
        if (to == p)  continue;
        if (used[to])
            fup[v] = min(fup[v], tin[to]);
        else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] >= tin[v] && p != -1)
                IS_CUTPOINT(v);
            children++;
        }
    }
    if (p == -1 && children > 1)
        IS_CUTPOINT(v);
}
 
bool foo(double r) {
    flag = 1;
    used.resize(0);
    tin.resize(0);
    fup.resize(0);
    timer = 0;
    used.resize(n, 0);
    tin.resize(n,0);
    fup.resize(n,0);
    rr = r;
    dfs(0);
    for (lli i = 0; i < n; i++)
        if (!used[i])
            flag = 0;
    return flag;
}
 
double bin(double l, double r) {
    for (lli q = 0; q < 300; q++) {
        double m = (l + r) / 2;
        if (foo(m)) r = m;
        else l = m;
    }
    return r;
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("evacuation.in", "r", stdin);
    //freopen("evacuation.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    a.resize(n);
    for (lli i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
    cout << fixed << setprecision(20) <<  bin(0, 1e9);
}