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

string solve(int N, int K) {
    if (K == 0) {
        return "OFF";
    }
    if ((K + 1) % (LL)pow(2, N) == 0) {
        return "ON";
    }
    return "OFF";
}

//#define LARGE

int main() {
#ifndef LARGE
    ifstream in("A-small-practice.in");
    ofstream out("A-small-practice.out");
#else
    ifstream in("A-large-practice.in");
    ofstream out("A-large-practic.out");
#endif
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        int N, K;
        in >> N >> K;
        out << "Case #" << t + 1 << ": " << solve(N, K) << endl;
    }
    return 0;
}
