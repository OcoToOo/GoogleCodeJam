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

double position[1000000];

bool can(double t, double D) {
    double current = -1.0e+13;
    for (int i = 0; i < N; ++i) {
        current = max(position[i] - t, current + D);
        if (current > position[i] + t) {
            return false;
        }
    }
    return true;
}

double solve(double D) {
    double ub = 1.0e+13;
    double lb = 0.0;
    for (int i = 0; i < 100; ++i) {
        double mid = (ub + lb) / 2;
        if (can(mid, D)) {
            ub = mid;
        } else {
            lb = mid;
        }
    }
    return ub;
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
        int C;
        in >> C;
        int D;
        in >> D;
        N = 0;
        for (int c = 0; c < C; ++c) {
            int P;
            in >> P;
            int V;
            in >> V;
            for (int v = 0; v < V; ++v) {
                position[N + v] = (double)P;
            }
            N += V;
        }
        fprintf(out, "Case #%d: %.6f\n", t + 1, solve(D));
    }
    fclose(out);
    return 0;
}
