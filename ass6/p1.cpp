#include <iostream>
using namespace std;

void reverseString(char* str) {    
    char* end = str;
    while (*end) { 
        end++;
    }
    end--; 

    while (str < end) {
        char temp = *str;
        *str = *end;
        *end = temp;
        str++;
        end--;
    }
}

int main() {
    char str[] = "hello";
    cout << "Original String: " << str << endl;
    reverseString(str);
    cout << "Reversed String: " << str << endl;
}