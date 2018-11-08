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

int N, M;

bool solve2(vector<vector<pair<int, int>>>& customers, vector<int>& malted) {
    for (int i = 0; i < M; ++i) {
        bool ok = false;
        for (int j = 0; j < customers[i].size(); ++j) {
            if (customers[i][j].second == malted[customers[i][j].first - 1]) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            return false;
        }
    }
    return true;
}

string solve(vector<vector<pair<int, int>>>& customers) {
    int n = N;
    int lo = n + 1;
    vector<int> answer;
    for (int i = 0; i < (1 << n); ++i) {
        int num = 0;
        vector<int> malted(n);
        for (int j = 0; j < n; ++j) {
            if ((i & (1 << j))) {
                num++;
                malted[j] = 1;
            }
        }
        if (solve2(customers, malted)) {
            if (num < lo) {
                answer = malted;
                lo = num;
            }
        }
    }
    if (lo == n + 1) {
        return "IMPOSSIBLE";
    }
    string ret;
    for (int i = 0; i < n; ++i) {
        ret += '0' + answer[i];
        if (i != n - 1) {
            ret += ' ';
        }
    }
    return ret;
}

int main() {
    ifstream in("B-small-practice.in");
    ofstream out("B-small-practice.out");
    int C;
    in >> C;
    for (int c = 0; c < C; ++c) {
        in >> N >> M;
        vector<vector<pair<int, int>>> customers;
        for (int m = 0; m < M; ++m) {
            int T;
            in >> T;
            vector<pair<int, int>> customer;
            for (int t = 0; t < T; ++t) {
                int flavor;
                in >> flavor;
                int malted;
                in >> malted;
                customer.push_back(make_pair(flavor, malted));
            }
            customers.push_back(customer);
        }
        out << "Case #" << c + 1 << ": " << solve(customers) << endl;
    }
    return 0;
}
