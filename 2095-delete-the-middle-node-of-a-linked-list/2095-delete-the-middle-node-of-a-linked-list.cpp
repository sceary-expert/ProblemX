/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast -> next && fast -> next -> next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            
        }
        if(fast -> next)
        {
            // even ----- delete next node
            slow -> next = slow -> next -> next;
            
        }
        else{
            
           if(slow -> next)
           {
               slow -> val = slow -> next -> val;
               slow -> next = slow -> next -> next;            
           }
            else return slow -> next;
            
        }
        return head;
            
        
    }
};