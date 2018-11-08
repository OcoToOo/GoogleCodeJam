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

const int INF = INT_MAX;

int D;
int I;
int M;
int N;

int solve(vector<int>& a) {
    int dp[202][256] = {};
    for (int i = 0; i < 202; ++i) {
        for (int j = 0; j <= 255; ++j) {
            dp[i][j] = INF;
        }
    }
    for (int i = 0; i <= 255; ++i) {
        dp[0][i] = dp[1][i] = 0;
    }
    for (int i = 0; i < N * 2; ++i) {
        if (!(i % 2)) {
            // not insert
            for (int j = 0; j <= 255; ++j) {
                dp[i + 2][j] = min(dp[i + 2][j], dp[i + 1][j]);
            }
            // insert
            if (M != 0) {
                for (int j = 0; j <= 255; ++j) {
                    for (int k = 0; k <= 255; ++k) {
                        int num = (abs(j - k) + M - 1) / M;
                        dp[i + 2][k] = min(dp[i + 2][k], dp[i + 1][j] + num * I);
                    }
                }
            }
        }
        if (i % 2) {
            // change
            for (int j = 0; j <= 255; ++j) {
                for (int k = -M; k <= M; ++k) {
                    int next = j + k;
                    if (next < 0 || next > 255) {
                        continue;
                    }
                    dp[i + 2][next] = min(dp[i + 2][next], dp[i + 1][j] + abs(a[i / 2] - next));
                }
            }
            // delete
            for (int j = 0; j <= 255; ++j) {
                dp[i + 2][j] = min(dp[i + 2][j], dp[i + 1][j] + D);
            }
        }
    }
    int ret = INT_MAX;
    for (int i = 0; i <= 255; ++i) {
        ret = min(ret, dp[N * 2 + 1][i]);
    }
    return ret;
}

//#define LARGE

int main() {
#ifndef LARGE
    ifstream in("B-small-practice.in");
    ofstream out("B-small-practice.out");
#else
    ifstream in("B-large-practice.in");
    ofstream out("B-large-practice.out");
#endif
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> D >> I >> M >> N;
        vector<int> a(N);
        for (int n = 0; n < N; ++n) {
            in >> a[n];
        }
        out << "Case #" << t + 1 << ": " << solve(a) << endl;
    }
    return 0;
}
