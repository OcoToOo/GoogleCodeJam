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

int A;
int B;
int K;

vector<int> v;

int solve() {
    int ret = 0;
    for (int a = 0; a < A; ++a) {
        for (int b = 0; b < B; ++b) {
            int n = a & b;
            if (n < K) {
                ret++;
            }
        }
    }
    return ret;
}

int main() {
    ifstream in("B-small-practice.in");
    ofstream out("B-small-practice.out");
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> A >> B >> K;
        out << "Case #" << t + 1 << ": " << solve() << endl;
    }
    return 0;
}
