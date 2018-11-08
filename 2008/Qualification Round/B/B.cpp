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

vector<int> solve(int T, vector<pair<pair<int, int>, int>>& v) {
    vector<int> ret(2, 0);
    sort(v.begin(), v.end());
    int size = v.size();
    vector<bool> done(size, false);
    for (int i = 0; i < size; ++i) {
        if (done[i]) {
            continue;
        }
        done[i] = true;
        int end = v[i].first.second;
        int dir = v[i].second;
        ret[dir]++;
        for (int j = i + 1; j < size; ++j) {
            if (done[j]) {
                continue;
            }
            if (v[j].second == dir) {
                continue;
            }
            if (end + T > v[j].first.first) {
                continue;
            }
            done[j] = true;
            end = v[j].first.second;
            dir = v[j].second;
        }
    }
    return ret;
}

int getTime(string s) {
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
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
    int N;
    in >> N;
    for (int n = 0; n < N; ++n) {
        int T, NA, NB;
        in >> T >> NA >> NB;
        vector<pair<pair<int, int>, int>> v(NA + NB);
        string s;
        for (int i = 0; i < NA; ++i) {
            in >> s;
            int start = getTime(s);
            in >> s;
            int end = getTime(s);
            v[i] = make_pair(make_pair(start, end), 0);
        }
        for (int i = 0; i < NB; ++i) {
            in >> s;
            int start = getTime(s);
            in >> s;
            int end = getTime(s);
            v[NA + i] = make_pair(make_pair(start, end), 1);
        }
        vector<int> answer = solve(T, v);
        out << "Case #" << n + 1 << ": " << answer[0] << " " << answer[1] << endl;
    }
    return 0;
}
