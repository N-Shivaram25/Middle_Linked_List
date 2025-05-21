#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Using slow and fast pointer approach (Floyd's Tortoise and Hare)
        // Fast pointer moves twice as fast as slow pointer
        // When fast reaches the end, slow will be at the middle
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    // Helper function to build a linked list from an array
    static ListNode* buildList(const std::vector<int>& values) {
        if (values.empty()) return nullptr;
        
        ListNode* head = new ListNode(values[0]);
        ListNode* current = head;
        
        for (size_t i = 1; i < values.size(); i++) {
            current->next = new ListNode(values[i]);
            current = current->next;
        }
        
        return head;
    }
    
    // Helper function to delete a linked list
    static void deleteList(ListNode* head) {
        while (head != nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    // Helper function to print a linked list
    static void printList(ListNode* head) {
        while (head != nullptr) {
            std::cout << head->val;
            if (head->next != nullptr) {
                std::cout << " -> ";
            }
            head = head->next;
        }
        std::cout << std::endl;
    }
};//ss