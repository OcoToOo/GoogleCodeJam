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

string solve(int X, int R, int C) {
    switch (X) {
        case 1:
            return "GABRIEL";
        case 2:
            if (R % 2 == 0 || C % 2 == 0) {
                return "GABRIEL";
            } else {
                return "RICHARD";
            }
        case 3:
            if ((R == 3 && C >= 2) || (C == 3 && R >= 2)) {
                return "GABRIEL";
            } else {
                return "RICHARD";
            }
        case 4:
            if ((R == 4 && C >= 3) || (C == 4 && R >= 3)) {
                return "GABRIEL";
            } else {
                return "RICHARD";
            }
    }
    return "";
}

int main() {
    ifstream in("D-small-practice.in");
    ofstream out("D-small-practice.out");
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        int X, R, C;
        in >> X >> R >> C;
        out << "Case #" << t + 1 << ": " << solve(X, R, C) << endl;
    }
    return 0;
}
