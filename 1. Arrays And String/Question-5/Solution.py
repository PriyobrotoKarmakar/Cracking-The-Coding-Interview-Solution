#!/usr/bin/env python3

def one_edit_away(first, second):
    """
    Solution: Check if two strings are one edit (or zero edits) away
    Time Complexity: O(n) where n is the length of the shorter string
    Space Complexity: O(1) - no extra data structures used
    """
    # If lengths differ by more than 1, return False
    if abs(len(first) - len(second)) > 1:
        return False
    
    # Get shorter and longer string
    s1, s2 = (first, second) if len(first) <= len(second) else (second, first)
    
    index1 = 0  # Index for shorter string
    index2 = 0  # Index for longer string
    found_difference = False
    
    while index1 < len(s1) and index2 < len(s2):
        if s1[index1] != s2[index2]:
            # If this is the second difference, return False
            if found_difference:
                return False
            found_difference = True
            
            # If strings are same length, we're replacing a character
            # Move shorter string pointer only if strings are same length
            if len(s1) == len(s2):
                index1 += 1
        else:
            # If characters match, move shorter string pointer
            index1 += 1
        
        # Always move longer string pointer
        index2 += 1
    
    return True

def one_edit_replace(s1, s2):
    """Check if strings are one character replacement away"""
    found_difference = False
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            if found_difference:
                return False
            found_difference = True
    return True

def one_edit_insert(s1, s2):
    """Check if strings are one character insertion away (s1 is shorter)"""
    index1 = 0
    index2 = 0
    while index1 < len(s1) and index2 < len(s2):
        if s1[index1] != s2[index2]:
            if index1 != index2:
                return False
            index2 += 1
        else:
            index1 += 1
            index2 += 1
    return True

def one_edit_away_alternative(first, second):
    """Alternative solution with separate functions for each edit type"""
    if len(first) == len(second):
        return one_edit_replace(first, second)
    elif len(first) + 1 == len(second):
        return one_edit_insert(first, second)
    elif len(first) == len(second) + 1:
        return one_edit_insert(second, first)
    return False

if __name__ == "__main__":
    test_cases = [
        ("pale", "ple"),     # True - remove 'a'
        ("pales", "pale"),   # True - insert 's'
        ("pale", "bale"),    # True - replace 'p' with 'b'
        ("pale", "bake"),    # False - replace 'p' and 'l'
        ("", ""),            # True - no edits
        ("", "a"),           # True - insert 'a'
        ("abc", "abcd"),     # True - insert 'd'
        ("abc", "abx"),      # True - replace 'c' with 'x'
        ("abc", "xyz")       # False - multiple changes
    ]
    
    print("Using combined approach:")
    for first, second in test_cases:
        print(f"{first}, {second}: {one_edit_away(first, second)}")
    
    print("\nUsing separate functions approach:")
    for first, second in test_cases:
        print(f"{first}, {second}: {one_edit_away_alternative(first, second)}")
