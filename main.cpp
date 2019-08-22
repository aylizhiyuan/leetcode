#include <stdio.h>
#include <set>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
class Solution {
    public: 
        ListNode *detectCycle(ListNode *head){
            
        }
};
int main(){
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(6);
    ListNode g(7);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = &c;
    Solution solve;
    ListNode *node = solve.detectCycle(&a);
    if(node){
        printf("%d\n",node->val);
    }else{
        printf("NULL\n");
    }
    return 0;
}