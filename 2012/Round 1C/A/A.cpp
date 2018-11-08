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

vector<int> v[1000];

bool b[1000];

bool solve() {
    for (int n = 0; n < N; ++n) {
        fill(b, b + N, false);
        queue<int> q;
        q.push(n);
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            if (b[p]) {
                return true;
            }
            b[p] = true;
            for (int i = 0; i < v[p].size(); ++i) {
                q.push(v[p][i]);
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
        for (int n = 0; n < N; ++n) {
            int M;
            in >> M;
            v[n].clear();
            for (int m = 0; m < M; ++m) {
                int c;
                in >> c;
                v[n].push_back(c - 1);
            }
        }
        out << "Case #" << t + 1 << ": " << (solve() ? "Yes" : "No") << endl;
    }
    return 0;
}
