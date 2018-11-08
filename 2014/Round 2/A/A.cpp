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
int X;

int solve(vector<int> S) {
    int ret = 0;
    sort(S.rbegin(), S.rend());
    while (S.size() != 0) {
        ret++;
        int n = S[0];
        S.erase(S.begin());
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] <= X - n) {
                S.erase(S.begin() + i);
                break;
            }
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
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> N >> X;
        vector<int> S(N);
        for (int n = 0; n < N; ++n) {
            in >> S[n];
        }
        out << "Case #" << t + 1 << ": " << solve(S) << endl;
    }
    return 0;
}
