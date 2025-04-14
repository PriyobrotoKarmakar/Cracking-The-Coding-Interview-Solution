#!/usr/bin/env python3

def is_substring(s1, s2):
    """
    Utility function to check if one string is a substring of another
    This simulates the isSubstring method that we're asked to assume exists
    """
    return s2 in s1

def is_rotation(s1, s2):
    """
    Solution: Check if s2 is a rotation of s1
    Time Complexity: O(N) where N is the length of the strings (assuming isSubstring runs in O(N) time)
    Space Complexity: O(N) for the concatenated string
    """
    # Check if the strings have the same length and are not empty
    if len(s1) != len(s2) or len(s1) == 0:
        return False
    
    # Concatenate s1 with itself
    s1s1 = s1 + s1
    
    # Check if s2 is a substring of s1s1
    return is_substring(s1s1, s2)

if __name__ == "__main__":
    test_cases = [
        ("waterbottle", "erbottlewat"),  # True - rotation
        ("abcde", "cdeab"),              # True - rotation
        ("abcde", "abcde"),              # True - rotation by 0 positions
        ("abcde", "edcba"),              # False - not a rotation, but reversed
        ("abcde", "abcdef"),             # False - different lengths
        ("", ""),                        # False - empty strings
        ("a", "a")                       # True - single character
    ]
    
    for s1, s2 in test_cases:
        result = is_rotation(s1, s2)
        print(f'Is "{s2}" a rotation of "{s1}"? {"Yes" if result else "No"}')
