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
bool b[16][16];

int solve2() {
    int ret = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (b[i][j]) {
                if (i != R - 1 && b[i + 1][j]) {
                    ret++;
                }
                if (j != C - 1 && b[i][j + 1]) {
                    ret++;
                }
            }
        }
    }
    return ret;
}

int solve() {
    int ret = INT_MAX;
    int n = R * C;
    for (int i = 0; i < (1 << n); ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if ((i & (1 << j))) {
                b[j / C][j % C] = true;
                cnt++;
            } else {
                b[j / C][j % C] = false;
            }
        }
        if (cnt != N) {
            continue;
        }
        ret = min(ret, solve2());
    }
    return ret;
}

int main() {
    ifstream in("B-small-practice.in");
    ofstream out("B-small-practice.out");
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> R >> C >> N;
        out << "Case #" << t + 1 << ": " << solve() << endl;
    }
    return 0;
}
