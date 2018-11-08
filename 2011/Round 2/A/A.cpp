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

int X, S, R, t, N;

double solve(vector<pair<int, pair<int, int>>> v) {
    double ret = 0.0;
    double remain = t;
    for (int i = 0; i < v.size(); ++i) {
        int w = v[i].first;
        int begin = v[i].second.first;
        int end = v[i].second.second;
        double t1 = (double)(end - begin) / (w + R);
        if (remain >= t1) {
            ret += t1;
            remain -= t1;
        } else {
            double d1 = remain * (w + R);
            double d2 = (end - begin) - d1;
            double t2 = d2 / (w + S);
            ret += remain + t2;
            remain = 0;
        }
    }
    return ret;
}

vector<pair<int, pair<int, int>>> init(vector<int>& B, vector<int>& E, vector<int>& w) {
    vector<pair<int, pair<int, int>>> v;
    int pos = 0;
    int index1 = 0;
    int index2 = 0;
    while (1) {
        if (B[index1] > pos) {
            int begin = pos;
            int end = B[index1];
            pos = end;
            B.insert(B.begin() + index1, begin);
            E.insert(E.begin() + index1, end);
            w.insert(w.begin() + index1, 0);
        } else {
            pos = E[index1];
            index2++;
        }
        index1++;
        if (pos == X) {
            break;
        }
        if (index2 >= N) {
            int begin = pos;
            int end = X;
            B.insert(B.begin() + index1, begin);
            E.insert(E.begin() + index1, end);
            w.insert(w.begin() + index1, 0);
            break;
        }
    }
    for (int i = 0; i < B.size(); ++i) {
        v.push_back(make_pair(w[i], make_pair(B[i], E[i])));
    }
    sort(v.begin(), v.end());
    return v;
}

//#define LARGE

int main() {
#ifndef LARGE
    ifstream in("A-small-practice.in");
    FILE* out = fopen("A-small-practice.out", "w");
#else
    ifstream in("A-large-practice.in");
    FILE* out = fopen("A-large-practice.out", "w");
#endif
    int T;
    in >> T;
    for (int c = 0; c < T; ++c) {
        in >> X >> S >> R >> t >> N;
        vector<int> B(N);
        vector<int> E(N);
        vector<int> w(N);
        for (int n = 0; n < N; ++n) {
            in >> B[n] >> E[n] >> w[n];
        }
        vector<pair<int, pair<int, int>>> v = init(B, E, w);
        fprintf(out, "Case #%d: %.7f\n", c + 1, solve(v));
    }
    return 0;
}
