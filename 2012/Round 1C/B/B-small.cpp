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

double D;
int N;
int A;

double d_time[100000];
double d_position[100000];
double d_acceleration[250];

vector<double> solve() {
    vector<double> ret;
    for (int a = 0; a < A; ++a) {
        double t_my = sqrt(2 * D / d_acceleration[a]);
        if (N == 1) {
            ret.push_back(t_my);
        } else if (N == 2) {
            double v_other = (d_position[1] - d_position[0]) / (d_time[1] - d_time[0]);
            double t_other = (D - d_position[1]) / v_other + d_time[1];
            ret.push_back(max(t_my, t_other));
        }
    }
    return ret;
}

int main() {
    ifstream in("B-small-practice.in");
    FILE *out = fopen("B-small-practice.out", "w");
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> D >> N >> A;
        for (int n = 0; n < N; ++n) {
            in >> d_time[n] >> d_position[n];
        }
        for (int a = 0; a < A; ++a) {
            in >> d_acceleration[a];
        }
        fprintf(out, "Case #%d: \n", t + 1);
        vector<double> answer = solve();
        for (int a = 0; a < A; ++a) {
            fprintf(out, "%.6f\n", answer[a]);
        }
    }
    fclose(out);
    return 0;
}
