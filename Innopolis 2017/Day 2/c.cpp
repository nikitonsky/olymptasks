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
 
vector<vector<lli>> a;
vector<bool> used;
vector<bool> used1;
lli res = 0;
lli cnt['z' - 'a' + 1];
string s;
 
void dfs(lli cur) {
    used[cur] = 1;
    cnt[s[cur] - 'a']++;
    for (auto now : a[cur]) {
        if (!used[now]) dfs(now);
    }
}
 
void dfs1(lli cur, char w) {
    used1[cur] = 1;
    if (s[cur] != w) res++;
    for (auto now : a[cur]) {
        if (!used1[now]) dfs1(now, w);
    }
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("oil.in", "r", stdin);
    //freopen("oil.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    lli n;
    cin >> s >> n;
    a.resize(s.size(), vector<lli>());
    for (lli i = 0; i < n; i++) {
        a[i].push_back(s.size() - n + i);
        a[s.size() - n + i].push_back(i);
    }
    used1.resize(s.size());
    used.resize(s.size());
    for (lli i = 0; i < s.size(); i++) {
        if (a[i].size() == 0) continue;
        if (!used[i]){
            for (lli i = 'a'; i <= 'z'; i++) cnt[i - 'a'] = 0;
            dfs(i);
            lli c = -1;
            char w = '1';
            for (lli i = 'a'; i <= 'z'; i++) {
                if (cnt[i - 'a'] > c) {
                    c = cnt[i - 'a'];
                    w = i;
                }
            }
            dfs1(i, w);
        }
    }
    cout << res;
}