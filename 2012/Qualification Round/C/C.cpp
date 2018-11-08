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

vector<pair<int, int>> v;

int d[7];

int solve(int A, int B) {
    v.clear();
    for (int n = A; n <= B; ++n) {
        int len = 1;
        int tmp = n;
        for (;; ++len) {
            tmp /= 10;
            if (!tmp) break;
        }
        tmp = n;
        for (int i = len - 1;; --i) {
            d[i] = tmp % 10;
            tmp /= 10;
            if (!tmp) break;
        }
        for (int i = 0; i < len - 1; ++i) {
            if (d[len - 1 - i] == 0) {
                continue;
            }
            int m = 0;
            for (int j = len - 1 - i; j < len; ++j) {
                m = 10 * m + d[j];
            }
            for (int j = 0; j < len - 1 - i; ++j) {
                m = 10 * m + d[j];
            }
            if (n < m && m <= B) {
                v.push_back(make_pair(n, m));
            }
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v.size();
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
        int A, B;
        in >> A >> B;
        out << "Case #" << t + 1 << ": " << solve(A, B) << endl;
    }
    return 0;
}
