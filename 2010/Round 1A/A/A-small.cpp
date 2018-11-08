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
int K;

char pieces[50][50];
char tmp[50][50];
char tmptmp[50];

bool check(char color) {
    for (int i = 0; i < N; ++i) {
        for (int s = 0; s < N; ++s) {
            if (pieces[i][s] != color) {
                continue;
            }
            int len = 1;
            for (int t = s + 1; t < N; ++t) {
                if (pieces[i][t] == color) {
                    len++;
                    if (len == K) {
                        return true;
                    }
                } else {
                    len = 0;
                    s = t + 1;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int s = 0; s < N; ++s) {
            if (pieces[s][i] != color) {
                continue;
            }
            int len = 1;
            for (int t = s + 1; t < N; ++t) {
                if (pieces[t][i] == color) {
                    len++;
                    if (len == K) {
                        return true;
                    }
                } else {
                    len = 0;
                    s = t + 1;
                    break;
                }
            }
        }
    }
    for (int r = N - 1; r >= 0; --r) {
        int len = 0;
        for (int i = r, j = 0; i >= 0 && j < N; --i, ++j) {
            if (pieces[i][j] == color) {
                len++;
                if (len == K) {
                    return true;
                }
            } else {
                len = 0;
            }
        }
    }
    for (int c = 0; c < N; ++c) {
        int len = 0;
        for (int i = N - 1, j = c; i >= 0 && j < N; --i, ++j) {
            if (pieces[i][j] == color) {
                len++;
                if (len == K) {
                    return true;
                }
            } else {
                len = 0;
            }
        }
    }
    for (int r = 0; r < N; ++r) {
        int len = 0;
        for (int i = r, j = 0; i < N && j < N; ++i, ++j) {
            if (pieces[i][j] == color) {
                len++;
                if (len == K) {
                    return true;
                }
            } else {
                len = 0;
            }
        }
    }
    for (int c = 0; c < N; ++c) {
        int len = 0;
        for (int i = 0, j = c; i < N && j < N; ++i, ++j) {
            if (pieces[i][j] == color) {
                len++;
                if (len == K) {
                    return true;
                }
            } else {
                len = 0;
            }
        }
    }
    return false;
}

void func(int j) {
    for (int i = 0; i < N; ++i) {
        tmptmp[i] = tmp[i][j];
    }

    int a = -1;
    int b = -1;
    for (int i = N - 1; i >= 0; --i) {
        if (a == -1 && tmptmp[i] == '.') {
            a = i;
        }
        if (a != -1 && tmptmp[i] != '.') {
            b = i;
            break;
        }
    }

    if (b == -1) {
        for (int i = 0; i < N; ++i) {
            pieces[i][j] = tmptmp[i];
        }
        return;
    }
    for (int i = N - 1; i >= 0; --i) {
        tmp[i][j] = '.';
        if (i > b) {
            tmp[i][j] = tmptmp[i];
        } else if (i <= b) {
            tmp[i + a - b][j] = tmptmp[i];
            tmp[i][j] = '.';
        }
    }

    return func(j);
}

void rotate() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int newj = N - i - 1;
            int newi = j;
            tmp[newi][newj] = pieces[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            pieces[i][j] = '.';
        }
    }

    for (int j = 0; j < N; ++j) {
        func(j);
    }
}

string solve() {
    bool r = false;
    bool b = false;

    if (check('R')) {
        r = true;
    }

    if (check('B')) {
        b = true;
    }

    if (r && b) {
        return "Both";
    }

    rotate();

    if (!r && check('R')) {
        r = true;
    }

    if (!b && check('B')) {
        b = true;
    }

    if (r && b) {
        return "Both";
    } else if (r) {
        return "Red";
    } else if (b) {
        return "Blue";
    } else {
        return "Neither";
    }
}

int main() {
    ifstream in("A-small-practice.in");
    ofstream out("A-small-practice.out");
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> N >> K;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                in >> pieces[i][j];
            }
        }
        out << "Case #" << t + 1 << ": " << solve().c_str() << endl;
    }
    return 0;
}
