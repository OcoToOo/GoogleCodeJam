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

void combine(vector<vector<char>>& combines, vector<char>& v) {
    while (true) {
        if (v.size() < 2) {
            return;
        }
        bool combined = false;
        for (int c = 0; c < combines.size(); ++c) {
            vector<char> elements = combines[c];
            for (int i = 0; i <= 1; i++) {
                if (v[v.size() - 2] == elements[i] && v[v.size() - 1] == elements[!i]) {
                    v.erase(v.end() - 2, v.end());
                    v.push_back(elements[2]);
                    combined = true;
                    break;
                }
            }
            if (combined) {
                break;
            }
        }
        if (!combined) {
            break;
        }
    }
}

void ooposed(vector<vector<char>>& opposeds, vector<char>& v) {
    if (v.size() < 2) {
        return;
    }
    for (int d = 0; d < opposeds.size(); ++d) {
        vector<char> elements = opposeds[d];
        for (int i = 0; i <= 1; i++) {
            if (v[v.size() - 1] == elements[i]) {
                for (int j = 0; j < v.size() - 1; ++j) {
                    if (v[j] == elements[!i]) {
                        v.clear();
                        return;
                    }
                }
            }
        }
    }
}

vector<char> solve(vector<vector<char>>& combines, vector<vector<char>>& opposeds, vector<char>& characters) {
    vector<char> v;
    for (int n = 0; n < characters.size(); ++n) {
        v.push_back(characters[n]);
        combine(combines, v);
        ooposed(opposeds, v);
    }
    return v;
}

//#define LARGE

int main() {
#ifdef LARGE
    ifstream in("B-large-practice.in");
    ofstream out("B-large-practice.out");
#else
    ifstream in("B-small-practice.in");
    ofstream out("B-small-practice.out");
#endif
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        int C;
        in >> C;
        vector<vector<char>> combines(C, vector<char>(3));
        for (int c = 0; c < C; ++c) {
            for (int i = 0; i < 3; ++i) {
                in >> combines[c][i];
            }
        }
        int D;
        in >> D;
        vector<vector<char>> opposeds(D, vector<char>(2));
        for (int d = 0; d < D; ++d) {
            for (int i = 0; i < 2; ++i) {
                in >> opposeds[d][i];
            }
        }
        int N;
        in >> N;
        vector<char> characters(N);
        for (int n = 0; n < N; ++n) {
            in >> characters[n];
        }
        vector<char> after = solve(combines, opposeds, characters);
        out << "Case #" << t + 1 << ": [";
        int size = after.size();
        for (int i = 0; i < size; ++i) {
            out << after[i];
            if (i != size - 1) {
                out << ", ";
            }
        }
        out << "]" << endl;
    }
    return 0;
}
