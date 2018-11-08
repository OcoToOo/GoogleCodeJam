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

int K;
int L;
int S;
string keyboard;
string target;
int total;
int hi;

void dfs(int n, string s) {
    if (n == S) {
        int cnt = 0;
        for (int i = 0; i <= S - L; ++i) {
            bool b = true;
            for (int j = i; j < i + L; ++j) {
                if (s[j] != target[j - i]) {
                    b = false;
                    break;
                }
            }
            if (b) {
                cnt++;
            }
        }
        total += cnt;
        hi = max(hi, cnt);
        return;
    }
    for (int i = 0; i < K; ++i) {
        dfs(n + 1, s + keyboard[i]);
    }
}

double solve() {
    dfs(0, string());
    int sum = 1;
    for (int i = 0; i < S; ++i) {
        sum *= K;
    }
    return (double)hi - (double)total / sum;
}

int main() {
    ifstream in("B-small-practice.in");
    FILE *fout = fopen("B-small-practice.out", "w");
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> K >> L >> S;
        in >> keyboard;
        in >> target;
        total = 0;
        hi = 0;
        fprintf(fout, "Case #%d: %.7f\n", t + 1, solve());
    }
    return 0;
}
