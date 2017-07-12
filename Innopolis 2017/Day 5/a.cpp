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
    freopen("grig.in", "r", stdin);
    freopen("grig.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    srand(time(NULL));
    lli n, k;
    cin >> n >> k;
    vector<lli> a(n,0);
    a[0] = 1;
    for (lli i = 0; i < n; i++) {
        for (lli j = i + 1; j < min(n, i + k + 1); j++) a[j] += a[i];
    }
    cout << a[n - 1];
}