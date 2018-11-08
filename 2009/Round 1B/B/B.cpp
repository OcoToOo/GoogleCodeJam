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

string solve(string s) {
    int size = s.size();
    if (next_permutation(s.begin(), s.end())) {
        return s;
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < size; ++i) {
        if (s[i] != '0') {
            swap(s[0], s[i]);
            break;
        }
    }
    s.insert(s.begin() + 1, '0');
    return s;
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
        string s;
        in >> s;
        out << "Case #" << t + 1 << ": " << solve(s) << endl;
    }
    return 0;
}
