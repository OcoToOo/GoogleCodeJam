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

LL getLL(string s) {
    istringstream istr(s);
    LL i;
    istr >> i;
    return i;
}

LL gcd(LL a, LL b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int solve(LL P, LL Q) {
    int ret = 0;
    while (P < Q) {
        ret++;
        Q /= 2;
    }
    return ret;
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
        string s;
        in >> s;
        int index = s.find('/', 0);
        string p = s.substr(0, index);
        LL P = getLL(p);
        string q = s.substr(index + 1, (int)s.size() - (index + 1));
        LL Q = getLL(q);
        LL W = gcd(P, Q);
        P /= W;
        Q /= W;
        if (Q & Q - 1) {
            out << "Case #" << t + 1 << ": "
                << "impossible" << endl;
        } else {
            out << "Case #" << t + 1 << ": " << solve(P, Q) << endl;
        }
    }
    return 0;
}
