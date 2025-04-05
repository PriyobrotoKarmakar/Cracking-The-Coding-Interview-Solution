#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Solution 1: Using a boolean array to track character occurrences.
 * Time Complexity: O(n) where n is the length of the string
 * Space Complexity: O(1) as we use a fixed-size array of 128 characters
 */
bool isUniqueCharsUsingArray(const string& str) {
    // Early return if string length exceeds ASCII character set size
    if (str.length() > 128) {
        return false;
    }
    
    // Create a boolean array to track seen characters
    bool char_set[128] = {false};
    
    for (int i = 0; i < str.length(); i++) {
        int val = str[i]; // Get ASCII value
        // If character already seen, return false
        if (char_set[val]) {
            return false;
        }
        // Mark character as seen
        char_set[val] = true;
    }
    
    return true;
}

/**
 * Solution 2: Using bit manipulation (assumes only lowercase a-z characters).
 * Time Complexity: O(n) where n is the length of the string
 * Space Complexity: O(1) as we use only a single integer
 */
bool isUniqueCharsUsingBitVector(const string& str) {
    // Early return if string length exceeds lowercase alphabet size
    if (str.length() > 26) {
        return false;
    }
    
    int checker = 0; // Bit vector to store character occurrences
    
    for (int i = 0; i < str.length(); i++) {
        int val = str[i] - 'a'; // Convert to 0-25 range for lowercase letters
        
        // Check if bit corresponding to this character is already set
        if ((checker & (1 << val)) > 0) {
            return false;
        }
        
        // Set the bit for this character
        checker |= (1 << val);
    }
    
    return true;
}

/**
 * Solution 3: Brute force approach without additional data structures
 * Time Complexity: O(n²) where n is the length of the string
 * Space Complexity: O(1) as we use no additional data structures
 */
bool isUniqueCharsWithoutDataStructure(const string& str) {
    // Compare each character with every other character
    for (int i = 0; i < str.length(); i++) {
        for (int j = i + 1; j < str.length(); j++) {
            if (str[i] == str[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};
    
    cout << "Using array method:" << endl;
    for (const auto& word : words) {
        cout << word << ": " << (isUniqueCharsUsingArray(word) ? "true" : "false") << endl;
    }
    
    cout << "\nUsing bit vector method (only works for lowercase a-z):" << endl;
    for (const auto& word : words) {
        cout << word << ": " << (isUniqueCharsUsingBitVector(word) ? "true" : "false") << endl;
    }
    
    cout << "\nUsing brute force method without data structure:" << endl;
    for (const auto& word : words) {
        cout << word << ": " << (isUniqueCharsWithoutDataStructure(word) ? "true" : "false") << endl;
    }
    
    return 0;
}