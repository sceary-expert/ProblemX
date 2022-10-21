/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        int t1 = node -> val, t2 = node -> next -> val;
        node -> next -> val = t1;
        node -> val = t2;
        node -> next = node -> next -> next;
        
        
    }
};