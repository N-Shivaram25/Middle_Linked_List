#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// External function declarations (defined in solution.c)
extern struct ListNode* middleNode(struct ListNode* head);
extern struct ListNode* buildList(int* arr, int size);
extern void printList(struct ListNode* head);
extern void freeList(struct ListNode* head);

// Helper function to check if two lists are identical
bool areListsEqual(struct ListNode* list1, struct ListNode* list2) {
    while (list1 != NULL && list2 != NULL) {
        if (list1->val != list2->val) return false;
        list1 = list1->next;
        list2 = list2->next;
    }
    return (list1 == NULL && list2 == NULL);
}

// Helper function to get the middle node using the naive way (for verification)
struct ListNode* getMiddleNodeReference(struct ListNode* head) {
    // If the list is empty
    if (head == NULL) return NULL;
    
    // Count the number of nodes
    int count = 0;
    struct ListNode* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    // Find the middle node (floor division for even lengths)
    int middleIndex = count / 2;
    current = head;
    for (int i = 0; i < middleIndex; i++) {
        current = current->next;
    }
    
    return current;
}

// Function to run a test case
bool runTest(int* arr, int size, const char* testName) {
    // Create list from array
    struct ListNode* head = buildList(arr, size);
    
    // Get the expected result
    struct ListNode* expected = getMiddleNodeReference(head);
    
    // Get the result from the solution
    struct ListNode* result = middleNode(head);
    
    // Check if they match
    bool passed = (result == expected);
    
    // Print test results with colored output
    printf("Test Case %s: ", testName);
    if (passed) {
        printf("✅ PASSED\n");
        printf("  Expected and actual middle nodes match at value: %d\n", result->val);
    } else {
        printf("❌ FAILED\n");
        printf("  Expected middle at value: %d, got: %d\n", expected->val, result->val);
    }
    
    // Clean up
    freeList(head);
    
    return passed;
}

int main() {
    printf("Running tests for middleNode function...\n\n");
    
    int testsPassed = 0;
    int totalTests = 5;
    
    // Test Case 1: Odd number of nodes
    int arr1[] = {1, 2, 3, 4, 5};
    if (runTest(arr1, 5, "1 (Odd length list)")) testsPassed++;
    
    // Test Case 2: Even number of nodes
    int arr2[] = {1, 2, 3, 4, 5, 6};
    if (runTest(arr2, 6, "2 (Even length list)")) testsPassed++;
    
    // Test Case 3: Single node
    int arr3[] = {42};
    if (runTest(arr3, 1, "3 (Single node)")) testsPassed++;
    
    // Test Case 4: Two nodes
    int arr4[] = {10, 20};
    if (runTest(arr4, 2, "4 (Two nodes)")) testsPassed++;
    
    // Test Case 5: 10 nodes
    int arr5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    if (runTest(arr5, 10, "5 (10 nodes)")) testsPassed++;
    
    // Summary
    printf("\nTest Summary: %d/%d tests passed\n", testsPassed, totalTests);
    
    // Return 0 if all tests pass, 1 otherwise
    return (testsPassed == totalTests) ? 0 : 1;
}