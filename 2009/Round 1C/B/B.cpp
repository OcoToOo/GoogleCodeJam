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

double ax;
double ay;
double az;
double avx;
double avy;
double avz;

double dmin;
double tmin;

double func(double t) {
    return sqrt((ax + t * avx) * (ax + t * avx) + (ay + t * avy) * (ay + t * avy) + (az + t * avz) * (az + t * avz));
}

void solve() {
    // trinary_search
    double lb = 0;
    double ub = 1e+8;
    for (int i = 0; i < 1000; ++i) {
        if (func((lb * 2 + ub) / 3) <= func((lb + ub * 2) / 3)) {
            ub = (lb + ub * 2) / 3;
        } else {
            lb = (lb * 2 + ub) / 3;
        }
    }
    tmin = (ub + lb) * 0.5;
    dmin = func(tmin);
}

//#define LARGE

int main() {
#ifndef LARGE
    ifstream in("B-small-practice.in");
    FILE *fout = fopen("B-small-practice.out", "w");
#else
    ifstream in("B-large-practice.in");
    FILE *fout = fopen("B-large-practice.out", "w");
#endif
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        in >> N;
        ax = 0, ay = 0, az = 0, avx = 0, avy = 0, avz = 0;
        for (int n = 0; n < N; ++n) {
            int x, y, z, vx, vy, vz;
            in >> x >> y >> z >> vx >> vy >> vz;
            ax += x;
            ay += y;
            az += z;
            avx += vx;
            avy += vy;
            avz += vz;
        }
        ax /= N;
        ay /= N;
        az /= N;
        avx /= N;
        avy /= N;
        avz /= N;
        solve();
        fprintf(fout, "Case #%d: %.8f %.8f\n", t + 1, dmin, tmin);
    }
    return 0;
}
