#!/usr/bin/env python3

def urlify_list(string, true_length):
    """
    Replace spaces with '%20' using character array approach (simulating in-place)
    Time Complexity: O(n)
    Space Complexity: O(n) for the list conversion
    """
    # Convert to list for easier manipulation
    char_list = list(string)
    
    # Count spaces
    space_count = 0
    for i in range(true_length):
        if char_list[i] == ' ':
            space_count += 1
    
    # Calculate new index position
    index = true_length + space_count * 2
    
    # If there is extra space in the array, add null terminator
    if true_length < len(char_list):
        char_list[true_length] = '\0'
    
    # Replace spaces from end to beginning
    for i in range(true_length - 1, -1, -1):
        if char_list[i] == ' ':
            char_list[index - 1] = '0'
            char_list[index - 2] = '2'
            char_list[index - 3] = '%'
            index -= 3
        else:
            char_list[index - 1] = char_list[i]
            index -= 1
    
    # Convert back to string and return
    return ''.join(char_list).replace('\0', '')

def urlify_pythonic(string, true_length):
    """
    Replace spaces with '%20' using Python's built-in methods
    Time Complexity: O(n)
    Space Complexity: O(n) for the new string
    """
    # Trim the string to the true length and replace spaces
    return string[:true_length].replace(' ', '%20')

if __name__ == "__main__":
    # Example with list-based approach
    input_str = "Mr John Smith    "
    true_length = 13  # Length of "Mr John Smith"
    
    print(f'Before: "{input_str}"')
    result1 = urlify_list(input_str, true_length)
    print(f'After (list approach): "{result1}"')
    
    # Example with Pythonic approach
    result2 = urlify_pythonic(input_str, true_length)
    print(f'After (Pythonic approach): "{result2}"')
    
    # Additional test cases
    test_cases = [
        ("much ado about nothing      ", 22),
        ("   hello world  ", 13),
        ("", 0),
        ("  ", 2)
    ]
    
    for test_str, length in test_cases:
        print(f'\nInput: "{test_str}" (true length: {length})')
        print(f'Output: "{urlify_pythonic(test_str, length)}"')
