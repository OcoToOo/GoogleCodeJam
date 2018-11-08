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

int L;
LL t;
int N;
int C;

int a[10000];

LL solve(vector<int>& d) {
    LL time = 0;
    int cur = 0;
    for (; cur < d.size(); ++cur) {
        if (time + d[cur] * 2 == t) {
            cur++;
            time = t;
            break;
        } else if (time + d[cur] * 2 > t) {
            d.insert(d.begin() + cur + 1, d[cur] - (t - time) / 2);
            cur++;
            time = t;
            break;
        }
        time += d[cur] * 2;
    }
    d.erase(d.begin(), d.begin() + cur);
    sort(d.rbegin(), d.rend());
    cur = 0;
    for (int l = 0; l < L; ++l, ++cur) {
        if (cur >= d.size()) {
            break;
        }
        time = time + d[cur];
    }
    for (; cur < d.size(); ++cur) {
        time = time + d[cur] * 2;
    }
    return time;
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
    for (int test = 0; test < T; ++test) {
        in >> L >> t >> N >> C;
        for (int c = 0; c < C; ++c) {
            in >> a[c];
        }
        vector<int> d(N);
        for (int n = 0; n < N; ++n) {
            d[n] = a[n % C];
        }
        out << "Case #" << test + 1 << ": " << solve(d) << endl;
    }
    return 0;
}
