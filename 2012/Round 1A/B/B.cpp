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

int star[1000][2];

int solve() {
    vector<int> level(N, 0);
    int cnt = 0;
    int num = 0;
    while (true) {
        bool is = false;
        // 0 -> 2
        for (int i = 0; i < N; ++i) {
            if (level[i] == 0) {
                if (num >= star[i][1]) {
                    level[i] = 2;
                    num += 2;
                    cnt++;
                    is = true;
                    break;
                }
            }
        }
        if (is) {
            continue;
        }
        // 1 -> 2
        for (int i = 0; i < N; ++i) {
            if (level[i] == 1) {
                if (num >= star[i][1]) {
                    level[i] = 2;
                    num += 1;
                    cnt++;
                    is = true;
                    break;
                }
            }
        }
        if (is) {
            continue;
        }
        // 0 -> 1
        priority_queue<pair<int, int>> q;
        int index = -1;
        int max = -1;
        for (int i = 0; i < N; ++i) {
            if (level[i] == 0) {
                if (num >= star[i][0]) {
                    q.push(make_pair(star[i][1], i));
                }
            }
        }
        if (q.empty()) {
            break;
        }
        pair<int, int> p = q.top();
        q.pop();
        level[p.second] = 1;
        num += 1;
        cnt++;
    }
    if (count(level.begin(), level.end(), 2) != N) {
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
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> N;
        for (int n = 0; n < N; ++n) {
            in >> star[n][0] >> star[n][1];
        }
        out << "Case #" << t + 1 << ": ";
        int cnt = solve();
        if (cnt == -1) {
            out << "Too Bad";
        } else {
            out << cnt;
        }
        out << endl;
    }
    return 0;
}
