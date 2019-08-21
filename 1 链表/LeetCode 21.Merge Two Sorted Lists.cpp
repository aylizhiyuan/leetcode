
#include <stdio.h>

struct ListNode {
 	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode temp_head(0);
    	ListNode *pre = &temp_head;
    	while (l1 && l2){
	    	if (l1->val < l2->val){
	    		pre->next = l1;
	    		l1 = l1->next;
	    	}
	    	else{
	    		pre->next = l2;
	    		l2 = l2->next;
	    	}
	    	pre = pre->next;
	    }
	    if (l1){
    		pre->next = l1;
    	}
    	if (l2){
	    	pre->next = l2;
	    }
        return temp_head.next;
    }
};

int main(){
	ListNode a(1);
	ListNode b(4);
	ListNode c(6);
	ListNode d(0);
	ListNode e(5);
	ListNode f(7);
	a.next = &b;
	b.next = &c;
	d.next = &e;
	e.next = &f;
	Solution solve;
	ListNode *head = solve.mergeTwoLists(&a, &d);
	while(head){
		printf("%d\n", head->val);
		head = head->next;
	}
	return 0;
}
