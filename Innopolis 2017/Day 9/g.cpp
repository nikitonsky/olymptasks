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
	freopen("rblock.in", "r", stdin);
	freopen("rblock.out", "w", stdout);
#endif // _DEBUG
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	lli n, m;
	cin >> n >> m;
	vector<vector<lli>> a(n, vector<lli>(n,-1));
	for (lli i = 0; i < n; i++) a[i][i] = 0;
	for (lli i = 0; i < m; i++) {
		lli f, t, c;
		cin >> f >> t >> c;
		--f, --t;
		a[f][t] = c;
		a[t][f] = c;
	}
	vector<lli> dist(n, INT64_MAX);
	dist[0] = 0;
	set<pair<lli, lli>> q;
	vector<lli> p(n, -1);
	q.insert({ 0,0 });
	while (!q.empty()) {
		lli cur = q.begin()->second;
		q.erase(q.begin());
		for (lli i = 0; i < n; i++) {
			if (a[cur][i] == -1) continue;
			if (dist[i] > dist[cur] + a[cur][i]) {
				q.erase({ dist[i],i });
				dist[i] = dist[cur] + a[cur][i];
				q.insert({ dist[i],i });
				p[i] = cur;
			}
		}
	}
	lli res = dist[n - 1],resu=-1;
	for (lli cur = n - 1; cur != 0; cur = p[cur]) {
		a[cur][p[cur]] *= 2;
		a[p[cur]][cur] *= 2;
		dist.resize(0);
		dist.resize(n, INT64_MAX);
		dist[0] = 0;
		q.insert({ 0,0 });
		while (!q.empty()) {
			lli cur = q.begin()->second;
			q.erase(q.begin());
			for (lli i = 0; i < n; i++) {
				if (a[cur][i] == -1) continue;
				if (dist[i] > dist[cur] + a[cur][i]) {
					q.erase({ dist[i],i });
					dist[i] = dist[cur] + a[cur][i];
					q.insert({ dist[i],i });
				}
			}
		}
		resu = max(resu, dist[n - 1] - res);
		a[cur][p[cur]] /= 2;
		a[p[cur]][cur] /= 2;
	}
	cout << resu;
}