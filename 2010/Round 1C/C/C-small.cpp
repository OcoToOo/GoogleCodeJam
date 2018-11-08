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

int M;
int N;

bool check(int sy, int sx, vector<vector<int>>& v, vector<vector<bool>>& done, int len, int flag) {
    for (int i = sy; i < sy + len; ++i) {
        for (int j = sx; j < sx + len; ++j) {
            if (done[i][j]) {
                return false;
            }
            if (((i - sy) % 2 ^ (j - sx) % 2 ^ flag) != v[i][j]) {
                return false;
            }
        }
    }
    for (int i = sy; i < sy + len; ++i) {
        for (int j = sx; j < sx + len; ++j) {
            done[i][j] = true;
        }
    }
    return true;
}

vector<pair<int, int>> solve(vector<vector<int>>& v) {
    vector<pair<int, int>> ret;
    vector<vector<bool>> done(M, vector<bool>(N, false));
    for (int len = min(M, N); len >= 1; --len) {
        int cnt = 0;
        for (int i = 0; i <= M - len; ++i) {
            for (int j = 0; j <= N - len; ++j) {
                if (done[i][j]) {
                    continue;
                }
                if (check(i, j, v, done, len, v[i][j])) {
                    cnt++;
                }
            }
        }
        if (cnt) {
            ret.push_back(make_pair(len, cnt));
        }
    }
    return ret;
}

int main() {
    ifstream in("C-small-practice.in");
    ofstream out("C-small-practice.out");
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> M >> N;
        vector<vector<int>> v(M, vector<int>(N));
        for (int m = 0; m < M; ++m) {
            string s;
            in >> s;
            for (int n = 0; n < N / 4; ++n) {
                int i = stoi(s.substr(n, 1), 0, 16);
                for (int l = 0; l < 4; ++l) {
                    v[m][n * 4 + l] = (i & (1 << 4 - l - 1)) == 0 ? 0 : 1;
                }
            }
        }
        vector<pair<int, int>> ret = solve(v);
        int size = ret.size();
        out << "Case #" << t + 1 << ": " << size << endl;
        for (int i = 0; i < size; ++i) {
            out << ret[i].first << " " << ret[i].second << endl;
        }
    }
    return 0;
}
