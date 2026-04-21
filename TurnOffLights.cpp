#include <iostream>
#include <string>
using namespace std;

bool isValidReach(int l, int n, int k, const string& bulbs) {
    int operations = 0;
    
    for (int i = 0; i < n; i++) {
        if (bulbs[i] == '1') {
            operations++;
            i = i + (l - 1); 
        }
    }
    return operations <= k;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    string bulbs;
    cin >> bulbs;
    
    int low = 1;
    int high = n;
    int smallest_reach = n;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isValidReach(mid, n, k, bulbs)) {
            smallest_reach = mid;
            high = mid - 1; 
        } else {
            low = mid + 1;
        }
    }
    
    cout << smallest_reach << "\n";
    
    return 0;
}