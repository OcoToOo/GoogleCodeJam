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

int DeceitfulWar(int size, vector<double> naomi, vector<double> ken) {
    sort(naomi.rbegin(), naomi.rend());
    sort(ken.rbegin(), ken.rend());
    int ret = 0;
    for (int i = 0; i < size; ++i) {
        if (ken[i] < naomi[i]) {
            ret++;
        } else {
            double n = naomi[size - 1];
            naomi.insert(naomi.begin() + i, n);
            naomi.erase(naomi.begin() + size);
        }
    }
    return ret;
}

int War(int size, vector<double> naomi, vector<double> ken) {
    sort(naomi.begin(), naomi.end());
    sort(ken.begin(), ken.end());
    int ret = 0;
    for (int i = 0; i < size; ++i) {
        vector<double>::iterator itr = upper_bound(ken.begin(), ken.end(), naomi[i]);
        if (itr == ken.end()) {
            ret++;
        } else {
            ken.erase(itr);
        }
    }
    return ret;
}

//#define LARGE

int main() {
#ifndef LARGE
    ifstream in("D-small-practice.in");
    ofstream out("D-small-practice.out");
#else
    ifstream in("D-large-practice.in");
    ofstream out("D-large-practice.out");
#endif
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        int size;
        in >> size;
        vector<double> naomi(size);
        for (int i = 0; i < size; ++i) {
            in >> naomi[i];
        }
        vector<double> ken(size);
        for (int i = 0; i < size; ++i) {
            in >> ken[i];
        }
        out << "Case #" << t + 1 << ": " << DeceitfulWar(size, naomi, ken) << " " << War(size, naomi, ken) << endl;
    }
    return 0;
}
