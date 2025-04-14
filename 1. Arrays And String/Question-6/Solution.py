#!/usr/bin/env python3

def compress_string(string):
    """
    Solution 1: Build compressed string and check length
    Time Complexity: O(n) where n is the length of the string
    Space Complexity: O(n) for the compressed string
    """
    if not string or len(string) <= 1:
        return string
    
    compressed = []
    count_consecutive = 1
    
    for i in range(1, len(string)):
        if string[i] == string[i - 1]:
            count_consecutive += 1
        else:
            compressed.append(string[i - 1] + str(count_consecutive))
            count_consecutive = 1
    
    # Add last character and its count
    compressed.append(string[-1] + str(count_consecutive))
    
    # Join the list to form the compressed string
    compressed_str = ''.join(compressed)
    
    # Return the shorter string
    return compressed_str if len(compressed_str) < len(string) else string

def compress_string_optimized(string):
    """
    Solution 2: Calculate final length first to avoid unnecessary work
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    if not string or len(string) <= 1:
        return string
    
    # Check if compression would create a longer string
    compressed_length = count_compression(string)
    if compressed_length >= len(string):
        return string
    
    compressed = []
    count_consecutive = 1
    
    for i in range(1, len(string)):
        if string[i] == string[i - 1]:
            count_consecutive += 1
        else:
            compressed.append(string[i - 1] + str(count_consecutive))
            count_consecutive = 1
    
    # Add last character and its count
    compressed.append(string[-1] + str(count_consecutive))
    
    return ''.join(compressed)

def count_compression(string):
    """Helper function to count the length of the compressed string"""
    if not string:
        return 0
    
    compressed_length = 0
    count_consecutive = 1
    
    for i in range(1, len(string)):
        if string[i] == string[i - 1]:
            count_consecutive += 1
        else:
            compressed_length += 1 + len(str(count_consecutive))
            count_consecutive = 1
    
    # Add last character and its count
    compressed_length += 1 + len(str(count_consecutive))
    
    return compressed_length

def compress_string_pythonic(string):
    """
    Solution 3: Using a more Pythonic approach with list comprehension
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    if not string or len(string) <= 1:
        return string
    
    # Initialize variables for compression
    result = []
    count = 1
    current_char = string[0]
    
    # Process the string character by character
    for char in string[1:]:
        if char == current_char:
            count += 1
        else:
            result.append(current_char + str(count))
            current_char = char
            count = 1
    
    # Don't forget the last run of characters
    result.append(current_char + str(count))
    compressed = ''.join(result)
    
    return compressed if len(compressed) < len(string) else string

if __name__ == "__main__":
    test_cases = [
        "aabcccccaaa",  # should compress to "a2b1c5a3"
        "abcd",         # should stay "abcd"
        "aabb",         # should stay "aabb" (since "a2b2" is same length)
        "aaa",          # should compress to "a3"
        "a",            # should stay "a"
        ""              # should stay ""
    ]
    
    print("Using basic approach:")
    for test in test_cases:
        print(f'"{test}" -> "{compress_string(test)}"')
    
    print("\nUsing optimized approach:")
    for test in test_cases:
        print(f'"{test}" -> "{compress_string_optimized(test)}"')
    
    print("\nUsing Pythonic approach:")
    for test in test_cases:
        print(f'"{test}" -> "{compress_string_pythonic(test)}"')
