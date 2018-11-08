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

int V;
int E;

vector<int> G[1000];
bool done[1000];
int num[1000];

void init() {
    for (int i = 0; i < V; ++i) {
        G[i].clear();
    }
}

int solve(int t) {
    int ret = 0;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            done[j] = false;
            num[j] = 0;
        }
        num[0] = 1;
        queue<pair<int, int>> q;
        q.push(make_pair(i, 0));
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int e = p.first;
            int rank = p.second;
            done[e] = true;
            vector<int> v;
            for (int j = 0; j < G[e].size(); ++j) {
                if (!done[G[e][j]]) {
                    v.push_back(G[e][j]);
                }
            }
            if ((int)v.size() >= 2) {
                for (int j = 0; j < v.size(); ++j) {
                    q.push(make_pair(v[j], rank + 1));
                }
                num[rank + 1] += 2;
            }
        }
        int sum = 0;
        int limit = 1;
        for (int j = 0; j < V; ++j) {
            sum += min(num[j], limit);
            limit = min(num[j], limit) * 2;
        }
        ret = max(ret, sum);
    }
    return V - ret;
}

int main() {
    ifstream in("B-small-practice.in");
    ofstream out("B-small-practice.out");
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> V;
        init();
        for (int n = 0; n < V - 1; ++n) {
            int from, to;
            in >> from;
            in >> to;
            G[--from].push_back(--to);
            G[to].push_back(from);
        }
        int ans = solve(t);
        out << "Case #" << t + 1 << ": " << ans << endl;
    }
    return 0;
}
