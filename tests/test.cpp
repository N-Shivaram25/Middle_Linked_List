#include <iostream>
#include <vector>
#include <string>
#include <cassert>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// External function declarations (defined in solution.cpp)
extern "C" {
    ListNode* middleNode(ListNode* head);
}

// Forward declarations for Solution class functions
class Solution {
public:
    static ListNode* buildList(const std::vector<int>& values);
    static void printList(ListNode* head);
    static void deleteList(ListNode* head);
};

// Helper function to get the middle node using the naive way (for verification)
ListNode* getMiddleNodeReference(ListNode* head) {
    // If the list is empty
    if (head == nullptr) return nullptr;
    
    // Count the number of nodes
    int count = 0;
    ListNode* current = head;
    while (current != nullptr) {
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
bool runTest(const std::vector<int>& arr, const char* testName) {
    // Create list from array
    ListNode* head = Solution::buildList(arr);
    
    // Get the expected result
    ListNode* expected = getMiddleNodeReference(head);
    
    // Get the result from the solution
    ListNode* result = middleNode(head);
    
    // Check if they match
    bool passed = (result == expected);
    
    // Print test results with colored output
    std::cout << "Test Case " << testName << ": ";
    if (passed) {
        std::cout << "✅ PASSED" << std::endl;
        std::cout << "  Expected and actual middle nodes match at value: " << result->val << std::endl;
    } else {
        std::cout << "❌ FAILED" << std::endl;
        std::cout << "  Expected middle at value: " << expected->val << ", got: " << result->val << std::endl;
    }
    
    // Clean up
    Solution::deleteList(head);
    
    return passed;
}

int main() {
    std::cout << "Running tests for middleNode function...\n\n";
    
    int testsPassed = 0;
    int totalTests = 5;
    
    // Test Case 1: Odd number of nodes
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    if (runTest(arr1, "1 (Odd length list)")) testsPassed++;
    
    // Test Case 2: Even number of nodes
    std::vector<int> arr2 = {1, 2, 3, 4, 5, 6};
    if (runTest(arr2, "2 (Even length list)")) testsPassed++;
    
    // Test Case 3: Single node
    std::vector<int> arr3 = {42};
    if (runTest(arr3, "3 (Single node)")) testsPassed++;
    
    // Test Case 4: Two nodes
    std::vector<int> arr4 = {10, 20};
    if (runTest(arr4, "4 (Two nodes)")) testsPassed++;
    
    // Test Case 5: 10 nodes
    std::vector<int> arr5 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    if (runTest(arr5, "5 (10 nodes)")) testsPassed++;
    
    // Summary
    std::cout << "\nTest Summary: " << testsPassed << "/" << totalTests << " tests passed" << std::endl;
    
    // Return 0 if all tests pass, 1 otherwise
    return (testsPassed == totalTests) ? 0 : 1;
}