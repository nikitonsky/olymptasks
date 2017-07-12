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
double a;
 
bool foo(double l) {
    double ll = a;
    for (lli i = 2; i < n; i++) {
        double cur = 2 * l - ll+2;
        if (cur <= 0) return 0;
        ll = l;
        l = cur;
    }
    return 1;
}
 
double bin() {
    double l = 0, r = 1e18;
    for (lli i = 0; i < 1000; i++) {
        double m = (l + r) / 2;
        if (foo(m)) r = m;
        else l = m;
    }
    double lll = a, ll = r;
    for (lli i = 2; i < n; i++) {
        double cur = 2 * ll - lll + 2;
        lll = ll;
        ll = cur;
    }
    return ll;
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("inverse.in", "r", stdin);
    //freopen("inverse.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> a;
    cout << bin();
}