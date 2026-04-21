#include <iostream>
using namespace std;

int main() {
    long long L, R;
    
    if (cin >> L >> R) {

        long long odds_till_R = (R + 1) / 2;
        long long odds_till_L = L / 2;
        long long total_odds = odds_till_R - odds_till_L;

        if (total_odds % 2 == 0) {
            cout << "even\n";
        } 
        else {
            cout << "odd\n";
        }
    }

    return 0;
}