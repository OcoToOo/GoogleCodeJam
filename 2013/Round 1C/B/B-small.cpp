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

string solve(int X, int Y) {
    string ret;
    int x = 0;
    int y = 0;
    while (x != X) {
        if (X > 0) {
            ret.append("WE");
            x++;
        } else {
            ret.append("EW");
            x--;
        }
    }
    while (y != Y) {
        if (Y > 0) {
            ret.append("SN");
            y++;
        } else {
            ret.append("NS");
            y--;
        }
    }
    return ret;
}

int main() {
    ifstream in("B-small-practice.in");
    ofstream out("B-small-practice.out");
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        int X, Y;
        in >> X >> Y;
        out << "Case #" << t + 1 << ": " << solve(X, Y) << endl;
    }
    return 0;
}
