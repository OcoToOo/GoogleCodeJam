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

#define N_MAX 1000
#define L_MAX 2

int L;
LL t;
int N;
int C;

int a[10000];
int d[N_MAX];

LL dp[2][L_MAX + 1];

int solve() {
    memset(dp, 1e+10, sizeof(dp));
    for (int i = 0; i <= L; i++) {
        dp[0][i] = 0;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= L; ++j) {
            if (j == 0) {
                dp[(i + 1) & 1][j] = dp[i & 1][j] + d[i] * 2;
            } else {
                if (t > dp[i & 1][j - 1] && t < dp[i & 1][j - 1] + d[i] * 2) {
                    dp[(i + 1) & 1][j] = min(dp[i & 1][j - 1] + (t - dp[i & 1][j - 1]) + d[i] - (t - dp[i & 1][j - 1]) / 2, dp[i & 1][j] + d[i] * 2);
                } else if (t <= dp[i & 1][j - 1]) {
                    dp[(i + 1) & 1][j] = min(dp[i & 1][j - 1] + d[i], dp[i & 1][j] + d[i] * 2);
                } else {
                    dp[(i + 1) & 1][j] = min(dp[i & 1][j - 1] + d[i] * 2, dp[i & 1][j] + d[i] * 2);
                }
            }
        }
    }
    return dp[N & 1][L];
}

int main() {
    ifstream in("B-small-practice.in");
    ofstream out("B-small-practice.out");
    int T;
    in >> T;
    for (int test = 0; test < T; ++test) {
        in >> L >> t >> N >> C;
        for (int c = 0; c < C; ++c) {
            in >> a[c];
        }
        for (int n = 0; n < N; ++n) {
            d[n] = a[n % C];
        }
        out << "Case #" << test + 1 << ": " << solve() << endl;
    }
    return 0;
}
