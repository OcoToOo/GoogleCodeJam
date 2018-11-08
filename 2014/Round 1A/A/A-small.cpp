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
int L;

int solve(vector<string>& op, vector<string>& de) {
    sort(de.begin(), de.end());
    int ret = L + 1;
    for (int i = 0; i < (1 << L); ++i) {
        vector<string> v = op;
        int cnt = 0;
        for (int j = 0; j < L; ++j) {
            if ((i & (1 << j))) {
                cnt++;
                for (int k = 0; k < N; ++k) {
                    v[k][j] = (v[k][j] == '1' ? '0' : '1');
                }
            }
        }
        sort(v.begin(), v.end());
        if (v == de) {
            ret = min(ret, cnt);
        }
    }
    return ret;
}

int main() {
    ifstream in("A-small-practice.in");
    ofstream out("A-small-practice.out");
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> N;
        in >> L;
        vector<string> op(N);
        vector<string> de(N);
        for (int n = 0; n < N; ++n) {
            in >> op[n];
        }
        for (int n = 0; n < N; ++n) {
            in >> de[n];
        }
        int ret = solve(op, de);
        if (ret == L + 1) {
            out << "Case #" << t + 1 << ": "
                << "NOT POSSIBLE" << endl;
        } else {
            out << "Case #" << t + 1 << ": " << ret << endl;
        }
    }
    return 0;
}
