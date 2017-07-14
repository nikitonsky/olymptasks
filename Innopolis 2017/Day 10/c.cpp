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
	freopen("z.in", "r", stdin);
	freopen("z.out", "w", stdout);
#endif // _DEBUG
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	string t;
	cin >> t;
	vector<lli> z(t.size());
	for (lli i = 1, l = 0, r = 0; i<t.size(); i++) {
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < t.size() && t[z[i]] == t[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
	for (lli i = 1; i < t.size(); i++) cout << z[i] << " ";
}