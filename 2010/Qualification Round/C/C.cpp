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

LL solve(int R, int k, int N, vector<int>& g) {
    vector<pair<int, int>> v(N);
    for (int n = 0; n < N; ++n) {
        int i = n;
        int num = 0;
        int sum = 0;
        int next = 0;
        for (;;) {
            if (sum + g[i] > k) {
                break;
            }
            sum += g[i];
            i++;
            if (i >= N) {
                i = 0;
            }
            next = i;
            num++;
            if (num >= N) {
                break;
            }
        }
        v[n] = make_pair(next, sum);
    }
    LL ret = 0;
    int now = 0;
    for (int r = 0; r < R; ++r) {
        ret += v[now].second;
        now = v[now].first;
    }
    return ret;
}

//#define LARGE

int main() {
#ifndef LARGE
    ifstream in("C-small-practice.in");
    ofstream out("C-small-practice.out");
#else
    ifstream in("C-large-practice.in");
    ofstream out("C-large-practice.out");
#endif
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        int R, k, N;
        in >> R >> k >> N;
        vector<int> g(N);
        for (int n = 0; n < N; ++n) {
            in >> g[n];
        }
        out << "Case #" << t + 1 << ": " << solve(R, k, N, g) << endl;
    }
    return 0;
}
