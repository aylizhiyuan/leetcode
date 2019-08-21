#include <stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int change_len = n - m + 1;
        ListNode *pre_head = NULL;
        ListNode *result = head;
        while(head && --m){
        	pre_head = head;
        	head = head->next;
        }
        ListNode *modify_list_tail = head;
        
        ListNode *new_head = NULL;
		while(head && change_len){
			ListNode *next = head->next;
			head->next = new_head;
			new_head = head;
			head = next;
			change_len--;
		}
		modify_list_tail->next = head;
		
		if (pre_head){
			pre_head->next = new_head;
		}
		else{
			result = new_head;
		}
		return result;
    }
};

int main(){	
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	Solution solve;
	ListNode *head = solve.reverseBetween(&a, 2, 4);	
	while(head){
		printf("%d\n", head->val);
		head = head->next;
	}
	return 0;
}
