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

int A;
int B;

double probability[99999];

double solve() {
    double ret = 1.0 + B + 1.0;
    double p = 1.0;
    for (int i = A - 1; i >= 0; --i) {
        p *= probability[A - 1 - i];
        ret = min(ret, p * ((double)i + B - (A - (double)i) + 1.0) + (1.0 - p) * ((double)i + B - (A - (double)i) + 1.0 + B + 1.0));
    }
    return ret;
}

//#define LARGE

int main() {
#ifndef LARGE
    ifstream in("A-small-practice.in");
    FILE *out = fopen("A-small-practice.out", "w");
#else
    ifstream in("A-large-practice.in");
    FILE *out = fopen("A-large-practice.out", "w");
#endif
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> A >> B;
        for (int a = 0; a < A; ++a) {
            in >> probability[a];
        }
        fprintf(out, "Case #%d: %.6f\n", t + 1, solve());
    }
    fclose(out);
    return 0;
}
