package solutions;

/** Singly-linked list node */
public class ListNode {
    public int val;
    public ListNode next;

    public ListNode() {}
    public ListNode(int val)               { this.val = val; }
    public ListNode(int val, ListNode nxt) { this.val = val; this.next = nxt; }
}
