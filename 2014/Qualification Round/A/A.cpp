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

vector<int> solve(int a1, int cards1[4][4], int a2, int cards2[4][4]) {
    vector<int> ret;
    map<int, int> m;
    for (int i = 0; i < 4; ++i) {
        m[cards1[a1 - 1][i]]++;
        m[cards2[a2 - 1][i]]++;
    }
    for (map<int, int>::iterator itr = m.begin(); itr != m.end(); ++itr) {
        if (itr->second == 2) {
            ret.push_back(itr->first);
        }
    }
    return ret;
}

int main() {
    ifstream in("A-small-practice.in");
    ofstream out("A-small-practice.out");
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        int a1;
        in >> a1;
        int cards1[4][4];
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                in >> cards1[i][j];
            }
        }
        int a2;
        in >> a2;
        int cards2[4][4];
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                in >> cards2[i][j];
            }
        }
        out << "Case #" << t + 1 << ": ";
        vector<int> ret = solve(a1, cards1, a2, cards2);
        if (ret.size() == 1) {
            out << ret[0];
        } else if (ret.size() >= 2) {
            out << "Bad magician!";
        } else if (ret.size() == 0) {
            out << "Volunteer cheated!";
        }
        out << endl;
    }
    return 0;
}
