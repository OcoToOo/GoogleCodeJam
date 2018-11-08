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

int C;
int D;
int V;

vector<int> v;

bool dfs(int index, int goal, int now) {
    if (now == goal) {
        return true;
    }
    if (now > goal) {
        return false;
    }
    if (index == v.size()) {
        return false;
    }
    if (dfs(index + 1, goal, now + v[index])) {
        return true;
    }
    if (dfs(index + 1, goal, now)) {
        return true;
    }
    return false;
}

int solve() {
    for (int i = 1; i <= V; ++i) {
        if (!dfs(0, i, 0)) {
            v.push_back(i);
            sort(v.begin(), v.end());
        }
    }
    return v.size() - D;
}

int main() {
    ifstream in("C-small-practice.in");
    ofstream out("C-small-practice.out");
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> C >> D >> V;
        v.clear();
        for (int d = 0; d < D; ++d) {
            int n;
            in >> n;
            v.push_back(n);
        }
        out << "Case #" << t + 1 << ": " << solve() << endl;
    }
    return 0;
}
