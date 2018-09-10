/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // https://www.interviewbit.com/problems/reverse-linked-list/
ListNode* Solution::reverseList(ListNode* A) {
    ListNode* curr = A;
    ListNode* prev(0);
    ListNode* next = A;
    
    while(next != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}
