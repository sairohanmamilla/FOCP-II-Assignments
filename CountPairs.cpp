#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 10000005; 
int distinct_primes[MAX_N];

void precompute() {
    for (int i = 2; i < MAX_N; i++) {
        if (distinct_primes[i] == 0) { 
            for (int j = i; j < MAX_N; j += i) {
                distinct_primes[j]++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    
    int t;
    if (cin >> t) {
        while (t--) {
            int n;
            cin >> n;
            cout << (1 << distinct_primes[n]) << "\n";
        }
    }
    
    return 0;
}