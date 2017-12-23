https://leetcode.com/problems/merge-two-sorted-lists/discuss/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * I fucking hate the fact how it took me so long to figure out one small case :(
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l2 == NULL) return l1;
        if(l1 == NULL) return l2;
        
        ListNode *l3;
        ListNode *tmpNode = new ListNode(0);
        l3 = tmpNode;
        
        while ( l1  && l2 ){
            if( l1->val <= l2->val ){
                tmpNode -> val = l1 -> val;
                l1 = l1 -> next;
            }
            else{
                tmpNode -> val = l2 -> val;
                l2 = l2 -> next;
            }
            tmpNode -> next = new ListNode(0);
            if(l1 && l2) tmpNode = tmpNode -> next;
        }
        if(l1) tmpNode->next = l1;
        if(l2) tmpNode->next = l2;
        return l3;
    }
};
