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

LL solve(vector<int>& x, vector<int>& y) {
    sort(x.begin(), x.end());
    sort(y.rbegin(), y.rend());
    LL ret = 0;
    for (int i = 0; i < (int)x.size(); ++i) {
        ret += (LL)x[i] * y[i];
    }
    return ret;
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
    for (int t = 0; t < T; ++t) {
        int n;
        in >> n;
        vector<int> x(n);
        vector<int> y(n);
        for (int i = 0; i < n; ++i) {
            in >> x[i];
        }
        for (int i = 0; i < n; ++i) {
            in >> y[i];
        }
        out << "Case #" << t + 1 << ": " << solve(x, y) << endl;
    }
    return 0;
}
