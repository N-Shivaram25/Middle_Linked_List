#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to find the middle node
struct ListNode* middleNode(struct ListNode* head) {
    //write code heer
}

// Helper function to create a linked list from an array
// This function is needed for tests
struct ListNode* buildList(int* arr, int size) {
    if (size == 0) return NULL;
    
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    
    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = arr[i];
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }
    
    return head;
}

// Helper function to print the list from a given node
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Helper function to free memory of a linked list
void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/* 
// Main function can be used for local testing, but should be commented out for GitHub Actions
int main() {
    // Create the linked list 1->2->3->4->5
    struct ListNode* head = buildList((int[]){1, 2, 3, 4, 5}, 5);
    
    // Find middle node
    struct ListNode* mid = middleNode(head);
    printf("Middle node onward: ");
    printList(mid); // Output: 3 4 5
    
    // Free the memory
    freeList(head);
    
    return 0;
}
*////