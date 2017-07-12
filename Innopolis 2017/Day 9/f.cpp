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

struct edge {
	lli f, t, c;
};

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("kpath.in", "r", stdin);
	freopen("kpath.out", "w", stdout);
#endif // _DEBUG
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	lli n, m, k, s;
	cin >> n >> m >> k >> s;
	--s;
	vector<edge> a(m);
	for (lli i = 0; i < m; i++) cin >> a[i].f >> a[i].t >> a[i].c;
	for (lli i = 0; i < m; i++) --a[i].f, --a[i].t;
	vector<vector<lli>> dp(k + 1, vector<lli>(n, INT64_MAX));
	dp[0][s] = 0;
	for (lli i = 1; i <= k; i++) {
		for (auto now : a) {
			if (dp[i - 1][now.f] == INT64_MAX) continue;
			dp[i][now.t] = min(dp[i][now.t], dp[i - 1][now.f] + now.c);
		}
	}
	for (auto now : dp[k]) {
		if (now == INT64_MAX) cout << "-1\n";
		else cout << now << "\n";
	}
}