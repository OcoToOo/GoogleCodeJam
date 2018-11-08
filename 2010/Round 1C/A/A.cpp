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

int solve(int N, vector<int>& A, vector<int>& B) {
    int cnt = 0;
    for (int n = 0; n < N; ++n) {
        for (int m = 0; m < N; ++m) {
            if (n == m) {
                continue;
            }
            if (A[m] < A[n] && B[m] > B[n]) {
                cnt++;
            } else if (A[m] > A[n] && B[m] < B[n]) {
                cnt++;
            }
        }
    }
    return cnt / 2;
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
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        in >> N;
        vector<int> A(N);
        vector<int> B(N);
        for (int n = 0; n < N; ++n) {
            in >> A[n] >> B[n];
        }
        out << "Case #" << t + 1 << ": " << solve(N, A, B) << endl;
    }
    return 0;
}
