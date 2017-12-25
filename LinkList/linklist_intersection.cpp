#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <assert.h>

//const long long MAXN = 1e7;
 /*
 https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/
 */


using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  			
  			int sizeA = 0 , sizeB = 0;
  			ListNode *tmpA = headA;
  			ListNode *tmpB = headB;
  			
  			while( tmpA ){
  				sizeA += 1;
  				tmpA = tmpA -> next;
  			}
  			while( tmpB ){
  				sizeB += 1;
  				tmpB = tmpB -> next;
  			}      
  			ListNode *small , *large;
  			int rem = 0;
  			if(sizeA <= sizeB){
  				small = headA;
  				large = headB;
  				rem = sizeB - sizeA;
  			}
  			else{
  				small = headB;
  				large = headA;
  				rem = sizeA - sizeB;
  			}
  			
  			ListNode *inter = new ListNode(0);
  			int cnt = 1;
  			while(cnt <= rem){
  				large = large -> next;
  				cnt += 1;
  			}
  			
  			bool cont = false;
 
  			while (small && large){
  				if((small -> val == large -> val) && !cont){
  					inter -> val = small->val; 
  					cont = true ;
  				}
  				if(small -> val != large -> val){
  					cont = false;
  				}
  				small = small -> next;
  				large = large -> next;
  			}
  			if (!cont) return NULL;
  			return inter;
    }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(1);
	b -> next = c;

	ListNode *res = getIntersectionNode(a , b);
	cout << res->val << "\n";
	
    return 0;
}
