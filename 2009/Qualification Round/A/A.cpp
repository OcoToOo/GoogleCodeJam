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

int solve(int L, int D, vector<string>& words, vector<int>& mask) {
    int ret = 0;
    for (int i = 0; i < D; ++i) {
        string word = words[i];
        bool ok = true;
        for (int j = 0; j < L; ++j) {
            if ((mask[j] & (1 << (word[j] - 'a'))) == 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ret++;
        }
    }
    return ret;
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
    int L, D, N;
    in >> L >> D >> N;
    vector<string> words(D);
    for (int i = 0; i < D; ++i) {
        in >> words[i];
    }
    for (int i = 0; i < N; ++i) {
        string tokens;
        in >> tokens;
        vector<int> mask(L, 0);
        bool flag = false;
        for (int i = 0, j = 0; i < (int)tokens.size(); ++i) {
            if (tokens[i] == '(') {
                flag = true;
                continue;
            }
            if (tokens[i] == ')') {
                flag = false;
                j++;
                continue;
            }
            mask[j] |= (1 << (tokens[i] - 'a'));
            if (!flag) {
                j++;
            }
        }
        out << "Case #" << i + 1 << ": " << solve(L, D, words, mask) << endl;
    }
    return 0;
}
