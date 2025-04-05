#!/usr/bin/env python3

def is_permutation_by_sorting(s, t):
    """
    Solution 1: Sort both strings and compare them
    Time Complexity: O(n log n) due to sorting
    Space Complexity: O(n) for creating sorted copies
    """
    # Check if strings have different lengths
    if len(s) != len(t):
        return False
    
    # Sort and compare
    return sorted(s) == sorted(t)

def is_permutation_by_count(s, t):
    """
    Solution 2: Count character occurrences
    Time Complexity: O(n) where n is the length of the strings
    Space Complexity: O(c) where c is the character set size (constant)
    """
    # Check if strings have different lengths
    if len(s) != len(t):
        return False
    
    # Use a dictionary to track character counts
    char_count = {}
    
    # Count occurrences in first string
    for char in s:
        if char in char_count:
            char_count[char] += 1
        else:
            char_count[char] = 1
    
    # Decrement counts for second string
    for char in t:
        if char not in char_count or char_count[char] == 0:
            return False
        char_count[char] -= 1
    
    return True

def is_permutation_by_count_alternate(s, t):
    """
    Solution 3: Use Python's Counter for character counting
    Time Complexity: O(n)
    Space Complexity: O(c) where c is the character set size
    """
    from collections import Counter
    return Counter(s) == Counter(t)

if __name__ == "__main__":
    pairs = [("apple", "papel"), ("carrot", "tarroc"), ("hello", "llloh")]
    
    print("Using sorting method:")
    for word1, word2 in pairs:
        anagram = is_permutation_by_sorting(word1, word2)
        print(f"{word1}, {word2}: {anagram}")
    
    print("\nUsing character count method:")
    for word1, word2 in pairs:
        anagram = is_permutation_by_count(word1, word2)
        print(f"{word1}, {word2}: {anagram}")
    
    print("\nUsing Counter method:")
    for word1, word2 in pairs:
        anagram = is_permutation_by_count_alternate(word1, word2)
        print(f"{word1}, {word2}: {anagram}")
