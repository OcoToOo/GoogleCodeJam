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

char values[10000][10000];
int signs[10000][10000];

void multiply(char value_a, char value_b, int sign_a, int sign_b, char* p_value_c, int* p_sign_c) {
    int sign_c = sign_a * sign_b;
    char value_c = 0;
    if (value_a == '1') {
        value_c = value_b;
    } else if (value_a == 'i') {
        if (value_b == '1') {
            value_c = value_a;
        } else if (value_b == 'i') {
            value_c = '1';
            sign_c *= -1;
        } else if (value_b == 'j') {
            value_c = 'k';
        } else if (value_b == 'k') {
            value_c = 'j';
            sign_c *= -1;
        } else {
            cout << "assert" << endl;
        }
    } else if (value_a == 'j') {
        if (value_b == '1') {
            value_c = value_a;
        } else if (value_b == 'i') {
            value_c = 'k';
            sign_c *= -1;
        } else if (value_b == 'j') {
            value_c = '1';
            sign_c *= -1;
        } else if (value_b == 'k') {
            value_c = 'i';
        } else {
            cout << "assert" << endl;
        }
    } else if (value_a == 'k') {
        if (value_b == '1') {
            value_c = value_a;
        } else if (value_b == 'i') {
            value_c = 'j';
        } else if (value_b == 'j') {
            value_c = 'i';
            sign_c *= -1;
        } else if (value_b == 'k') {
            value_c = '1';
            sign_c *= -1;
        } else {
            cout << "assert" << endl;
        }
    } else {
        cout << "assert" << endl;
    }
    *p_value_c = value_c;
    *p_sign_c = sign_c;
}

string solve(string s) {
    int size = s.size();
    if (size < 3) {
        return "NO";
    }
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if (j == i) {
                values[i][j] = s[j];
                signs[i][j] = 1;
            } else {
                multiply(values[i][j - 1], s[j], signs[i][j - 1], 1, &values[i][j], &signs[i][j]);
            }
        }
    }
    for (int i = 0; i < size - 2; ++i) {
        if (values[0][i] != 'i' || signs[0][i] != 1) {
            continue;
        }
        for (int j = i + 1; j < size - 1; ++j) {
            if (values[i + 1][j] != 'j' || signs[i + 1][j] != 1) {
                continue;
            }
            if (values[j + 1][size - 1] == 'k' && signs[j + 1][size - 1] == 1) {
                return "YES";
            }
        }
    }
    return "NO";
}

int main() {
    ifstream in("C-small-practice.in");
    ofstream out("C-small-practice.out");
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        int L, X;
        in >> L >> X;
        string s;
        in >> s;
        string ss;
        for (int i = 0; i < X; i++) {
            ss += s;
        }
        out << "Case #" << t + 1 << ": " << solve(ss) << endl;
    }
    return 0;
}
