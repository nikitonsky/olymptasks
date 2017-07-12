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
    //freopen("phones.in", "r", stdin);
    //freopen("phones.out", "w", stdout);
#endif // _DEBUG
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    lli a = 0, ab = 0,abc=0;
    for (auto now : s) {
        switch (now)
        {
        case 'a':
            a++;
            break;
        case 'b':
            ab+=a;
            break;
        case 'c':
            abc += ab;
            break;
        default:
            break;
        }
    }
    cout << abc;
}