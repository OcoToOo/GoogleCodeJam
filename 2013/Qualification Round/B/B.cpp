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
int M;

string solve(vector<vector<int>>& lawn) {
    vector<vector<int>> init;
    for (int n = 0; n < N; ++n) {
        vector<int> v(M, 100);
        init.push_back(v);
    }

    for (int n = 0; n < N; ++n) {
        for (int m = 0; m < M; ++m) {
            int h = lawn[n][m];

            bool ok = true;
            for (int x = 0; x < M; ++x) {
                if (lawn[n][x] > h) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                for (int x = 0; x < M; ++x) {
                    init[n][x] = min(h, init[n][x]);
                }
            }

            ok = true;
            for (int y = 0; y < N; ++y) {
                if (lawn[y][m] > h) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                for (int y = 0; y < N; ++y) {
                    init[y][m] = min(h, init[y][m]);
                }
            }
        }
    }

    for (int n = 0; n < N; ++n) {
        for (int m = 0; m < M; ++m) {
            if (init[n][m] != lawn[n][m]) {
                return "NO";
            }
        }
    }
    return "YES";
}

//#define LARGE

int main() {
#ifndef LARGE
    ifstream in("B-small-practice.in");
    ofstream out("B-small-practice.out");
#else
    ifstream in("B-large-practice.in");
    ofstream out("B-large-practice.out");
#endif
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> N >> M;
        vector<vector<int>> lawn(N, vector<int>(M));
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                in >> lawn[n][m];
            }
        }
        string s = solve(lawn);
        out << "Case #" << t + 1 << ": " << solve(lawn).c_str() << endl;
    }
    return 0;
}
