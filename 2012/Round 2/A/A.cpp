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
int D;

bool solve(vector<int>& d, vector<int>& l) {
    vector<int> v(N, -1);
    queue<pair<int, int>> q;
    q.push(make_pair(0, d[0]));
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int pos = p.first;
        if (pos == N - 1) {
            return true;
        }
        int len = p.second;
        if (len < v[pos]) {
            continue;
        }
        for (int i = pos + 1; i < N; ++i) {
            if (d[pos] + len >= d[i]) {
                int lenlen = min(d[i] - d[pos], l[i]);
                if (lenlen > v[i]) {
                    q.push(make_pair(i, lenlen));
                    v[i] = lenlen;
                }
            }
        }
    }
    return false;
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
        in >> N;
        vector<int> d(N + 1);
        vector<int> l(N + 1);
        for (int n = 0; n < N; ++n) {
            in >> d[n] >> l[n];
        }
        in >> D;
        d[N] = D;
        l[N] = 0;
        N++;
        out << "Case #" << t + 1 << ": " << (solve(d, l) ? "YES" : "NO") << endl;
    }
    return 0;
}
