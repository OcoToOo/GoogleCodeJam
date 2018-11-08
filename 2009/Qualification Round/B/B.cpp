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

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

vector<vector<int>> solve(int H, int W, vector<vector<int>>& v) {
    vector<vector<int>> sinks(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int x = j;
            int y = i;
            while (1) {
                int lo = v[y][x];
                int cx = -1;
                int cy = -1;
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx < 0 || nx >= W || ny < 0 || ny >= H) {
                        continue;
                    }
                    if (v[ny][nx] < lo) {
                        cx = nx;
                        cy = ny;
                        lo = v[ny][nx];
                    }
                }
                if (cx == -1) {
                    break;
                }
                x = cx;
                y = cy;
            }
            sinks[i][j] = y * W + x;
        }
    }
    vector<vector<int>> ret(H, vector<int>(W, -1));
    int label = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (ret[i][j] != -1) {
                continue;
            }
            int sink = sinks[i][j];
            for (int k = 0; k < H; ++k) {
                for (int l = 0; l < W; ++l) {
                    if (sinks[k][l] == sink) {
                        ret[k][l] = label;
                    }
                }
            }
            label++;
        }
    }
    return ret;
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
        int H, W;
        in >> H >> W;
        vector<vector<int>> v(H, vector<int>(W));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                in >> v[i][j];
            }
        }
        vector<vector<int>> labels = solve(H, W, v);
        out << "Case #" << t + 1 << ":" << endl;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                char c = labels[i][j] + 'a';
                out << c << " ";
            }
            out << endl;
        }
    }
    return 0;
}
