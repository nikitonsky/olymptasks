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
	lli to, t, s;
};

edge make(lli to, lli t, lli s) {
	edge res;
	res.to = to;
	res.t = t;
	res.s = s;
	return res;
}
lli n;
vector<vector<edge>> a;

bool foo(lli cnt) {
	vector<lli> dist(n, INT64_MAX);
	dist[0] = 0;
	set<pair<lli, lli>> q;
	q.insert({ 0,0 });
	while (!q.empty()){
		lli cur = q.begin()->second;
		q.erase(q.begin());
		for (auto now : a[cur]) {
			if (now.s < cnt) continue;
			if (dist[now.to] > dist[cur] + now.t) {
				q.erase({ dist[now.to],now.to });
				dist[now.to] = dist[cur] + now.t;
				q.insert({ dist[now.to],now.to });
			}
		}
	}
	return dist[n - 1] <= 24 * 60;
}

lli bin() {
	lli l = 0, r = 1e7;
	while (r - l > 1) {
		lli m = (l + r) / 2;
		if (foo(m)) l = m;
		else r = m;
	}
	return l;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("cups.in", "r", stdin);
	freopen("cups.out", "w", stdout);
#endif // _DEBUG
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	lli m;
	cin >> n >> m;
	a.resize(n, vector<edge>());
	for (lli i = 0; i < m; i++) {
		lli f, to,t, s;
		cin >> f >> to >> t >> s;
		--f, --to, s -= 3000000;
		s /= 100;
		a[f].push_back(make(to, t, s));
		a[to].push_back(make(f, t, s));
	}
	cout << bin();
}