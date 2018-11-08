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
int K;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int solve() {
    int n = N * M;
    int ret = K;
    for (int i = 0; i < (1 << n); ++i) {
        int stone = 0;
        int point = 0;
        bool stones[20][20] = {};
        for (int j = 0; j < n; ++j) {
            if ((i & (1 << j))) {
                stone++;
                stones[j / M][j % M] = true;
                point++;
            }
        }
        bool done[20][20] = {};
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                if (stones[n][m]) {
                    continue;
                }
                if (done[n][m]) {
                    continue;
                }
                if (n == 0 || n == N - 1 || m == 0 || m == M - 1) {
                    continue;
                }
                bool ok = true;
                queue<pair<int, int>> q;
                q.push(make_pair(m, n));
                done[n][m] = true;
                int cnt = 1;
                while (!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();
                    int x = p.first;
                    int y = p.second;
                    for (int i = 0; i < 4; ++i) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
                            continue;
                        }
                        if (done[ny][nx]) {
                            continue;
                        }
                        if (stones[ny][nx]) {
                            continue;
                        }
                        q.push(make_pair(nx, ny));
                        done[ny][nx] = true;
                        if (ny != 0 && ny != N - 1 && nx != 0 && nx != M - 1) {
                            cnt++;
                        } else {
                            ok = false;
                        }
                    }
                }
                if (ok) {
                    point += cnt;
                }
            }
        }
        if (point >= K) {
            ret = min(ret, stone);
        }
    }
    return ret;
}

int main() {
    ifstream in("C-small-practice.in");
    ofstream out("C-small-practice.out");
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> N >> M >> K;
        out << "Case #" << t + 1 << ": " << solve() << endl;
    }
    return 0;
}
