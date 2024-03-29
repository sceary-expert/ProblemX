/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 
 1 -> 2 -> 3 -> 4
 
 */
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode fastPointer = head;
        ListNode slowPointer = head;
        while(fastPointer != null && fastPointer.next != null)
        {
            fastPointer = fastPointer.next;
            if(fastPointer != null)fastPointer = fastPointer.next;
            slowPointer = slowPointer.next;
        }
        return slowPointer;
    }
}