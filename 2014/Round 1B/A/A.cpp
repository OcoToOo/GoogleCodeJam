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
vector<char> characters[100];
vector<int> nums[100];

int solve(vector<string>& v) {
    for (int i = 0; i < N; ++i) {
        characters[i].clear();
        nums[i].clear();
        char c = '.';
        int cnt = 0;
        for (int j = 0; j < v[i].size(); ++j) {
            if (c == '.') {
                characters[i].push_back(v[i][j]);
                c = v[i][j];
                cnt++;
            } else if (v[i][j] != c) {
                characters[i].push_back(v[i][j]);
                nums[i].push_back(cnt);
                c = v[i][j];
                cnt = 1;
            } else {
                cnt++;
            }
            if (j == (int)(v[i].size()) - 1) {
                nums[i].push_back(cnt);
            }
        }
    }
    for (int i = 1; i < N; ++i) {
        if (characters[0] != characters[i]) {
            return -1;
        }
    }
    int ret = 0;
    for (int i = 0; i < nums[0].size(); ++i) {
        int mini = INT_MAX;
        for (int j = 1; j <= 100; ++j) {
            int cnt = 0;
            for (int n = 0; n < N; ++n) {
                cnt += abs(nums[n][i] - j);
            }
            mini = min(mini, cnt);
        }
        ret += mini;
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
        in >> N;
        vector<string> v(N);
        for (int n = 0; n < N; ++n) {
            in >> v[n];
        }
        int ret = solve(v);
        if (ret == -1) {
            out << "Case #" << t + 1 << ": "
                << "Fegla Won" << endl;
        } else {
            out << "Case #" << t + 1 << ": " << ret << endl;
        }
    }
    return 0;
}
