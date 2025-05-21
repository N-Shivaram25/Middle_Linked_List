import sys
import os

# Add the solutions directory to the Python path
sys.path.append(os.path.join(os.path.dirname(__file__), '..'))

# Import the solution module
from solutions.solution import Solution, ListNode

# Helper function to check if two lists are identical
def are_lists_equal(list1, list2):
    while list1 and list2:
        if list1.val != list2.val:
            return False
        list1 = list1.next
        list2 = list2.next
    return list1 is None and list2 is None

# Helper function to get the middle node using the naive way (for verification)
def get_middle_node_reference(head):
    # If the list is empty
    if head is None:
        return None
    
    # Count the number of nodes
    count = 0
    current = head
    while current:
        count += 1
        current = current.next
    
    # Find the middle node (floor division for even lengths)
    middle_index = count // 2
    current = head
    for i in range(middle_index):
        current = current.next
    
    return current

# Function to run a test case
def run_test(arr, test_name):
    # Create list from array
    head = Solution.build_list(arr)
    
    # Get the expected result
    expected = get_middle_node_reference(head)
    
    # Get the result from the solution
    solution = Solution()
    result = solution.middleNode(head)
    
    # Check if they match
    passed = result == expected
    
    # Print test results with colored output
    print(f"Test Case {test_name}: ", end="")
    if passed:
        print("✅ PASSED")
        if result:
            print(f"  Expected and actual middle nodes match at value: {result.val}")
        else:
            print("  Expected and actual middle nodes are both None")
    else:
        print("❌ FAILED")
        print(f"  Expected middle at value: {expected.val if expected else 'None'}, got: {result.val if result else 'None'}")
    
    return passed

def main():
    print("Running tests for middleNode function...\n")
    
    tests_passed = 0
    total_tests = 5
    
    # Test Case 1: Odd number of nodes
    arr1 = [1, 2, 3, 4, 5]
    if run_test(arr1, "1 (Odd length list)"): tests_passed += 1
    
    # Test Case 2: Even number of nodes
    arr2 = [1, 2, 3, 4, 5, 6]
    if run_test(arr2, "2 (Even length list)"): tests_passed += 1
    
    # Test Case 3: Single node
    arr3 = [42]
    if run_test(arr3, "3 (Single node)"): tests_passed += 1
    
    # Test Case 4: Two nodes
    arr4 = [10, 20]
    if run_test(arr4, "4 (Two nodes)"): tests_passed += 1
    
    # Test Case 5: 10 nodes
    arr5 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    if run_test(arr5, "5 (10 nodes)"): tests_passed += 1
    
    # Summary
    print(f"\nTest Summary: {tests_passed}/{total_tests} tests passed")
    
    # Return 0 if all tests pass, 1 otherwises
    return 0 if tests_passed == total_tests else 1

if __name__ == "__main__":
    sys.exit(main())