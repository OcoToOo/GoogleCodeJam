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

char c[100][100];

double owp[100];
double oowp[100];

double ooowp[100];

double RPI[100];

void solve() {
    for (int i = 0; i < N; ++i) {
        int win = 0;
        int game = 0;

        for (int j = 0; j < N; ++j) {
            if (i == j) {
                continue;
            }

            if (c[i][j] != '0' && c[i][j] != '1') {
                continue;
            }

            int owin = 0;
            int ogame = 0;

            for (int k = 0; k < N; ++k) {
                if (j == k) {
                    continue;
                }

                if (c[j][k] != '0' && c[j][k] != '1') {
                    continue;
                }

                int oowin = 0;
                int oogame = 0;

                for (int l = 0; l < N; ++l) {
                    if (k == l) {
                        continue;
                    }

                    if (l == j) {
                        continue;
                    }

                    if (c[k][l] != '0' && c[k][l] != '1') {
                        continue;
                    }

                    oogame++;
                    if (c[k][l] == '1') {
                        oowin++;
                    }
                }

                // OOWP
                ooowp[ogame] = (double)oowin / oogame;

                ogame++;

                if (k == i) {
                    continue;
                }

                if (c[j][k] == '1') {
                    owin++;
                }
            }

            // OOWP
            double ooowpsum = 0.0;
            for (int k = 0; k < ogame; ++k) {
                ooowpsum += ooowp[k];
            }
            oowp[game] = ooowpsum / (double)ogame;

            // OWP
            owp[game] = (double)owin / (ogame - 1);

            // WP
            game++;

            if (c[i][j] == '1') {
                win++;
            }
        }

        // OOWP
        double oowpsum = 0.0;
        for (int j = 0; j < game; ++j) {
            oowpsum += oowp[j];
        }
        double OOWP = oowpsum / game;

        // OWP
        double owpsum = 0.0;
        for (int j = 0; j < game; ++j) {
            owpsum += owp[j];
        }
        double OWP = owpsum / game;

        // WP
        double WP = (double)win / game;

        RPI[i] = 0.25 * WP + 0.50 * OWP + 0.25 * OOWP;
    }
}

//#define LARGE

int main() {
#ifndef LARGE
    ifstream in("A-small-practice.in");
    FILE *out = fopen("A-small-practice.out", "w");
#else
    ifstream in("A-large-practice.in");
    FILE *out = fopen("A-large-practice.out", "w");
#endif
    int T;
    in >> T;
    for (int t = 0; t < T; ++t) {
        in >> N;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                in >> c[i][j];
            }
        }
        solve();
        fprintf(out, "Case #%d:\n", t + 1);
        for (int i = 0; i < N; i++) {
            fprintf(out, "%.6f\n", RPI[i]);
        }
    }
    fclose(out);
    return 0;
}
