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

int A;
int N;

int solve(vector<int>& motes) {
    sort(motes.begin(), motes.end());
    int ret = N;
    int cnt = 0;
    if (A != 1) {
        for (int i = 0; i < N; ++i) {
            if (A > motes[i]) {
                A += motes[i];
            } else {
                while (true) {
                    cnt++;
                    A += A - 1;
                    if (A > motes[i]) {
                        A += motes[i];
                        break;
                    }
                }
            }
            ret = min(ret, cnt + N - (i + 1));
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
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> A >> N;
        vector<int> motes(N);
        for (int n = 0; n < N; ++n) {
            in >> motes[n];
        }
        out << "Case #" << t + 1 << ": " << solve(motes) << endl;
    }
    return 0;
}
