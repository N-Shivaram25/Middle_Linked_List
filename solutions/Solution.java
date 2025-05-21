package solutions;

public class Solution {

    /** Returns the middle node of a singly-linked list. *///s
    public ListNode middleNode(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    /** Build a list from an int array and return the head. */
    public static ListNode buildList(int[] values) {
        if (values == null || values.length == 0) return null;

        ListNode head = new ListNode(values[0]);
        ListNode cur  = head;
        for (int i = 1; i < values.length; i++) {
            cur.next = new ListNode(values[i]);
            cur      = cur.next;
        }
        return head;
    }

    /** Print the list in “1 -> 2 -> 3” form. */
    public static void printList(ListNode head) {
        for (ListNode cur = head; cur != null; cur = cur.next) {
            System.out.print(cur.val + (cur.next != null ? " -> " : ""));
        }
        System.out.println();
    }
}
