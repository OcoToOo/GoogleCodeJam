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

int N;

int solve(vector<int>& v) {
    int ret = 0;
    while (!v.empty()) {
        int pos = distance(v.begin(), min_element(v.begin(), v.end()));
        ret += min(pos, (int)v.size() - 1 - pos);
        v.erase(v.begin() + pos);
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
        in >> N;
        vector<int> v(N);
        for (int n = 0; n < N; ++n) {
            in >> v[n];
        }
        out << "Case #" << t + 1 << ": " << solve(v) << endl;
    }
    return 0;
}
