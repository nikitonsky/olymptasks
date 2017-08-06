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
#define ulli unsigned long long int
using namespace std;

const unsigned long long P = 31;

int getInt(char c)
{
	return c - 'a' + 1;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("substrcmp.in", "r", stdin);
	freopen("substrcmp.out", "w", stdout);
#endif // _DEBUG
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	vector<ulli> power(s.length() + 1);
	power[0] = 1;
	for (lli i = 1; i <= s.length(); i++)
		power[i] = power[i - 1] * P;
	vector<ulli> hash(s.length() + 1);
	for (lli i = 1; i <= s.length(); i++)
		hash[i] = (hash[i - 1] + s[i - 1]) * P;
	lli n;
	cin >> n;
	for (lli i = 0; i < n; i++)
	{
		lli x, y, l, r;
		cin >> l >> r >> x >> y;
		if (y - x != r - l) cout << "No\n";
		else {
			ulli fir = hash[r] - hash[l - 1] * power[r - l + 1], sec = hash[y] - hash[x - 1] * power[y - x + 1];
			if (fir == sec)
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}
}