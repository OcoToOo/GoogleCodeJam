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

int solve(vector<pair<char, int>> v, vector<int>& obpos, vector<int>& bbpos) {
    int orpos = 1;
    int brpos = 1;
    int seconds = 0;
    vector<int>::iterator oitr = obpos.begin();
    vector<int>::iterator bitr = bbpos.begin();
    for (int n = 0; n < v.size();) {
        seconds++;
        char color = v[n].first;
        int position = v[n].second;
        if (color == 'O') {
            if (orpos < position) {
                orpos++;
            } else if (orpos > position) {
                orpos--;
            } else if (orpos == position) {
                n++;
                oitr++;
            }
            if (bitr != bbpos.end()) {
                if (*bitr > brpos) {
                    brpos++;
                } else if (*bitr < brpos) {
                    brpos--;
                }
            }
        } else if (color == 'B') {
            if (brpos < position) {
                brpos++;
            } else if (brpos > position) {
                brpos--;
            } else if (brpos == position) {
                n++;
                bitr++;
            }
            if (oitr != obpos.end()) {
                if (*oitr > orpos) {
                    orpos++;
                } else if (*oitr < orpos) {
                    orpos--;
                }
            }
        }
    }
    return seconds;
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
        vector<pair<char, int>> v(N);
        vector<int> obpos;
        vector<int> bbpos;
        for (int n = 0; n < N; ++n) {
            char color;
            in >> color;
            int position;
            in >> position;
            v[n] = make_pair(color, position);
            if (color == 'O') {
                obpos.push_back(position);
            } else {
                bbpos.push_back(position);
            }
        }
        out << "Case #" << t + 1 << ": " << solve(v, obpos, bbpos) << endl;
    }
    return 0;
}
