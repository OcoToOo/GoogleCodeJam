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

LL dfs(int b, int t, vector<pair<int, LL>> box, vector<pair<int, LL>> toy) {
    if (b >= N || t >= M) {
        return 0;
    }
    if (box[b].first == toy[t].first) {
        LL num = min(box[b].second, toy[t].second);
        box[b].second -= num;
        toy[t].second -= num;
        if (box[b].second == 0) {
            b++;
        }
        if (toy[t].second == 0) {
            t++;
        }
        return num + dfs(b, t, box, toy);
    } else {
        LL num = dfs(b + 1, t, box, toy);
        for (; t < M; t++) {
            if (box[b].first == toy[t].first) {
                break;
            }
        }
        return max(num, dfs(b, t, box, toy));
    }
}

int main() {
    ifstream in("C-small-practice.in");
    ofstream out("C-small-practice.out");
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> N >> M;
        vector<pair<int, LL>> box;
        vector<pair<int, LL>> toy;
        for (int n = 0; n < N; ++n) {
            LL a;
            int A;
            in >> a >> A;
            box.push_back(make_pair(A, a));
        }
        for (int m = 0; m < M; ++m) {
            LL b;
            int B;
            in >> b >> B;
            toy.push_back(make_pair(B, b));
        }
        out << "Case #" << t + 1 << ": " << dfs(0, 0, box, toy) << endl;
    }
    return 0;
}
