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
	freopen("search2.in", "r", stdin);
	freopen("search2.out", "w", stdout);
#endif // _DEBUG
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	string t, f, s;
	cin >> f>> s;
	t = f + '#' + s;
	vector<lli> prefix(t.size());
	prefix[0] = 0;
	for (lli i = 1; i < t.size(); i++) {
		lli j = prefix[i - 1];
		while (j > 0 && t[i] != t[j])
			j = prefix[j - 1];
		if (t[i] == t[j])  j++;
		prefix[i] = j;
	}
	lli res = 0;
	for (auto now : prefix) res += now == f.size();
	cout << res << "\n";
	for (lli i = 0; i < prefix.size(); i++) if (prefix[i] == f.size()) cout << i - 2*f.size()+1<< " ";
}