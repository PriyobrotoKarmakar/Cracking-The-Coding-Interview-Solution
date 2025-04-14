#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Solution 1: Creating two separate lists and merging them
 * Time Complexity: O(N) where N is the length of the linked list
 * Space Complexity: O(1) as we're just rearranging pointers
 */
ListNode *partition(ListNode *head, int x)
{
    if (!head)
        return nullptr;

    ListNode *beforeStart = nullptr;
    ListNode *beforeEnd = nullptr;
    ListNode *afterStart = nullptr;
    ListNode *afterEnd = nullptr;

    // Partition list
    while (head)
    {
        ListNode *next = head->next;
        head->next = nullptr;

        if (head->val < x)
        {
            // Insert node into end of before list
            if (!beforeStart)
            {
                beforeStart = head;
                beforeEnd = head;
            }
            else
            {
                beforeEnd->next = head;
                beforeEnd = head;
            }
        }
        else
        {
            // Insert node into end of after list
            if (!afterStart)
            {
                afterStart = head;
                afterEnd = head;
            }
            else
            {
                afterEnd->next = head;
                afterEnd = head;
            }
        }

        head = next;
    }

    // If there's no "before" list, return the "after" list
    if (!beforeStart)
    {
        return afterStart;
    }

    // Merge the two lists
    beforeEnd->next = afterStart;

    return beforeStart;
}

/**
 * Solution 2: Using in-place partitioning with two pointers
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
ListNode *partitionInPlace(ListNode *head, int x)
{
    if (!head)
        return nullptr;

    ListNode dummy(0); // Dummy head to simplify code
    dummy.next = head;

    // Find the tail node
    ListNode *tail = head;
    while (tail->next)
    {
        tail = tail->next;
    }

    ListNode *end = tail; // The current end of our processed list

    // Start processing from the head
    ListNode *current = head;
    ListNode *prev = &dummy;

    while (current != end->next)
    {
        ListNode *next = current->next;

        if (current->val >= x)
        {
            // Move to the end of the list
            prev->next = next;
            end->next = current;
            current->next = nullptr;
            end = current;
        }
        else
        {
            // Keep in place
            prev = current;
        }

        current = next;
    }

    return dummy.next;
}

// Helper function to create a linked list from an array
ListNode *createLinkedList(int arr[], int n)
{
    if (n <= 0)
        return nullptr;

    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;

    for (int i = 1; i < n; i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to free memory of a linked list
void deleteLinkedList(ListNode *head)
{
    ListNode *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    // Example from the problem statement
    int arr[] = {3, 5, 8, 5, 10, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    ListNode *list = createLinkedList(arr, n);

    cout << "Original List: ";
    printLinkedList(list);

    int partitionValue = 5;
    cout << "Partition value: " << partitionValue << endl;

    ListNode *partitioned = partition(list, partitionValue);
    cout << "After partitioning (Solution 1): ";
    printLinkedList(partitioned);

    // Test with in-place solution
    int arr2[] = {3, 5, 8, 5, 10, 2, 1};
    ListNode *list2 = createLinkedList(arr2, n);
    ListNode *partitioned2 = partitionInPlace(list2, partitionValue);
    cout << "After partitioning (Solution 2): ";
    printLinkedList(partitioned2);

    // Test edge cases

    // 1. All elements less than partition value
    int arr3[] = {1, 2, 3, 4};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    ListNode *list3 = createLinkedList(arr3, n3);
    cout << "\nAll elements less than partition: ";
    printLinkedList(list3);

    ListNode *partitioned3 = partition(list3, 5);
    cout << "After partitioning: ";
    printLinkedList(partitioned3);

    // 2. All elements greater than or equal to partition value
    int arr4[] = {5, 6, 7, 8};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    ListNode *list4 = createLinkedList(arr4, n4);
    cout << "\nAll elements greater than partition: ";
    printLinkedList(list4);

    ListNode *partitioned4 = partition(list4, 5);
    cout << "After partitioning: ";
    printLinkedList(partitioned4);

    // 3. Empty list
    cout << "\nEmpty list partitioning: ";
    ListNode *partitioned5 = partition(nullptr, 5);
    if (!partitioned5)
    {
        cout << "empty" << endl;
    }
    else
    {
        printLinkedList(partitioned5);
    }

    // Clean up
    deleteLinkedList(partitioned);
    deleteLinkedList(partitioned2);
    deleteLinkedList(partitioned3);
    deleteLinkedList(partitioned4);

    return 0;
}
