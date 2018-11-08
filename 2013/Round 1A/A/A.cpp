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

bool func(LL r, LL t, LL n) {
    return 2 * n + 2 * r - 1 <= t / n;
}

LL solve(LL r, LL t) {
    LL ub = t;
    LL lb = 1;
    while (ub - lb > 1) {
        LL mid = (ub + lb) / 2;
        if (func(r, t, mid)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    return lb;
}

//#define LARGE

int main() {
#ifndef LARGE
    ifstream in("A-small-practice.in");
    ofstream out("A-small-practice.out");
#else
    ifstream in("A-large-practice.in");
    ofstream out("A-large-practice.out");
#endif
    int T;
    in >> T;
    for (int c = 0; c < T; ++c) {
        LL r, t;
        in >> r >> t;
        out << "Case #" << c + 1 << ": " << solve(r, t) << endl;
    }
    return 0;
}
