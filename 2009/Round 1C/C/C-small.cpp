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

int P, Q;

int solve2(vector<int>& v, vector<int>& w) {
    bool done[100] = {};
    int ret = 0;
    for (int i = 0; i < Q; ++i) {
        int cnt = 0;
        int pos = v[w[i]] - 1;
        done[pos] = true;
        for (int j = pos - 1; j >= 0; --j) {
            if (!done[j]) {
                cnt++;
            } else {
                break;
            }
        }
        for (int j = pos + 1; j < P; ++j) {
            if (!done[j]) {
                cnt++;
            } else {
                break;
            }
        }
        ret += cnt;
    }
    return ret;
}

int solve(vector<int>& v) {
    int ret = INT_MAX;
    vector<int> w;
    for (int i = 0; i < Q; ++i) {
        w.push_back(i);
    }
    do {
        ret = min(ret, solve2(v, w));
    } while (next_permutation(w.begin(), w.end()));
    return ret;
}

#define LARGE

int main() {
    ifstream in("C-small-practice.in");
    ofstream out("C-small-practice.out");
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> P >> Q;
        vector<int> v(Q);
        for (int q = 0; q < Q; ++q) {
            in >> v[q];
        }
        out << "Case #" << t + 1 << ": " << solve(v) << endl;
    }
    return 0;
}
