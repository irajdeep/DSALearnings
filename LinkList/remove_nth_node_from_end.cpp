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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
  		vector <ListNode*> v;
        ListNode* tmp = head;
        int cnt = 0;
        
        while( tmp != NULL ){
            cnt += 1;
            v.push_back( tmp );
            tmp = tmp -> next;
        }
        cout << cnt << "\n";
        int id = cnt - n - 1;
        ListNode* rem = v[id];
        if(cnt == n) return head -> next;
        rem -> next = rem -> next -> next;
        return head;
    }
};

// Better solution using constant space , 2 pointer
