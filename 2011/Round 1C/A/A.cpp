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

int R;
int C;

int movex[] = {1, 0, 1};
int movey[] = {0, 1, 1};

bool solve(vector<vector<char>>& pictures) {
    for (int y = 0; y < R; ++y) {
        for (int x = 0; x < C; ++x) {
            if (pictures[y][x] == '#') {
                pictures[y][x] = '/';
                for (int i = 0; i < 3; ++i) {
                    int nx = x + movex[i];
                    int ny = y + movey[i];
                    if (nx >= C || ny >= R) {
                        return false;
                    }
                    if (pictures[ny][nx] != '#') {
                        return false;
                    }
                    if (i == 0 || i == 1) {
                        pictures[ny][nx] = '\\';
                    } else {
                        pictures[ny][nx] = '/';
                    }
                }
                x++;
            }
        }
    }
    return true;
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
        in >> R >> C;
        vector<vector<char>> pictures(R, vector<char>(C));
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                in >> pictures[r][c];
            }
        }
        out << "Case #" << t + 1 << ":" << endl;
        if (solve(pictures)) {
            for (int r = 0; r < R; ++r) {
                for (int c = 0; c < C; c++) {
                    out << pictures[r][c];
                }
                out << endl;
            }
        } else {
            out << "Impossible" << endl;
        }
    }
    return 0;
}
