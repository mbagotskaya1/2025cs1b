#include <iostream>
#include <string>
using namespace std; 

string reverseString(const string& str) {
    string result = "";
    for (int i = str.length() - 1; i >= 0; i--) {
        result += str[i];
    }
    return result;
}

int main() {
    string str = "";
    
    cout << "enter string: ";
    getline(cin, str);
    
    cout << reverseString(str) << endl;
    
}