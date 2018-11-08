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

bool isConsonants(char c) {
    return !(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o');
}

bool isConsecutiveConsonants(string sub, int n) {
    for (int start = 0; start < sub.length();) {
        if (isConsonants(sub[start])) {
            int end = start;
            for (; end < sub.length(); end++) {
                if (isConsonants(sub[end])) {
                    if (end - start + 1 >= n) {
                        return true;
                    }
                } else {
                    break;
                }
            }
            start = end + 1;
        } else {
            start++;
        }
    }
    return false;
}

int solve(string name, int n) {
    int cnt = 0;
    for (int start = 0; start < name.size(); ++start) {
        for (int end = start; end < name.size(); ++end) {
            string sub = name.substr(start, end - start + 1);
            if (isConsecutiveConsonants(sub, n)) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ifstream in("A-small-practice.in");
    ofstream out("A-small-practice.out");
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        string name;
        in >> name;
        int n;
        in >> n;
        out << "Case #" << t + 1 << ": " << solve(name, n) << endl;
    }
    return 0;
}
