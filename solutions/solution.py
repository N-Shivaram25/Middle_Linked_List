from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        Find the middle node of a linked list.
        For lists with even length, return the second middle node.
        
        Args:
            head: Head of the linked list
            
        Returns:
            The middle node of the linked list
        """
        # Using slow and fast pointer approach (Floyd's Tortoise and Hare)s
        # Fast pointer moves twice as fast as slow pointer
        # When fast reaches the end, slow will be at the middles
        slow = head
        fast = head
        
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
        return slow
    
    @staticmethod
    def build_list(values):
        """Create a linked list from a list of values."""
        if not values:
            return None
        
        head = ListNode(values[0])
        current = head
        
        for val in values[1:]:
            current.next = ListNode(val)
            current = current.next
            
        return head
    
    @staticmethod
    def print_list(head):
        """Print the linked list."""
        values = []
        current = head
        
        while current:
            values.append(str(current.val))
            current = current.next
            
        print(" -> ".join(values))