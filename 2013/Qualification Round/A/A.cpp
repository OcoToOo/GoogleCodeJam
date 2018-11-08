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

string board[4];

string solve() {
    char player[] = {'X', 'O'};
    for (int p = 0; p < 2; ++p) {
        stringstream s;
        s << player[p] << " won";
        for (int j = 0; j < 4; ++j) {
            bool win = true;
            for (int i = 0; i < 4; ++i) {
                if (board[j][i] != player[p] && board[j][i] != 'T') {
                    win = false;
                    break;
                }
            }
            if (win) {
                return s.str();
            }
        }
        for (int i = 0; i < 4; ++i) {
            bool win = true;
            for (int j = 0; j < 4; ++j) {
                if (board[j][i] != player[p] && board[j][i] != 'T') {
                    win = false;
                    break;
                }
            }
            if (win) {
                return s.str();
            }
        }
        bool win = true;
        for (int i = 0, j = 0; i < 4; ++i, ++j) {
            if (board[j][i] != player[p] && board[j][i] != 'T') {
                win = false;
                break;
            }
        }
        if (win) {
            return s.str();
        }
        win = true;
        for (int i = 3, j = 0; i >= 0; i--, ++j) {
            if (board[j][i] != player[p] && board[j][i] != 'T') {
                win = false;
                break;
            }
        }
        if (win) {
            return s.str();
        }
    }
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 4; ++i) {
            if (board[j][i] == '.') {
                return "Game has not completed";
            }
        }
    }
    return "Draw";
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
        for (int i = 0; i < 4; ++i) {
            string s;
            in >> board[i];
        }
        out << "Case #" << t + 1 << ": " << solve().c_str() << endl;
    }
    return 0;
}
