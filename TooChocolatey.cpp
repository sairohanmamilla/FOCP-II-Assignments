#include <bits/stdc++.h>
using namespace std;

string solve(int n, vector<int> arr) {
    map<int, int, greater<int>> piles;
    
    for (int i = 0; i < n; i++) {
        piles[arr[i]]++;
    }
    
    long long alex_score = 0;
    long long bob_score = 0;
    bool is_alex_turn = true; 
    
    for (auto pair : piles) {
        int pile_size = pair.first;
        int count = pair.second;
        
        int usable_piles = min(2, count); 
        
        for (int i = 0; i < usable_piles; i++) {
            if (is_alex_turn) {
                alex_score += pile_size;
            } else {
                bob_score += pile_size;
            }
            is_alex_turn = !is_alex_turn;
        }
    }

    if (alex_score > bob_score) {
        return "Alex";
    } else {
        return "Bob";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i_arr = 0; i_arr < n; i_arr++)
        {
            cin >> arr[i_arr];
        }

        string out_;
        out_ = solve(n, arr);
        cout << out_;
        cout << "\n";
    }
}