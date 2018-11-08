#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

int dp[1000001];

void solve() {
    for (int i = 0; i <= 1000000; ++i) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int i = 0; i < 1000000; ++i) {
        bool flag = false;
        int j = 0;
        int n = i;
        while (n) {
            if (n % 10 || flag) {
                j = j * 10 + n % 10;
                flag = true;
            }
            n /= 10;
        }
        if (j > i && j <= 1000000) {
            if (dp[j] > dp[i] + 1) {
                dp[j] = dp[i] + 1;
            }
        }
        if (dp[i + 1] > dp[i] + 1) {
            dp[i + 1] = dp[i] + 1;
        }
    }
}

int main() {
    ifstream in("A-small-practice.in");
    ofstream out("A-small-practice.out");
    solve();
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        in >> N;
        out << "Case #" << t + 1 << ": " << dp[N] << endl;
    }
    return 0;
}
