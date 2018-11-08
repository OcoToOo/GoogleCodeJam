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

int solve(string& S) {
    string s;
    s += S[0];
    for (int i = 1; i < S.length(); ++i) {
        if (S[i] != S[i - 1]) {
            s += S[i];
        }
    }
    if (s[s.length() - 1] == '+') {
        return s.length() - 1;
    }
    return s.length();
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
        string S;
        in >> S;
        out << "Case #" << t + 1 << ": " << solve(S) << endl;
    }
    return 0;
}
