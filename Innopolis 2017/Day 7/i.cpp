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
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("numbers.in", "r", stdin);
    freopen("numbers.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n, m;
    cin >> n >> m;
    queue<lli> q;
    q.push(n);
    vector<lli> d(10000, INT64_MAX), p(10000, -1);
    vector<bool> used(1000, 0);
    while (!q.empty()) {
        lli cur = q.front();
        q.pop();
        if (cur % 10 != 1) {
            if (d[cur] + 1 < d[cur - 1]) {
                d[cur - 1] = d[cur] + 1;
                p[cur - 1] = cur;
                q.push(cur-1);
            }
        }
        if (cur / 1000 != 9) {
            if (d[cur] + 1 < d[cur +1000]) {
                d[cur +1000] = d[cur] + 1;
                p[cur +1000] = cur;
                q.push(cur+1000);
            }
        }
        if (d[cur] + 1 < d[cur%1000*10+cur/1000]) {
            d[cur % 1000 * 10 + cur / 1000] = d[cur] + 1;
            p[cur % 1000 * 10 + cur / 1000] = cur;
            q.push(cur % 1000 * 10 + cur / 1000);
        }
        if (d[cur] + 1 < d[cur/10+cur%10*1000]) {
            d[cur / 10 + cur % 10 * 1000] = d[cur] + 1;
            p[cur / 10 + cur % 10 * 1000] = cur;
            q.push(cur / 10 + cur % 10 * 1000);
        }
    }
    cout << n << "\n";
    vector<lli> res;
    for (lli cur = m; cur != n; cur = p[cur]) res.push_back(cur);
    for (lli i = res.size() - 1; i >= 0; i--) cout << res[i] << "\n";
}