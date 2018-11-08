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

int N, K, B, T;

int solve(vector<pair<int, int>>& chickens) {
    int num = 0;
    int cnt = 0;
    for (int n = N - 1; n >= 0; --n) {
        if (chickens[n].first + chickens[n].second * T >= B) {
            cnt += (N - n - 1 - num);
            num++;
        }
        if (num >= K) {
            break;
        }
    }
    if (num < K) {
        return -1;
    }
    return cnt;
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
    int C;
    in >> C;
    for (int c = 0; c < C; ++c) {
        in >> N >> K >> B >> T;
        vector<pair<int, int>> chickens(N);
        vector<int> x(N);
        for (int n = 0; n < N; ++n) {
            in >> x[n];
        }
        vector<int> v(N);
        for (int n = 0; n < N; ++n) {
            in >> v[n];
        }
        for (int n = 0; n < N; ++n) {
            chickens[n] = make_pair(x[n], v[n]);
        }
        int num = solve(chickens);
        out << "Case #" << c + 1 << ": ";
        if (num == -1) {
            out << "IMPOSSIBLE" << endl;
        } else {
            out << num << endl;
        }
    }
    return 0;
}
