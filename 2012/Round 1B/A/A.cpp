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
int X;
int MAX;
int MIN;

int s[200];
double rate[200];

double can(double total) {
    for (int i = 0; i < N; ++i) {
        double reminder = total - s[i];
        if (reminder < 0.0) {
            rate[i] = 0.0;
        } else {
            rate[i] = reminder / (double)X;
        }
    }
    double sum = 0.0;
    for (int i = 0; i < N; ++i) {
        sum += rate[i];
    }
    return sum <= 1.0000000;
}

void solve() {
    double lb = MIN;
    double ub = MAX + X;
    for (int i = 0; i < 100; ++i) {
        double mid = (lb + ub) / 2.0;
        if (can(mid)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    can(lb);
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
        X = 0;
        MAX = 0;
        MIN = INT_MAX;
        in >> N;
        for (int i = 0; i < N; ++i) {
            in >> s[i];
            X += s[i];
            MAX = max(MAX, s[i]);
            MIN = min(MIN, s[i]);
        }
        solve();
        fprintf(out, "Case #%d: ", t + 1);
        for (int i = 0; i < N; ++i) {
            fprintf(out, "%.5f ", rate[i] * 100.0);
        }
        fprintf(out, "\n");
    }
    fclose(out);
    return 0;
}
