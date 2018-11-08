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

int solve(set<string>& dirs, vector<string>& newdirs) {
    int cnt = 0;
    for (int i = 0; i < newdirs.size(); ++i) {
        string newdir = newdirs[i];
        int pos = 0;
        while (true) {
            pos++;
            pos = newdir.find('/', pos);
            if (pos == string::npos) {
                if (dirs.find(newdir) == dirs.end()) {
                    dirs.insert(newdir);
                    cnt++;
                }
                break;
            }
            string parentdir = newdir.substr(0, pos);
            if (dirs.find(parentdir) == dirs.end()) {
                dirs.insert(parentdir);
                cnt++;
            }
        }
    }
    return cnt;
}

#define LARGE

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
        int N, M;
        in >> N >> M;
        set<string> dirs;
        for (int n = 0; n < N; ++n) {
            string tmp;
            in >> tmp;
            dirs.insert(tmp);
        }
        vector<string> newdirs(M);
        for (int m = 0; m < M; ++m) {
            in >> newdirs[m];
        }
        out << "Case #" << t + 1 << ": " << solve(dirs, newdirs) << endl;
    }
    return 0;
}
