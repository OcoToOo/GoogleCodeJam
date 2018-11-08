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

char table[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

string solve(string& input) {
    string output;
    for (int i = 0; i < input.size(); ++i) {
        output.push_back(input[i] == ' ' ? ' ' : table[input[i] - 'a']);
    }
    return output;
}

int main() {
    ifstream in("A-small-practice.in");
    ofstream out("A-small-practice.out");
    int T;
    in >> T;
    string input;
    getline(in, input);
    for (int t = 0; t < T; ++t) {
        getline(in, input);
        out << "Case #" << t + 1 << ": " << solve(input).c_str() << endl;
    }
    return 0;
}
