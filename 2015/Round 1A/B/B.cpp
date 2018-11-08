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

int B;
int N;

bool func(LL n, vector<int>& v) {
    LL sum = 0;
    for (int i = 0; i < B; ++i) {
        sum += (n + v[i] - 1) / v[i];
    }
    return sum >= N;
}

int solve(vector<int>& v) {
    LL hi = 100000LL * N;
    LL lo = 0;
    while (hi - lo > 1) {
        LL mid = (hi + lo) / 2;
        if (func(mid, v)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    LL total = 0;
    for (int i = 0; i < B; ++i) {
        total += (hi - 1 + v[i] - 1) / v[i];
    }
    for (int i = 0; i < B; i++) {
        if (((hi + v[i] - 1) / v[i]) != (hi - 1 + v[i] - 1) / v[i]) {
            total++;
        }
        if (total >= N) {
            return i + 1;
        }
    }
    return 0;
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
        in >> B >> N;
        vector<int> M(B);
        for (int m = 0; m < B; ++m) {
            in >> M[m];
        }
        out << "Case #" << t + 1 << ": " << solve(M) << endl;
    }
    return 0;
}
