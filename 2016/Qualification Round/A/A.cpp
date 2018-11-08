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

int solve(LL N) {
    set<int> s;
    for (int i = 1;; ++i) {
        LL n = N * i;
        while (n) {
            s.insert(n % 10);
            n /= 10;
        }
        if (s.size() == 10) {
            return N * i;
        }
    }
    return 0;
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
        if (N == 0) {
            out << "Case #" << t + 1 << ": "
                << "INSOMNIA" << endl;
        } else {
            out << "Case #" << t + 1 << ": " << solve(N) << endl;
        }
    }

    return 0;
}
