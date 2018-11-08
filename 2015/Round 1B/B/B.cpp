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

int R, C, N;
bool b[10000][10000];

int solve2(int num) {
    int ret = 0;
    if (num >= N) {
        return ret;
    }
    if (!b[0][0]) {
        b[0][0] = true;
        if (C > 1) {
            ret++;
        }
        if (R > 1) {
            ret++;
        }
        num++;
        if (num >= N) {
            return ret;
        }
    }
    if (!b[0][C - 1]) {
        b[0][C - 1] = true;
        ret++;
        if (R > 1) {
            ret++;
        }
        num++;
        if (num >= N) {
            return ret;
        }
    }
    if (!b[R - 1][0]) {
        b[R - 1][0] = true;
        ret++;
        if (C > 1) {
            ret++;
        }
        num++;
        if (num >= N) {
            return ret;
        }
    }
    if (!b[R - 1][C - 1]) {
        b[R - 1][C - 1] = true;
        ret += 2;
        num++;
        if (num >= N) {
            return ret;
        }
    }
    for (int j = 0; j < C; ++j) {
        if (!b[0][j]) {
            b[0][j] = true;
            ret += 2;
            if (R > 1) {
                ret++;
            }
            num++;
            if (num >= N) {
                return ret;
            }
        }
    }
    for (int i = 0; i < R; ++i) {
        if (!b[i][0]) {
            b[i][0] = true;
            ret += 2;
            if (C > 1) {
                ret++;
            }
            num++;
            if (num >= N) {
                return ret;
            }
        }
    }
    for (int j = 0; j < C; ++j) {
        if (!b[R - 1][j]) {
            b[R - 1][j] = true;
            ret += 3;
            num++;
            if (num >= N) {
                return ret;
            }
        }
    }
    for (int i = 0; i < R; ++i) {
        if (!b[i][C - 1]) {
            b[i][C - 1] = true;
            ret += 3;
            num++;
            if (num >= N) {
                return ret;
            }
        }
    }
    return ret + 4 * (N - num);
}

int solve() {
    int ret = INT_MAX;
    int num = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            b[i][j] = false;
            if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
                b[i][j] = true;
                num++;
            }
        }
    }
    ret = min(ret, solve2(num));
    num = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            b[i][j] = false;
            if ((i % 2 == 0 && j % 2 == 1) || (i % 2 == 1 && j % 2 == 0)) {
                b[i][j] = true;
                num++;
            }
        }
    }
    ret = min(ret, solve2(num));
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
        in >> R >> C >> N;
        out << "Case #" << t + 1 << ": " << solve() << endl;
    }
    return 0;
}
