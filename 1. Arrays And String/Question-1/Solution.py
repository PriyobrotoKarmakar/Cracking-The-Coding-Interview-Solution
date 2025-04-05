#!/usr/bin/env python3

def is_unique_chars_using_array(string):
    """
    Solution 1: Using a set or dictionary to track character occurrences.
    Time Complexity: O(n) where n is the length of the string
    Space Complexity: O(c) where c is the size of the character set (at most 128 for ASCII)
    """
    # Early return if string length exceeds ASCII character set size
    if len(string) > 128:
        return False
    
    # Create a set to track seen characters
    char_set = set()
    
    for char in string:
        # If character already seen, return False
        if char in char_set:
            return False
        # Add character to set
        char_set.add(char)
    
    return True


def is_unique_chars_using_bit_vector(string):
    """
    Solution 2: Using bit manipulation (assumes only lowercase a-z characters).
    Time Complexity: O(n) where n is the length of the string
    Space Complexity: O(1) as we use only a single integer
    """
    # Early return if string length exceeds lowercase alphabet size
    if len(string) > 26:
        return False
    
    checker = 0  # Bit vector to store character occurrences
    
    for char in string:
        # Convert character to 0-25 range for lowercase letters
        val = ord(char) - ord('a')
        
        # Check if bit corresponding to this character is already set
        if (checker & (1 << val)) > 0:
            return False
        
        # Set the bit for this character
        checker |= (1 << val)
    
    return True


def is_unique_chars_without_data_structure(string):
    """
    Solution 3: Brute force approach without additional data structures
    Time Complexity: O(n²) where n is the length of the string
    Space Complexity: O(1) as we use no additional data structures
    """
    # Compare each character with every other character
    for i in range(len(string)):
        for j in range(i + 1, len(string)):
            if string[i] == string[j]:
                return False
    return True


def is_unique_chars_using_sort(string):
    """
    Solution 4: Sort the string first, then check adjacent characters
    Time Complexity: O(n log n) due to sorting
    Space Complexity: O(n) if sorting creates a copy, O(1) if sorting in place
    """
    # Convert to sorted list (this creates a new list in Python)
    sorted_chars = sorted(string)
    
    # Check adjacent characters for duplicates
    for i in range(1, len(sorted_chars)):
        if sorted_chars[i] == sorted_chars[i - 1]:
            return False
    
    return True


if __name__ == "__main__":
    words = ["abcde", "hello", "apple", "kite", "padle"]
    
    print("Using array/set method:")
    for word in words:
        print(f"{word}: {is_unique_chars_using_array(word)}")
    
    print("\nUsing bit vector method (only works for lowercase a-z):")
    for word in words:
        print(f"{word}: {is_unique_chars_using_bit_vector(word)}")
    
    print("\nUsing brute force method without data structure:")
    for word in words:
        print(f"{word}: {is_unique_chars_without_data_structure(word)}")
    
    print("\nUsing sort method:")
    for word in words:
        print(f"{word}: {is_unique_chars_using_sort(word)}")