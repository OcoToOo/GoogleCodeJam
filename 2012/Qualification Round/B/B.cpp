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

int solve(int N, int S, int p, vector<int>& points) {
    int num = 0;
    for (int n = 0; n < N; ++n) {
        int point = points[n];
        int a = point / 3;
        int b = point % 3;
        if (!point) {
            b = 0;
        }
        if (a >= p || (b >= 1 && a + 1 >= p)) {
            num++;
        } else if (S && b >= 2 && a + 2 >= p) {
            num++;
            S--;
        } else if (S && (b == 0) && (a + 1 == p) && (a - 1 >= 0)) {
            num++;
            S--;
        }
    }
    return num;
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
        int N, S, p;
        in >> N >> S >> p;
        vector<int> points(N);
        for (int n = 0; n < N; ++n) {
            in >> points[n];
        }
        out << "Case #" << t + 1 << ": " << solve(N, S, p, points) << endl;
    }
    return 0;
}
