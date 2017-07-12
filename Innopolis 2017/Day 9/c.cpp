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
	freopen("floyd.in", "r", stdin);
	freopen("floyd.out", "w", stdout);
#endif // _DEBUG
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	lli n;
	cin >> n;
	vector<vector<lli>> a(n, vector<lli>(n));
	for (lli i = 0; i < n; i++)
		for (lli j = 0; j < n; j++)
			cin >> a[i][j];
	for (lli k = 0; k<n; ++k)
		for (lli i = 0; i<n; ++i)
			for (lli j = 0; j<n; ++j)
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
	for (auto d : a) {
		for (auto now : d) cout << now << " ";
		cout << "\n";
	}
}