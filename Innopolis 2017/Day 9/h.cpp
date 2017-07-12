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

vector<vector<pair<lli,lli>>> a;
vector<char> used;
lli en = -1, st = -1;
vector<lli> ans;

void dfs(lli cur) {
	used[cur] = 1;
	for (auto now : a[cur]) {
		if (!used[now.first]) {
			dfs(now.first);
		}
	}
	used[cur] = 2;
	ans.push_back(cur);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("dag-shortpath.in", "r", stdin);
	freopen("dag-shortpath.out", "w", stdout);
#endif // _DEBUG
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	lli n, m,s,to;
	cin >> n >> m >> s >> to;
	a.resize(n+228, vector<pair<lli,lli>>());
	for (lli i = 0; i < m; i++) {
		lli f, t,c;
		cin >> f >> t>>c;
		--f, --t;
		a[f].push_back({ t,c });
	}
	used.resize(n+228, 0);
	--s, --to;
	dfs(s);
	if (!used[to]) cout << "Unreachable";
	else {
		reverse(ans.begin(), ans.end());
		vector<lli> dp(n+228, INT64_MAX);
		dp[s] = 0;
		for (lli i = 0; i < ans.size(); i++) {
			for (auto now : a[ans[i]]) {
				dp[now.first] = min(dp[now.first], dp[ans[i]] + now.second);
			}
		}
		cout << dp[to];
	}
}