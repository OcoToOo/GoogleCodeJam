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

int N;

int a[20];

vector<vector<int>> solve() {
    map<int, vector<int>> sums;
    vector<vector<int>> ret;
    for (int i = 1; i < (1 << N); ++i) {
        vector<int> v;
        int sum = 0;
        int num = 0;
        for (int j = 0; j < N; ++j) {
            if ((i & (1 << j))) {
                sum += a[j];
                v.push_back(a[j]);
            }
        }
        map<int, vector<int>>::iterator itr = sums.find(sum);
        if (itr != sums.end()) {
            ret.push_back(itr->second);
            ret.push_back(v);
            return ret;
        }
        sums.insert(make_pair(sum, v));
    }
    return ret;
}

int main() {
    ifstream in("C-small-practice.in");
    ofstream out("C-small-practice.out");
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> N;
        for (int n = 0; n < N; ++n) {
            in >> a[n];
        }
        vector<vector<int>> ret = solve();
        out << "Case #" << t + 1 << ":" << endl;
        if (ret.size() == 2) {
            for (int i = 0; i < ret[0].size(); ++i) {
                out << ret[0][i] << " ";
            }
            out << endl;
            for (int i = 0; i < ret[1].size(); ++i) {
                out << ret[1][i] << " ";
            }
            out << endl;
        } else {
            out << "Impossible" << endl;
        }
    }
    return 0;
}
