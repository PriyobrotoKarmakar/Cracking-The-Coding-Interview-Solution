#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Utility function to check if one string is a substring of another
 * This simulates the isSubstring method that we're asked to assume exists
 */
bool isSubstring(const string& s1, const string& s2) {
    return s1.find(s2) != string::npos;
}

/**
 * Solution: Check if s2 is a rotation of s1
 * Time Complexity: O(N) where N is the length of the strings (assuming isSubstring runs in O(N) time)
 * Space Complexity: O(N) for the concatenated string
 */
bool isRotation(const string& s1, const string& s2) {
    // Check if the strings have the same length and are not empty
    if (s1.length() != s2.length() || s1.length() == 0) {
        return false;
    }
    
    // Concatenate s1 with itself
    string s1s1 = s1 + s1;
    
    // Check if s2 is a substring of s1s1
    return isSubstring(s1s1, s2);
}

int main() {
    vector<pair<string, string>> testCases = {
        {"waterbottle", "erbottlewat"},  // True - rotation
        {"abcde", "cdeab"},              // True - rotation
        {"abcde", "abcde"},              // True - rotation by 0 positions
        {"abcde", "edcba"},              // False - not a rotation, but reversed
        {"abcde", "abcdef"},             // False - different lengths
        {"", ""},                        // False - empty strings
        {"a", "a"}                       // True - single character
    };
    
    for (const auto& test : testCases) {
        const string& s1 = test.first;
        const string& s2 = test.second;
        bool result = isRotation(s1, s2);
        
        cout << "Is \"" << s2 << "\" a rotation of \"" << s1 << "\"? " 
             << (result ? "Yes" : "No") << endl;
    }
    
    return 0;
}
