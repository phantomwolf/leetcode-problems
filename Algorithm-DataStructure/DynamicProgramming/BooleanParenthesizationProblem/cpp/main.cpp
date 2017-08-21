#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


int count_parenth(const string &symbols, const string &operators)
{
    int n = symbols.size();
    int T[n][n], F[n][n];
    for (int i = 0; i < n; ++i) {
        F[i][i] = (symbols[i] == 'F') ? 1 : 0;
        T[i][i] = (symbols[i] == 'T') ? 1 : 0;
    }

    for (int gap = 1; gap < n; ++gap) {
        for (int i = 0, j = gap; j < n; ++i, ++j) {
            F[i][j] = T[i][j] = 0;
            // Divide the sequence to 2 parts
            for (int p = i; p < j; ++p) {
                // total[i][p] & total[p + 1][j]
                int total_left  = T[i][p] + F[i][p];
                int total_right = T[p + 1][j] + F[p + 1][j];
                
                switch (operators[p]) {
                case '&':
                    T[i][j] += T[i][p] * T[p + 1][j];
                    F[i][j] += total_left * total_right - T[i][p] * T[p + 1][j];
                    break;
                case '|':
                    T[i][j] += total_left * total_right - F[i][p] * F[p + 1][j];
                    F[i][j] += F[i][p] * F[p + 1][j];
                    break;
                case '^':
                    T[i][j] += T[i][p] * F[p + 1][j] + F[i][p] * T[p + 1][j];
                    F[i][j] += T[i][p] * T[p + 1][j] + F[i][p] * F[p + 1][j];
                    break;
                default:
                    cout << "Invalid operator: " << operators[p] << endl;
                    exit(255);
                }
            }
        }
    }
    return T[0][n - 1];
}


int main()
{
    string symbols("TTFT");
    string operators("|&^");

    int res = count_parenth(symbols, operators);
    cout << "result: " << res << endl;

    return 0;
}
