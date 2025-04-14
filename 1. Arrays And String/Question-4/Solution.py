#!/usr/bin/env python3
from collections import Counter

def get_char_number(c):
    """Maps each character to a number. a -> 0, b -> 1, etc.
    Non-letter characters map to -1"""
    c = c.lower()
    if ord('a') <= ord(c) <= ord('z'):
        return ord(c) - ord('a')
    return -1

def build_char_frequency_table(phrase):
    """Count how many times each character appears."""
    table = [0] * 26  # a-z
    for c in phrase:
        x = get_char_number(c)
        if x != -1:
            table[x] += 1
    return table

def check_max_one_odd(table):
    """Check that no more than one character has an odd count."""
    found_odd = False
    for count in table:
        if count % 2 == 1:
            if found_odd:
                return False
            found_odd = True
    return True

def is_permutation_of_palindrome(phrase):
    """
    Solution 1: Using character counting
    Time Complexity: O(n) where n is the length of the string
    Space Complexity: O(1) as we use a fixed-size array
    """
    table = build_char_frequency_table(phrase)
    return check_max_one_odd(table)

def is_permutation_of_palindrome_optimized(phrase):
    """
    Solution 2: Optimized - Check as we go
    Time Complexity: O(n) where n is the length of the string
    Space Complexity: O(1) as we use a fixed-size array
    """
    count_odd = 0
    table = [0] * 26  # a-z
    for c in phrase:
        x = get_char_number(c)
        if x != -1:
            table[x] += 1
            if table[x] % 2 == 1:
                count_odd += 1
            else:
                count_odd -= 1
    return count_odd <= 1

def toggle(bit_vector, index):
    """Toggle the ith bit in the integer"""
    if index < 0:
        return bit_vector
    
    mask = 1 << index
    if bit_vector & mask == 0:
        bit_vector |= mask
    else:
        bit_vector &= ~mask
    return bit_vector

def create_bit_vector(phrase):
    """Create a bit vector for the string. For each letter, toggle the bit"""
    bit_vector = 0
    for c in phrase:
        x = get_char_number(c)
        if x != -1:
            bit_vector = toggle(bit_vector, x)
    return bit_vector

def check_exactly_one_bit_set(bit_vector):
    """Check that exactly one bit is set by subtracting one from the integer and ANDing with the original"""
    return bit_vector & (bit_vector - 1) == 0

def is_permutation_of_palindrome_bit_vector(phrase):
    """
    Solution 3: Using bit vector
    Time Complexity: O(n) where n is the length of the string
    Space Complexity: O(1) as we use only a single integer
    """
    bit_vector = create_bit_vector(phrase)
    return bit_vector == 0 or check_exactly_one_bit_set(bit_vector)

def is_permutation_of_palindrome_pythonic(phrase):
    """
    Pythonic solution using Counter
    Time Complexity: O(n)
    Space Complexity: O(k) where k is the number of unique characters
    """
    # Count only letters, ignoring case
    counter = Counter(c.lower() for c in phrase if c.isalpha())
    # Count characters with odd occurrences
    return sum(count % 2 for count in counter.values()) <= 1

if __name__ == "__main__":
    strings = ["Tact Coa", "Race Car", "Was it a cat I saw", "hello", "aab"]
    
    print("Using character counting method:")
    for s in strings:
        print(f"{s}: {is_permutation_of_palindrome(s)}")
    
    print("\nUsing optimized method:")
    for s in strings:
        print(f"{s}: {is_permutation_of_palindrome_optimized(s)}")
    
    print("\nUsing bit vector method:")
    for s in strings:
        print(f"{s}: {is_permutation_of_palindrome_bit_vector(s)}")
    
    print("\nUsing Pythonic method:")
    for s in strings:
        print(f"{s}: {is_permutation_of_palindrome_pythonic(s)}")
