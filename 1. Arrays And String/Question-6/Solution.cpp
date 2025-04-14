#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

/**
 * Solution 1: Naive approach - Build compressed string and check length
 * Time Complexity: O(n) where n is the length of the string
 * Space Complexity: O(n) for the compressed string
 */
string compressString(const string& str) {
    if (str.length() <= 1) {
        return str;
    }
    
    string compressed;
    int countConsecutive = 1;
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == str[i - 1]) {
            countConsecutive++;
        } else {
            compressed += str[i - 1] + to_string(countConsecutive);
            countConsecutive = 1;
        }
    }
    
    // Add last character and its count
    compressed += str[str.length() - 1] + to_string(countConsecutive);
    
    // Return the shorter string
    return compressed.length() < str.length() ? compressed : str;
}

/**
 * Solution 2: Calculate final length first to avoid unnecessary work
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
string compressStringOptimized(const string& str) {
    // Check if compression would save space
    int compressedLength = countCompression(str);
    if (compressedLength >= str.length()) {
        return str;
    }
    
    string compressed;
    compressed.reserve(compressedLength); // Pre-allocate space
    
    int countConsecutive = 1;
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == str[i - 1]) {
            countConsecutive++;
        } else {
            compressed += str[i - 1];
            compressed += to_string(countConsecutive);
            countConsecutive = 1;
        }
    }
    
    // Add last character and its count
    compressed += str[str.length() - 1];
    compressed += to_string(countConsecutive);
    
    return compressed;
}

/**
 * Helper function to count the length of the compressed string
 */
int countCompression(const string& str) {
    if (str.empty()) {
        return 0;
    }
    
    int compressedLength = 0;
    int countConsecutive = 1;
    
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == str[i - 1]) {
            countConsecutive++;
        } else {
            compressedLength += 1 + to_string(countConsecutive).length();
            countConsecutive = 1;
        }
    }
    
    // Add last character and its count
    compressedLength += 1 + to_string(countConsecutive).length();
    
    return compressedLength;
}

/**
 * Solution 3: Using a StringBuilder (stringstream in C++)
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
string compressStringWithStringBuilder(const string& str) {
    if (str.length() <= 1) {
        return str;
    }
    
    stringstream compressed;
    int countConsecutive = 1;
    
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == str[i - 1]) {
            countConsecutive++;
        } else {
            compressed << str[i - 1] << countConsecutive;
            countConsecutive = 1;
        }
    }
    
    // Add last character and its count
    compressed << str[str.length() - 1] << countConsecutive;
    
    string result = compressed.str();
    return result.length() < str.length() ? result : str;
}

int main() {
    vector<string> testCases = {
        "aabcccccaaa",  // should compress to "a2b1c5a3"
        "abcd",         // should stay "abcd"
        "aabb",         // should stay "aabb" (since "a2b2" is same length)
        "aaa",          // should compress to "a3"
        "a",            // should stay "a"
        ""              // should stay ""
    };
    
    cout << "Using naive approach:" << endl;
    for (const auto& test : testCases) {
        cout << "\"" << test << "\" -> \"" << compressString(test) << "\"" << endl;
    }
    
    cout << "\nUsing optimized approach:" << endl;
    for (const auto& test : testCases) {
        cout << "\"" << test << "\" -> \"" << compressStringOptimized(test) << "\"" << endl;
    }
    
    cout << "\nUsing StringBuilder approach:" << endl;
    for (const auto& test : testCases) {
        cout << "\"" << test << "\" -> \"" << compressStringWithStringBuilder(test) << "\"" << endl;
    }
    
    return 0;
}
