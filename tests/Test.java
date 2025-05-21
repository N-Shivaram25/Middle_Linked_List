package tests;

import solutions.ListNode;
import solutions.Solution;

public class Test {

    private static boolean runTest(int[] input, int expect, String name) {
        ListNode head = Solution.buildList(input);
        ListNode mid  = new Solution().middleNode(head);
        boolean ok    = mid != null && mid.val == expect;

        System.out.printf("Test %s: %s%n",
                          name, ok ? "✅ PASSED" :
                          "❌ FAILED – expected " + expect + ", got " +
                          (mid == null ? "null" : mid.val));
        return ok;
    }

    public static void main(String[] args) {
        System.out.println("Running tests…\n");

        int pass = 0;
        if (runTest(new int[]{1,2,3,4,5},           3, "1 (odd)")   ) pass++;
        if (runTest(new int[]{1,2,3,4,5,6},         4, "2 (even)" ) ) pass++;
        if (runTest(new int[]{42},                  42,"3 (single)")) pass++;
        if (runTest(new int[]{10,20},               20,"4 (two)")   ) pass++;
        if (runTest(new int[]{1,2,3,4,5,6,7,8,9,10},6,"5 (ten)")    ) pass++;

        System.out.printf("%nSummary: %d/5 tests passed%n", pass);
        System.exit(pass == 5 ? 0 : 1);
    }
}
