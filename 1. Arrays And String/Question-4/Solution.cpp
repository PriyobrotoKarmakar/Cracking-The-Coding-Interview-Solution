#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

/**
 * Maps each character to a number.
 * a -> 0, b -> 1, etc.
 * Non-letter characters map to -1
 */
int getCharNumber(char c) {
    c = tolower(c);
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    }
    return -1;
}

/**
 * Count how many times each character appears.
 */
vector<int> buildCharFrequencyTable(const string& phrase) {
    vector<int> table(26, 0); // a-z
    for (char c : phrase) {
        int x = getCharNumber(c);
        if (x != -1) {
            table[x]++;
        }
    }
    return table;
}

/**
 * Check that no more than one character has an odd count.
 */
bool checkMaxOneOdd(const vector<int>& table) {
    bool foundOdd = false;
    for (int count : table) {
        if (count % 2 == 1) {
            if (foundOdd) {
                return false;
            }
            foundOdd = true;
        }
    }
    return true;
}

/**
 * Solution 1: Using character counting
 * Time Complexity: O(n) where n is the length of the string
 * Space Complexity: O(1) as we use a fixed-size array
 */
bool isPermutationOfPalindrome(const string& phrase) {
    vector<int> table = buildCharFrequencyTable(phrase);
    return checkMaxOneOdd(table);
}

/**
 * Solution 2: Optimized - Check as we go
 * Time Complexity: O(n) where n is the length of the string
 * Space Complexity: O(1) as we use a fixed-size array
 */
bool isPermutationOfPalindromeOptimized(const string& phrase) {
    int countOdd = 0;
    vector<int> table(26, 0); // a-z
    for (char c : phrase) {
        int x = getCharNumber(c);
        if (x != -1) {
            table[x]++;
            if (table[x] % 2 == 1) {
                countOdd++;
            } else {
                countOdd--;
            }
        }
    }
    return countOdd <= 1;
}

/**
 * Toggle the ith bit in the integer
 */
int toggle(int bitVector, int index) {
    if (index < 0) return bitVector;
    
    int mask = 1 << index;
    if ((bitVector & mask) == 0) {
        bitVector |= mask;
    } else {
        bitVector &= ~mask;
    }
    return bitVector;
}

/**
 * Create a bit vector for the string. For each letter, toggle the bit
 */
int createBitVector(const string& phrase) {
    int bitVector = 0;
    for (char c : phrase) {
        int x = getCharNumber(c);
        if (x != -1) {
            bitVector = toggle(bitVector, x);
        }
    }
    return bitVector;
}

/**
 * Check that exactly one bit is set by subtracting one from the integer and ANDing with the original
 */
bool  checkExactlyOneBitSet(int bitVector) {
    return (bitVector & (bitVector - 1)) == 0;
}

/**
 * Solution 3: Using bit vector
 * Time Complexity: O(n) where n is the length of the string
 * Space Complexity: O(1) as we use only a single integer
 */
bool isPermutationOfPalindromeBitVector(const string& phrase) {
    int bitVector = createBitVector(phrase);
    return bitVector == 0 || checkExactlyOneBitSet(bitVector);
}

int main() {
    vector<string> strings = {"Tact Coa", "Race Car", "Was it a cat I saw", "hello", "aab"};
    
    cout << "Using character counting method:" << endl;
    for (const auto& s : strings) {
        cout << s << ": " << (isPermutationOfPalindrome(s) ? "true" : "false") << endl;
    }
    
    cout << "\nUsing optimized method:" << endl;
    for (const auto& s : strings) {
        cout << s << ": " << (isPermutationOfPalindromeOptimized(s) ? "true" : "false") << endl;
    }
    
    cout << "\nUsing bit vector method:" << endl;
    for (const auto& s : strings) {
        cout << s << ": " << (isPermutationOfPalindromeBitVector(s) ? "true" : "false") << endl;
    }
    
    return 0;
}
