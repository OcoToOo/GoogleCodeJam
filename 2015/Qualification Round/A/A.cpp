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

int solve(vector<int>& levels) {
    int ret = 0;
    int size = levels.size();
    int sum = levels[0];
    for (int i = 1; i < size; ++i) {
        if (i > sum) {
            ret += i - sum;
            sum += i - sum;
        }
        sum += levels[i];
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
        int S;
        in >> S;
        string s;
        in >> s;
        vector<int> levels(S + 1);
        for (int i = 0; i <= S; ++i) {
            levels[i] = s[i] - '0';
        }
        out << "Case #" << t + 1 << ": " << solve(levels) << endl;
    }
    return 0;
}
