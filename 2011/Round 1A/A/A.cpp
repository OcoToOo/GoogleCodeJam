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

long long N;
int Pd;
int Pg;

LL func() {
    int d = Pd;
    LL g = 100;
    for (int i = 2; i * i <= d; ++i) {
        while (d % i == 0) {
            d /= i;
            if (g % i == 0) {
                g /= i;
            }
        }
    }
    if (d != 1 && g % d == 0) {
        g /= d;
    }
    return g;
}

bool solve() {
    if (Pg == 100 && Pd != 100) {
        return false;
    }
    if (Pg == 100 && Pd == 100) {
        return true;
    }
    if (Pg == 0 && Pd != 0) {
        return false;
    }
    if (Pg == 0 && Pd == 0) {
        return true;
    }
    if (func() <= N) {
        return true;
    }
    return false;
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
        in >> N >> Pd >> Pg;
        out << "Case #" << t + 1 << ": " << (solve() ? "Possible" : "Broken") << endl;
    }
    return 0;
}
