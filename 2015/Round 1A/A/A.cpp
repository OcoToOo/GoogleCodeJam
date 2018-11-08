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

int solve1(vector<int>& v) {
    int size = v.size();
    int ret = 0;
    for (int i = 1; i < size; ++i) {
        ret += max(0, v[i - 1] - v[i]);
    }
    return ret;
}

int solve2(vector<int>& v) {
    int size = v.size();
    int hi = 0;
    for (int i = 1; i < size; ++i) {
        hi = max(hi, v[i - 1] - v[i]);
    }
    int ret = 0;
    for (int i = 0; i < size - 1; ++i) {
        ret += min(hi, v[i]);
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
        int N;
        in >> N;
        vector<int> v(N);
        for (int n = 0; n < N; ++n) {
            in >> v[n];
        }
        out << "Case #" << t + 1 << ": " << solve1(v) << " " << solve2(v) << endl;
    }
    return 0;
}
