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
	freopen("pathbgep.in", "r", stdin);
	freopen("pathbgep.out", "w", stdout);
#endif // _DEBUG
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	lli n, m;
	cin >> n >> m;
	vector < vector<pair<lli, lli>>> a(n, vector<pair<lli, lli>>());
	for (lli i = 0; i < m; i++) {
		lli f, t, c;
		cin >> f >> t >> c;
		--f, --t;
		a[f].push_back({ t,c });
		a[t].push_back({ f,c });
	}
	vector<lli> dist(n, INT64_MAX);
	dist[0] = 0;
	set <pair<lli, lli>> q;
	q.insert({ 0,0 });
	while (!q.empty()) {
		lli cur = q.begin()->second;
		q.erase(q.begin());
		for (auto now : a[cur]) {
			if (dist[now.first] > dist[cur] + now.second) {
				q.erase({ dist[now.first], now.first });
				dist[now.first] = dist[cur] + now.second;
				q.insert({ dist[now.first],now.first });
			}
		}
	}
	for (auto now : dist) cout << now << " ";
}