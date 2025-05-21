// Definition for singly-linked list
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

// External class declarations (defined in Solution.java)
class Solution {
    // External method declarations
    public ListNode middleNode(ListNode head);
    
    // Helper methods
    public static ListNode buildList(int[] values);
    public static void printList(ListNode head);
    public static void freeList(ListNode head);
}

public class Test {
    // Helper function to check if two lists are identical
    private static boolean areListsEqual(ListNode list1, ListNode list2) {
        while (list1 != null && list2 != null) {
            if (list1.val != list2.val) return false;
            list1 = list1.next;
            list2 = list2.next;
        }
        return (list1 == null && list2 == null);
    }
    
    // Helper function to get the reference middle node (for verification)
    private static ListNode getMiddleNodeReference(ListNode head) {
        // If the list is empty
        if (head == null) return null;
        
        // Count the nodes
        int count = 0;
        ListNode curr = head;
        while (curr != null) {
            count++;
            curr = curr.next;
        }
        
        // Find the middle (count/2)
        int middle = count / 2;
        curr = head;
        for (int i = 0; i < middle; i++) {
            curr = curr.next;
        }
        
        return curr;
    }
    
    // Run a test case
    private static boolean runTest(int[] arr, String testName) {
        // Create list from array
        ListNode head = Solution.buildList(arr);
        
        // Get the expected result
        ListNode expected = getMiddleNodeReference(head);
        
        // Get the result from the solution
        Solution solution = new Solution();
        ListNode result = solution.middleNode(head);
        
        // Check if they match
        boolean passed = (result == expected);
        
        // Print test results with colored output
        System.out.print("Test Case " + testName + ": ");
        if (passed) {
            System.out.println("✅ PASSED");
            if (result != null) {
                System.out.println("  Expected and actual middle nodes match at value: " + result.val);
            } else {
                System.out.println("  Expected and actual middle nodes are both null");
            }
        } else {
            System.out.println("❌ FAILED");
            System.out.println("  Expected middle at value: " + (expected != null ? expected.val : "null") + 
                             ", got: " + (result != null ? result.val : "null"));
        }
        
        return passed;
    }
    
    public static void main(String[] args) {
        System.out.println("Running tests for middleNode function...\n");
        
        int testsPassed = 0;
        int totalTests = 5;
        
        // Test Case 1: Odd number of nodes
        int[] arr1 = {1, 2, 3, 4, 5};
        if (runTest(arr1, "1 (Odd length list)")) testsPassed++;
        
        // Test Case 2: Even number of nodes
        int[] arr2 = {1, 2, 3, 4, 5, 6};
        if (runTest(arr2, "2 (Even length list)")) testsPassed++;
        
        // Test Case 3: Single node
        int[] arr3 = {42};
        if (runTest(arr3, "3 (Single node)")) testsPassed++;
        
        // Test Case 4: Two nodes
        int[] arr4 = {10, 20};
        if (runTest(arr4, "4 (Two nodes)")) testsPassed++;
        
        // Test Case 5: 10 nodes
        int[] arr5 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        if (runTest(arr5, "5 (10 nodes)")) testsPassed++;
        
        // Summary
        System.out.println("\nTest Summary: " + testsPassed + "/" + totalTests + " tests passed");
        
        // Exit with appropriate status
        System.exit(testsPassed == totalTests ? 0 : 1);
    }
}