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

int solve(vector<int>& v) {
    int size = v.size();
    int ret = 1000;
    for (int i = 1; i < 1000; ++i) {
        int cnt = 0;
        for (int j = 0; j < size; ++j) {
            if (v[j] <= i) {
                continue;
            }
            cnt += ((v[j] - i) + (i - 1)) / i;
        }
        cnt += i;
        ret = min(ret, cnt);
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
        int D;
        in >> D;
        vector<int> v(D);
        for (int d = 0; d < D; ++d) {
            in >> v[d];
        }
        out << "Case #" << t + 1 << ": " << solve(v) << endl;
    }
    return 0;
}
