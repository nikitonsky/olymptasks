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
    freopen("rmq.in", "r", stdin);
    freopen("rmq.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n;
    cin >> n;
    vector<lli> a(n+10,INT64_MAX);
    for (lli i = 0; i < n; i++) cin >> a[i];
    lli len = (lli)sqrt(n + .0);
    vector<lli> b(len+10,INT64_MAX);
    for (lli i = 0; i < n; i++) b[i / len] = min(b[i / len], a[i]);
    string t;
    while(cin >> t) {
        if (t == "min") {
            lli l, r;
            cin >> l >> r;
            --l, --r;
            lli re = a[l];
            for (lli i = l; i <= r;) {
                if (i % len == 0 && i + len - 1 <= r) {
                    re = min(re, b[i / len]);
                    i += len;
                }
                else {
                    re = min(re, a[i]);
                    i++;
                }
            }
            cout << re << "\n";
        }
        else {
            lli i, x;
            cin >> i >> x;
            --i;
            if (b[i / len] >= x) {
                a[i] = x;
                b[i / len] = x;
            }
            else if (a[i] != b[i / len])a[i] = x;
            else {
                a[i] = x;
                b[i / len] = INT64_MAX;
                for (lli j = i / len*len; j < min(n, i / len*len + len); j++) b[j / len] = min(b[j / len], a[j]);
            }
        }
    }
}