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
 
vector<vector<lli>> ch;
lli color = 0;
 
bool foo(char a, char b) {
    return (a == ')'&& b == '(') || (a == ']'&&b == '[') || (a == '}'&&b == '{');
}
 
void dfs(lli cur, bool c) {
    color += c;
    for (auto now : ch[cur]) dfs(now, !c);
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("select.in", "r", stdin);
    //freopen("select.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n;
    cin >> n;
    vector<vector<bool>> a(n, vector<bool>(n, 0));
    lli m;
    cin >> m;
    for (lli i = 0; i < m; i++) {
        lli f, t;
        cin >> f >> t;
        --f, --t;
        a[f][t] = 1;
        a[t][f] = 1;
    }
    for (auto now : a) {
        for (auto now1 : now)
            cout << now1 << " ";
        cout << "\n";
    }
}