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

int C;
int D;
int V;

int solve(vector<int>& v) {
    int ret = 0;
    int index = 0;
    LL sum = 0;
    for (LL n = 1; n <= V;) {
        bool changed = false;
        while (index < D && v[index] < n) {
            sum += v[index];
            index++;
            changed = true;
        }
        if (changed) {
            n = sum * C + 1;
            continue;
        }
        if (index >= D || v[index] != n) {
            ret++;
        } else {
            index++;
        }
        sum += n;
        n = sum * C + 1;
    }
    return ret;
}

//#define LARGE

int main() {
#ifndef LARGE
    ifstream in("C-small-practice.in");
    ofstream out("C-small-practice.out");
#else
    ifstream in("C-large-practice.in");
    ofstream out("C-large-practice.out");
#endif
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> C >> D >> V;
        vector<int> v(D);
        for (int d = 0; d < D; ++d) {
            in >> v[d];
        }
        sort(v.begin(), v.end());
        out << "Case #" << t + 1 << ": " << solve(v) << endl;
    }
    return 0;
}
