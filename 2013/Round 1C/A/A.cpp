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

int dp[1000000];

bool isConsonants(char c) {
    return !(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o');
}

LL solve(string name, int n) {
    memset(dp, sizeof(dp), 0);
    int size = name.size();
    int cnt = 0;
    for (int i = 0; i < size; ++i) {
        if (isConsonants(name[i])) {
            cnt++;
        } else {
            cnt = 0;
        }
        dp[i] = cnt;
    }
    LL ret = 0;
    int done = 0;
    for (int i = 0; i < size; ++i) {
        if (dp[i] >= n) {
            int num = i - n + 1 + 1 - done;
            ret += (LL)num * (size - i);
            done += num;
        }
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
        string name;
        in >> name;
        int n;
        in >> n;
        out << "Case #" << t + 1 << ": " << solve(name, n) << endl;
    }
    return 0;
}
