#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * Solution 1: Using sorting approach
 * Time Complexity: O(n log n) due to sorting
 * Space Complexity: O(n) for creating sorted copies
 */
bool isPermutationUsingSorting(string s, string t) {
    // Check if strings have different lengths
    if (s.length() != t.length()) {
        return false;
    }
    
    // Sort both strings
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    
    // Compare the sorted strings
    return s == t;
}

/**
 * Solution 2: Using character count
 * Time Complexity: O(n) where n is the length of the strings
 * Space Complexity: O(1) as we use a fixed-size array for character counts
 */
bool isPermutationUsingCharCount(const string& s, const string& t) {
    // Check if strings have different lengths
    if (s.length() != t.length()) {
        return false;
    }
    
    // Create an array to store character counts
    int letters[128] = {0}; // Assumption: ASCII
    
    // Count occurrences in first string
    for (int i = 0; i < s.length(); i++) {
        letters[s[i]]++;
    }
    
    // Decrement counts for second string
    for (int i = 0; i < t.length(); i++) {
        letters[t[i]]--;
        if (letters[t[i]] < 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    vector<pair<string, string>> pairs = {
        {"apple", "papel"}, 
        {"carrot", "tarroc"}, 
        {"hello", "llloh"}
    };
    
    cout << "Using sorting method:" << endl;
    for (const auto& pair : pairs) {
        const string& word1 = pair.first;
        const string& word2 = pair.second;
        bool anagram = isPermutationUsingSorting(word1, word2);
        cout << word1 << ", " << word2 << ": " << (anagram ? "true" : "false") << endl;
    }
    
    cout << "\nUsing character count method:" << endl;
    for (const auto& pair : pairs) {
        const string& word1 = pair.first;
        const string& word2 = pair.second;
        bool anagram = isPermutationUsingCharCount(word1, word2);
        cout << word1 << ", " << word2 << ": " << (anagram ? "true" : "false") << endl;
    }
    
    return 0;
}
