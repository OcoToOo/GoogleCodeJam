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

double C;
double F;
double X;

double solve() {
    double p = 2.0;
    double min = X / p;
    double total = 0.0;
    while (1) {
        double time = total + X / p;
        if (time > min) {
            break;
        }
        min = time;
        total += C / p;
        p += F;
    }
    return min;
}

//#define LARGE

int main() {
#ifndef LARGE
    ifstream in("B-small-practice.in");
    FILE *out = fopen("B-small-practice.out", "w");
#else
    ifstream in("B-large-practice.in");
    FILE *out = fopen("B-large-practice.out", "w");
#endif
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> C >> F >> X;
        fprintf(out, "Case #%d: %.7f\n", t + 1, solve());
    }
    return 0;
}
