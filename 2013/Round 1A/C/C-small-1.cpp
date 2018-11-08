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

int R;
int N;
int M;
int K;

set<int> getProducts(vector<int>& n) {
    set<int> s;
    for (int i = 0; i < (1 << n.size()); ++i) {
        int p = 1;
        for (int j = 0; j < n.size(); ++j) {
            if ((i & (1 << j))) {
                p *= n[j];
            }
        }
        s.insert(p);
    }
    return s;
}

vector<int> solve(vector<int>& p) {
    vector<int> ret(N, 2);
    for (int i = 2; i <= M; ++i) {
        for (int j = i; j <= M; ++j) {
            for (int k = j; k <= M; ++k) {
                vector<int> n;
                n.push_back(i);
                n.push_back(j);
                n.push_back(k);
                set<int> s = getProducts(n);
                bool b = true;
                for (int l = 0; l < p.size(); ++l) {
                    if (s.find(p[l]) == s.end()) {
                        b = false;
                        break;
                    }
                }
                if (b) {
                    ret = n;
                }
            }
        }
    }
    return ret;
}

int main() {
    ifstream in("C-small-practice-1.in");
    ofstream out("C-small-practice-1.out");
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        out << "Case #" << t + 1 << ":" << endl;
        in >> R >> N >> M >> K;
        for (int r = 0; r < R; ++r) {
            vector<int> p(K);
            for (int k = 0; k < K; ++k) {
                in >> p[k];
            }
            vector<int> ret = solve(p);
            for (int n = 0; n < ret.size(); ++n) {
                out << ret[n];
            }
            out << endl;
        }
    }
    return 0;
}
