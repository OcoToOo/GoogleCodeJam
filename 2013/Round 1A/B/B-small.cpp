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

int E;
int R;
int N;

int v[10];

int dfs(int i, int e) {
    if (i >= N) {
        return 0;
    }
    int best = 0;
    for (int j = 0; j <= e; ++j) {
        best = max(best, j * v[i] + dfs(i + 1, min(E, e - j + R)));
    }
    return best;
}

int main() {
    ifstream in("B-small-practice.in");
    ofstream out("B-small-practice.out");
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> E >> R >> N;
        for (int i = 0; i < N; ++i) {
            in >> v[i];
        }
        out << "Case #" << t + 1 << ": " << dfs(0, E) << endl;
    }
    return 0;
}
