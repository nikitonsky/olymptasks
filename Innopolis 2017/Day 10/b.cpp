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
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);
#endif // _DEBUG
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	string t;
	cin >> t;
	vector<lli> prefix(t.size());
	prefix[0] = 0;
	for (lli i = 1; i < t.size(); i++) {
		lli j = prefix[i - 1];
		while (j > 0 && t[i] != t[j])
			j = prefix[j - 1];
		if (t[i] == t[j])  j++;
		prefix[i] = j;
	}
	for (auto now : prefix) cout << now << " ";
}