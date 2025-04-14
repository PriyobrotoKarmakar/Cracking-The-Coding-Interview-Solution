#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

/**
 * Solution: Check if two strings are one edit (or zero edits) away
 * Time Complexity: O(n) where n is the length of the shorter string
 * Space Complexity: O(1) - no extra data structures used
 */
bool oneEditAway(const string& first, const string& second) {
    // If the strings have more than one character length difference, they can't be one edit away
    if (abs(int(first.length() - second.length())) > 1) {
        return false;
    }
    
    // Get shorter and longer string
    const string& s1 = first.length() <= second.length() ? first : second;
    const string& s2 = first.length() <= second.length() ? second : first;
    
    int index1 = 0; // Index for shorter string
    int index2 = 0; // Index for longer string
    bool foundDifference = false;
    
    while (index1 < s1.length() && index2 < s2.length()) {
        if (s1[index1] != s2[index2]) {
            // If this is the second difference, return false
            if (foundDifference) {
                return false;
            }
            foundDifference = true;
            
            // If strings are same length, we're replacing a character
            // Move shorter string pointer only if strings are same length
            if (s1.length() == s2.length()) {
                index1++;
            }
        } else {
            // If characters match, move shorter string pointer
            index1++;
        }
        // Always move longer string pointer
        index2++;
    }
    
    return true;
}

/**
 * Alternative solution with separate functions for each edit type
 */
bool oneEditReplace(const string& s1, const string& s2) {
    bool foundDifference = false;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            if (foundDifference) {
                return false;
            }
            foundDifference = true;
        }
    }
    return true;
}

bool oneEditInsert(const string& s1, const string& s2) {
    // s1 is shorter, s2 is longer
    int index1 = 0;
    int index2 = 0;
    while (index1 < s1.length() && index2 < s2.length()) {
        if (s1[index1] != s2[index2]) {
            if (index1 != index2) {
                return false;
            }
            index2++;
        } else {
            index1++;
            index2++;
        }
    }
    return true;
}

bool oneEditAwayAlternative(const string& first, const string& second) {
    if (first.length() == second.length()) {
        return oneEditReplace(first, second);
    } else if (first.length() + 1 == second.length()) {
        return oneEditInsert(first, second);
    } else if (first.length() == second.length() + 1) {
        return oneEditInsert(second, first);
    }
    return false;
}

int main() {
    vector<pair<string, string>> testCases = {
        {"pale", "ple"},     // true - remove 'a'
        {"pales", "pale"},   // true - insert 's'
        {"pale", "bale"},    // true - replace 'p' with 'b'
        {"pale", "bake"},    // false - replace 'p' and 'l'
        {"", ""},            // true - no edits
        {"", "a"},           // true - insert 'a'
        {"abc", "abcd"},     // true - insert 'd'
        {"abc", "abx"},      // true - replace 'c' with 'x'
        {"abc", "xyz"}       // false - multiple changes
    };
    
    cout << "Using combined approach:" << endl;
    for (const auto& test : testCases) {
        cout << test.first << ", " << test.second << ": " 
             << (oneEditAway(test.first, test.second) ? "true" : "false") << endl;
    }
    
    cout << "\nUsing separate functions approach:" << endl;
    for (const auto& test : testCases) {
        cout << test.first << ", " << test.second << ": " 
             << (oneEditAwayAlternative(test.first, test.second) ? "true" : "false") << endl;
    }
    
    return 0;
}
