#include "../solutions/solution.cpp"
#include <iostream>
#include <vector>

// Reference logic for testing (not from user solution)
ListNode* getMiddleNodeReference(ListNode* head) {
    if (head == nullptr) return nullptr;

    int count = 0;
    ListNode* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }

    int middleIndex = count / 2;
    current = head;
    for (int i = 0; i < middleIndex; i++) {
        current = current->next;
    }

    return current;
}

bool runTest(Solution& sol, const std::vector<int>& arr, const char* testName) {
    ListNode* head = sol.buildList(arr);
    ListNode* expected = getMiddleNodeReference(head);
    ListNode* result = sol.middleNode(head);

    bool passed = (result == expected);

    std::cout << "Test Case " << testName << ": ";
    if (passed) {
        std::cout << "✅ PASSED" << std::endl;
    } else {
        std::cout << "❌ FAILED" << std::endl;
        std::cout << "  Expected value: " << expected->val << ", Got: " << result->val << std::endl;
    }

    sol.deleteList(head);
    return passed;
}

int main() {
    Solution sol;
    int passed = 0;
    int total = 5;

    if (runTest(sol, {1, 2, 3, 4, 5}, "1 (Odd length)")) passed++;
    if (runTest(sol, {1, 2, 3, 4, 5, 6}, "2 (Even length)")) passed++;
    if (runTest(sol, {42}, "3 (Single node)")) passed++;
    if (runTest(sol, {10, 20}, "4 (Two nodes)")) passed++;
    if (runTest(sol, {1,2,3,4,5,6,7,8,9,10}, "5 (Ten nodes)")) passed++;

    std::cout << "\nSummary: " << passed << "/" << total << " tests passed." << std::endl;
    return passed == total ? 0 : 1;
}
