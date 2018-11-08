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

int solve(vector<int>& v) {
    int patrick_sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        patrick_sum = patrick_sum ^ v[i];
    }
    if (patrick_sum != 0) {
        return -1;
    }
    sort(v.begin(), v.end());
    return accumulate(v.begin(), v.end(), 0) - v[0];
}

//#define LARGE

int main() {
#ifdef LARGE
    ifstream in("C-large-practice.in");
    ofstream out("C-large-practice.out");
#else
    ifstream in("C-small-practice.in");
    ofstream out("C-small-practice.out");
#endif
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        in >> N;
        vector<int> v(N);
        for (int n = 0; n < N; ++n) {
            in >> v[n];
        }
        out << "Case #" << t + 1 << ": ";
        int answer = solve(v);
        if (answer == -1) {
            out << "NO";
        } else {
            out << answer;
        }
        out << endl;
    }
    return 0;
}
