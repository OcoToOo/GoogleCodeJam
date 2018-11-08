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
int M;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char v[50][50];

ifstream in("C-small-practice.in");
ofstream out("C-small-practice.out");

bool solve2(bool swapped) {
    bool ok = false;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (v[r][c] == '*') {
                continue;
            } else if (ok) {
                continue;
            }
            int cnt = 0;
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    int nr = r + i;
                    int nc = c + j;
                    if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
                        continue;
                    }
                    if (v[nr][nc] == '*') {
                        cnt++;
                    }
                }
            }
            if (cnt == 0) {
                v[r][c] = 'c';
                ok = true;
            }
        }
    }

    if (!ok) {
        return false;
    }

    if (swapped) {
        for (int c = 0; c < C; ++c) {
            for (int r = 0; r < R; ++r) {
                out << v[r][c];
            }
            out << endl;
        }
    } else {
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                out << v[r][c];
            }
            out << endl;
        }
    }

    return true;
}

bool solve1(bool swapped) {
    if (R * C - 1 == M) {
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                v[r][c] = '*';
            }
        }
        v[0][0] = 'c';
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                out << v[r][c];
            }
            out << endl;
        }
        return true;
    }

    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            v[r][c] = '.';
        }
    }
    int m = M;
    for (int i = 0, j = 0; i < R;) {
        if (m >= C - j && R - i > 2) {
            for (int k = j; k < C; ++k) {
                v[i][k] = '*';
            }
            m -= C - j;
            i++;
        } else if (m >= R - i && C - j > 2) {
            for (int k = i; k < R; ++k) {
                v[k][j] = '*';
            }
            m -= R - i;
            j++;
            continue;
        } else {
            for (int k = i; k < R - 2; ++k) {
                for (int l = j; l < C - 2; ++l) {
                    if (m > 0) {
                        v[k][l] = '*';
                        m--;
                    }
                }
            }
            break;
        }
    }
    if (m == 0) {
        if (solve2(swapped)) {
            return true;
        }
    }

    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            v[r][c] = '.';
        }
    }
    int d = 0;
    int top = 0;
    int bottom = R - 1;
    int left = 0;
    int right = C - 1;
    m = M;
    while (m) {
        bool ok = false;
        if (d == 0 && m >= right - left + 1) {
            for (int k = left; k <= right; ++k) {
                v[top][k] = '*';
                ok = true;
            }
            m -= right - left + 1;
            top++;
            d++;
        } else if (d == 1 && m >= bottom - top + 1) {
            for (int k = top; k <= bottom; ++k) {
                v[k][right] = '*';
                ok = true;
            }
            m -= bottom - top + 1;
            right--;
            d++;
        } else if (d == 2 && m >= right - left + 1) {
            for (int k = right; k >= left; --k) {
                v[bottom][k] = '*';
                ok = true;
            }
            m -= right - left + 1;
            bottom--;
            d++;
        } else if (d == 3 && m >= bottom - top + 1) {
            for (int k = bottom; k >= top; --k) {
                v[k][left] = '*';
                ok = true;
            }
            m -= bottom - top + 1;
            left++;
            d++;
            d %= 4;
        }

        if (!ok) {
            break;
        }
    }

    if (m == 0) {
        if (solve2(swapped)) {
            return true;
        }
    }

    return false;
}

int main() {
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> R >> C >> M;
        out << "Case #" << t + 1 << ":" << endl;
        if (!solve1(false)) {
            swap(R, C);
            if (!solve1(true)) {
                out << "Impossible" << endl;
            }
        }
    }
    return 0;
}
