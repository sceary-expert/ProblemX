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
    ListNode* removeElements(ListNode* head, int v) {
        ListNode* dummy = head;
        if(!head)return head;
        while(dummy != NULL && dummy -> next != NULL)
        {
            if(dummy -> next -> val == v)
            {
                dummy -> next = dummy -> next -> next;
            }
            else dummy = dummy -> next;
        }
        if(head -> val == v)return head -> next;
        return head;
    }
};