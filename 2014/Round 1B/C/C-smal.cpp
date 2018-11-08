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
int M;

bool edge[8][8];
int back[8];

string solve(vector<int>& zip) {
    string ret;
    vector<int> v;
    for (int i = 0; i < N; ++i) {
        v.push_back(i);
    }
    do {
        for (int i = 0; i < N; ++i) {
            back[i] = -1;
        }
        int city = v[0];
        bool ok = true;
        for (int i = 1; i < N;) {
            int next = v[i];
            if (edge[city][next]) {
                back[next] = city;
                city = next;
                i++;
            } else if (back[city] != -1) {
                city = back[city];
                continue;
            } else {
                ok = false;
                break;
            }
        }
        if (ok) {
            stringstream s;
            for (int i = 0; i < N; ++i) {
                s << zip[v[i]];
            }
            string val = s.str();
            if (ret.size() == 0) {
                ret = val;
            } else {
                if (val < ret) {
                    ret = val;
                }
            }
        }
    } while (next_permutation(v.begin(), v.end()));
    return ret;
}

int main() {
    ifstream in("C-small-practice.in");
    ofstream out("C-small-practice.out");
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> N >> M;
        vector<int> zip(N);
        for (int n = 0; n < N; ++n) {
            in >> zip[n];
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                edge[i][j] = false;
            }
        }
        for (int m = 0; m < M; ++m) {
            int from, to;
            in >> from >> to;
            from--;
            to--;
            edge[from][to] = true;
            edge[to][from] = true;
        }
        out << "Case #" << t + 1 << ": " << solve(zip) << endl;
    }
    return 0;
}
