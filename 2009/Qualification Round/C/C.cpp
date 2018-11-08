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

const string S = "welcome to code jam";

const int mod = 10000;

int solve(string s) {
    int dp[20][501] = {};
    for (int i = 0; i <= 500; ++i) {
        dp[0][i] = 1;
    }
    int size = s.size();
    int ret = 0;
    for (int i = 0; i < 19; ++i) {
        char c = S[i];
        for (int j = 0; j < size; ++j) {
            if (s[j] == c) {
                dp[i + 1][j + 1] = dp[i][j];
            }
        }
        for (int j = 0; j < size; ++j) {
            dp[i + 1][j + 1] += dp[i + 1][j];
            dp[i + 1][j + 1] %= mod;
        }
    }
    return dp[19][size];
}

//#define LARGE

int main() {
#ifndef LARGE
    ifstream in("C-small-practice.in");
    FILE *out = fopen("C-small-practice.out", "w");
#else
    ifstream in("C-large-practice.in");
    FILE *out = fopen("C-large-practice.out", "w");
#endif
    string s;
    getline(in, s);
    int T = stoi(s, 0);
    for (int t = 0; t < T; ++t) {
        getline(in, s);
        fprintf(out, "Case #%d: %04d\n", t + 1, solve(s));
    }
    return 0;
}
