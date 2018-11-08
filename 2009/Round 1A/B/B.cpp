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

typedef pair<long, PII> PLPII;

#define INF LLONG_MAX

int N, M;
int lights[20][20][3];
LL d[40][40];

LL solve() {
    for (int i = 0; i < 2 * N; ++i) {
        for (int j = 0; j < 2 * M; ++j) {
            d[i][j] = INF;
        }
    }
    priority_queue<PLPII, vector<PLPII>, greater<PLPII>> pque;
    pque.push(make_pair(0, make_pair(0, 2 * N - 1)));
    d[2 * N - 1][0] = 0;
    while (!pque.empty()) {
        PLPII p = pque.top();
        pque.pop();
        LL t = p.first;
        int x = p.second.first;
        int y = p.second.second;
        if (t > d[y][x]) {
            continue;
        }
        int S = lights[y / 2][x / 2][0];
        int W = lights[y / 2][x / 2][1];
        int T = lights[y / 2][x / 2][2];
        // west
        if (x > 0) {
            if (x % 2 == 0) {
                if (d[y][x - 1] > t + 2) {
                    d[y][x - 1] = t + 2;
                    pque.push(make_pair(t + 2, make_pair(x - 1, y)));
                }
            } else {
                if (t >= T) {
                    LL tt = (t - T) % (S + W);
                    if (tt >= S) {
                        if (d[y][x - 1] > t + 1) {
                            d[y][x - 1] = t + 1;
                            pque.push(make_pair(t + 1, make_pair(x - 1, y)));
                        }
                    } else {
                        if (d[y][x - 1] > t + (S - tt) + 1) {
                            d[y][x - 1] = t + (S - tt) + 1;
                            pque.push(make_pair(t + (S - tt) + 1, make_pair(x - 1, y)));
                        }
                    }
                } else {
                    LL tt = T - t;
                    tt = tt % (S + W);
                    if (tt == 0) {
                        if (d[y][x - 1] > t + S + 1) {
                            d[y][x - 1] = t + S + 1;
                            pque.push(make_pair(t + S + 1, make_pair(x - 1, y)));
                        }
                    } else if (tt > 0 && tt <= W) {
                        if (d[y][x - 1] > t + 1) {
                            d[y][x - 1] = t + 1;
                            pque.push(make_pair(t + 1, make_pair(x - 1, y)));
                        }
                    } else {
                        if (d[y][x - 1] > t + tt - W + 1) {
                            d[y][x - 1] = t + tt - W + 1;
                            pque.push(make_pair(t + tt - W + 1, make_pair(x - 1, y)));
                        }
                    }
                }
            }
        }
        // east
        if (x < 2 * M - 1) {
            if (x % 2 != 0) {
                if (d[y][x + 1] > t + 2) {
                    d[y][x + 1] = t + 2;
                    pque.push(make_pair(t + 2, make_pair(x + 1, y)));
                }
            } else {
                if (t >= T) {
                    LL tt = (t - T) % (S + W);
                    if (tt >= S) {
                        if (d[y][x + 1] > t + 1) {
                            d[y][x + 1] = t + 1;
                            pque.push(make_pair(t + 1, make_pair(x + 1, y)));
                        }
                    } else {
                        if (d[y][x + 1] > t + (S - tt) + 1) {
                            d[y][x + 1] = t + (S - tt) + 1;
                            pque.push(make_pair(t + (S - tt) + 1, make_pair(x + 1, y)));
                        }
                    }
                } else {
                    LL tt = T - t;
                    tt = tt % (S + W);
                    if (tt == 0) {
                        if (d[y][x + 1] > t + S + 1) {
                            d[y][x + 1] = t + S + 1;
                            pque.push(make_pair(t + S + 1, make_pair(x + 1, y)));
                        }
                    } else if (tt > 0 && tt <= W) {
                        if (d[y][x + 1] > t + 1) {
                            d[y][x + 1] = t + 1;
                            pque.push(make_pair(t + 1, make_pair(x + 1, y)));
                        }
                    } else {
                        if (d[y][x + 1] > t + tt - W + 1) {
                            d[y][x + 1] = t + tt - W + 1;
                            pque.push(make_pair(t + tt - W + 1, make_pair(x + 1, y)));
                        }
                    }
                }
            }
        }
        // north
        if (y > 0) {
            if (y % 2 == 0) {
                if (d[y - 1][x] > t + 2) {
                    d[y - 1][x] = t + 2;
                    pque.push(make_pair(t + 2, make_pair(x, y - 1)));
                }
            } else {
                if (t >= T) {
                    LL tt = (t - T) % (S + W);
                    if (tt < S) {
                        if (d[y - 1][x] > t + 1) {
                            d[y - 1][x] = t + 1;
                            pque.push(make_pair(t + 1, make_pair(x, y - 1)));
                        }
                    } else {
                        if (d[y - 1][x] > t + S + W - tt + 1) {
                            d[y - 1][x] = t + S + W - tt + 1;
                            pque.push(make_pair(t + S + W - tt + 1, make_pair(x, y - 1)));
                        }
                    }
                } else {
                    LL tt = T - t;
                    tt = tt % (S + W);
                    if (tt == 0 || tt > W) {
                        if (d[y - 1][x] > t + 1) {
                            d[y - 1][x] = t + 1;
                            pque.push(make_pair(t + 1, make_pair(x, y - 1)));
                        }
                    } else {
                        if (d[y - 1][x] > t + tt + 1) {
                            d[y - 1][x] = t + tt + 1;
                            pque.push(make_pair(t + tt + 1, make_pair(x, y - 1)));
                        }
                    }
                }
            }
        }
        // south
        if (y < 2 * N - 1) {
            if (y % 2 != 0) {
                if (d[y + 1][x] > t + 2) {
                    d[y + 1][x] = t + 2;
                    pque.push(make_pair(t + 2, make_pair(x, y + 1)));
                }
            } else {
                if (t >= T) {
                    LL tt = (t - T) % (S + W);
                    if (tt < S) {
                        if (d[y + 1][x] > t + 1) {
                            d[y + 1][x] = t + 1;
                            pque.push(make_pair(t + 1, make_pair(x, y + 1)));
                        }
                    } else {
                        if (d[y + 1][x] > t + S + W - tt + 1) {
                            d[y + 1][x] = t + S + W - tt + 1;
                            pque.push(make_pair(t + S + W - tt + 1, make_pair(x, y + 1)));
                        }
                    }
                } else {
                    LL tt = T - t;
                    tt = tt % (S + W);
                    if (tt == 0 || tt > W) {
                        if (d[y + 1][x] > t + 1) {
                            d[y + 1][x] = t + 1;
                            pque.push(make_pair(t + 1, make_pair(x, y + 1)));
                        }
                    } else {
                        if (d[y + 1][x] > t + tt + 1) {
                            d[y + 1][x] = t + tt + 1;
                            pque.push(make_pair(t + tt + 1, make_pair(x, y + 1)));
                        }
                    }
                }
            }
        }
    }
    return d[0][2 * M - 1];
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
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                in >> lights[n][m][0];
                in >> lights[n][m][1];
                in >> lights[n][m][2];
            }
        }
        out << "Case #" << t + 1 << ": " << solve() << endl;
    }
    return 0;
}
