#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/**
 * Replaces spaces with '%20' in a string
 * Time Complexity: O(n) where n is the length of the string
 * Space Complexity: O(1) as we're modifying the string in-place
 */
void replaceSpaces(char* str, int trueLength) {
    // Count spaces
    int spaceCount = 0;
    for (int i = 0; i < trueLength; i++) {
        if (str[i] == ' ') {
            spaceCount++;
        }
    }
    
    // Calculate new length
    int newLength = trueLength + spaceCount * 2;
    
    // Set null terminator at the end
    str[newLength] = '\0';
    
    // Perform the replacement from end to beginning
    for (int i = trueLength - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[newLength - 1] = '0';
            str[newLength - 2] = '2';
            str[newLength - 3] = '%';
            newLength -= 3;
        } else {
            str[newLength - 1] = str[i];
            newLength--;
        }
    }
}

// C++ string version (more convenient)
string urlify(string s, int trueLength) {
    // Count spaces
    int spaceCount = 0;
    for (int i = 0; i < trueLength; i++) {
        if (s[i] == ' ') {
            spaceCount++;
        }
    }
    
    // Resize string to fit all characters
    int newLength = trueLength + 2 * spaceCount;
    s.resize(newLength);
    
    // Replace spaces from end to beginning
    for (int i = trueLength - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            s[newLength - 1] = '0';
            s[newLength - 2] = '2';
            s[newLength - 3] = '%';
            newLength -= 3;
        } else {
            s[newLength - 1] = s[i];
            newLength--;
        }
    }
    
    return s;
}

int main() {
    // C-style string example
    char str[256] = "Mr John Smith    ";
    int trueLength = 13; // Length of "Mr John Smith"
    
    cout << "Before (C-style): \"" << str << "\"" << endl;
    replaceSpaces(str, trueLength);
    cout << "After (C-style): \"" << str << "\"" << endl;
    
    // C++ string example
    string s = "Mr John Smith";
    cout << "Before (C++ style): \"" << s << "\"" << endl;
    string result = urlify(s, s.length());
    cout << "After (C++ style): \"" << result << "\"" << endl;
    
    return 0;
}
