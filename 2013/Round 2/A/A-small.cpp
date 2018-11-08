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

int N;
int M;

LL calc(LL n) {
    return n * (2LL * N - n + 1) / 2;
}

LL solve(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> start, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> end) {
    LL cost = 0;
    priority_queue<pair<int, int>> pque;
    while (!end.empty()) {
        pair<int, int> e = end.top();
        end.pop();
        int end_pos = e.first;
        int end_num = e.second;
        while (!start.empty()) {
            pair<int, int> s = start.top();
            if (e.first < s.first) {
                break;
            }
            start.pop();
            pque.push(make_pair(s.first, s.second));
        }
        while (1) {
            pair<int, int> s = pque.top();
            pque.pop();
            int start_pos = s.first;
            int start_num = s.second;
            int num = min(start_num, end_num);
            cost += ((calc(end_pos - start_pos) % 1000002013) * (num % 1000002013));
            cost %= 1000002013;
            if (end_num > start_num) {
                end_num -= start_num;
            } else {
                start_num -= end_num;
                if (start_num) {
                    pque.push(make_pair(start_pos, start_num));
                }
                break;
            }
        }
    }
    return cost;
}

int main() {
    ifstream in("A-small-practice.in");
    ofstream out("A-small-practice.out");
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> N >> M;
        map<pair<int, int>, int> m;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> start;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> end;
        LL cost = 0;
        for (int m = 0; m < M; ++m) {
            int o, e, p;
            in >> o >> e >> p;
            cost += (calc(e - o) % 1000002013 * (p % 1000002013));
            cost %= 1000002013;
            start.push(make_pair(o, p));
            end.push(make_pair(e, p));
        }
        LL ret = solve(start, end);
        LL ans = cost - ret;
        out << "Case #" << t + 1 << ": " << ans << endl;
    }
    return 0;
}
