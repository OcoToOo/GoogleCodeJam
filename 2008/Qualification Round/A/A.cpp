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

int solve(int S, vector<string> &v) {
    int size = v.size();
    set<string> s;
    int ret = 0;
    for (int i = 0; i < size; ++i) {
        s.insert(v[i]);
        if (s.size() == S) {
            ret++;
            s.clear();
            s.insert(v[i]);
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
    string s;
    getline(in, s);
    int T = stoi(s, 0);
    for (int t = 0; t < T; ++t) {
        getline(in, s);
        int S = stoi(s, 0);
        for (int i = 0; i < S; ++i) {
            getline(in, s);
        }
        getline(in, s);
        int Q = stoi(s, 0);
        vector<string> v(Q);
        for (int i = 0; i < Q; ++i) {
            getline(in, v[i]);
        }
        out << "Case #" << t + 1 << ": " << solve(S, v) << endl;
    }
    return 0;
}
