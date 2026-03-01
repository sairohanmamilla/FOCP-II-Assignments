#include <iostream>
using namespace std;
int main() {
    string a, b;
    cout << "Enter two strings: ";
    cin >> a;
    cin >> b;
    int count[26];
    for(int i=0; i<26; i++) {
        count[i] = 0;
    }
    for(int i=0; i<a.length(); i++) { 
        count[a[i]-'a']++;
    }
    for(int i=0; i<b.length(); i++) { 
        count[b[i]-'a']--;
    }
    bool isAnagram = true;
    for(int i=0; i<26; i++) {
        if(count[i]!=0) {
            isAnagram = false;
            break;
        }
    }
    if(isAnagram) {
        cout << "Anagram";
    } else {
        cout << "Not Anagram";
    }
    return 0;
}


//Palindromic Number Pyramid
//Expected Output:
//   11
//  1221
// 123321
// 12344321
/*#include <iostream>
using namespace std;
int main() 
{
    int n=4;
    for(int i = 1; i <= n; i++)
    {
        for(int space = 1; space <= n-i; space++)
        {
            cout << "";
        }
        for(int j = 1; j <= i; j++) 
        {
            cout << j;
        }
        for(int j = i; j >= 1; j--) 
        {
            cout << j;
        }
        cout << n << endl;
    }
}*/
