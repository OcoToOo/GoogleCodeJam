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

int H;
int N;
int M;

int c[100][100];
int f[100][100];
double t[100][100];

int movex[] = {0, -1, 1, 0};
int movey[] = {-1, 0, 0, 1};

double dijkstra() {
    for (int n = 0; n < N; ++n) {
        for (int m = 0; m < M; ++m) {
            t[n][m] = DBL_MAX;
        }
    }
    priority_queue<pair<double, PII>, vector<pair<double, PII>>, greater<pair<double, PII>>> q;
    q.push(make_pair(0.0, make_pair(0, 0)));
    while (!q.empty()) {
        pair<double, PII> p = q.top();
        q.pop();
        int x = p.second.second;
        int y = p.second.first;
        double time = p.first;
        if (time > t[p.second.first][p.second.second]) {
            continue;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + movex[i];
            int ny = y + movey[i];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
                continue;
            }
            if (c[ny][nx] - f[y][x] < 50) {
                continue;
            }
            if (c[ny][nx] - f[ny][nx] < 50) {
                continue;
            }
            if (c[y][x] - f[ny][nx] < 50) {
                continue;
            }
            double pass = 0.0;
            double currentHeight = (double)H - time * 10.0;
            if (c[ny][nx] - currentHeight < 50.0) {
                pass += (50.0 - (c[ny][nx] - currentHeight)) / 10.0;
                currentHeight -= (50.0 - (c[ny][nx] - currentHeight));
            }
            if (currentHeight != H) {
                if (currentHeight - f[y][x] < 20.0) {
                    pass += 10.0;
                } else {
                    pass += 1.0;
                }
            }
            if (t[ny][nx] > time + pass) {
                t[ny][nx] = time + pass;
                q.push(make_pair(t[ny][nx], make_pair(ny, nx)));
            }
        }
    }
    return t[N - 1][M - 1];
}

//#define LARGE

int main() {
#ifndef LARGE
    ifstream in("B-small-practice.in");
    FILE *out = fopen("B-small-practice.out", "w");
#else
    ifstream in("B-large-practice.in");
    FILE *out = fopen("B-large-practice.out", "w");
#endif
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> H >> N >> M;
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                in >> c[n][m];
            }
        }
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                in >> f[n][m];
            }
        }
        fprintf(out, "Case #%d: %.6f\n", t + 1, dijkstra());
    }
    fclose(out);
    return 0;
}
