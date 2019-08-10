#include <stdio.h>
#include <set> //STL set的使用
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){};
};
//遍历链表，计算链表的长度
int get_list_length(ListNode *head){
    int len = 0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
};
//将指针向前移动至多出节点个数后面的位置
ListNode *foward_long_list(int long_len,int short_len,ListNode *head){

};

class Solution {
    public: 
        ListNode *getIntersectionNode(ListNode *headA,ListNode *headB){
        
        }  
};
int main(){
    ListNode a1(1);
    ListNode a2(2);
    ListNode b1(3);
    ListNode b2(4);
    ListNode b3(5);
    ListNode c1(6);
    ListNode c2(7);
    ListNode c3(8);
    a1.next = &a2;
    a2.next =&c1;
    c1.next = &c2;
    c2.next = &c3;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &c1;
    Solution solve;
    ListNode *result = solve.getIntersectionNode(&a1,&b1);
    printf("%d\n",result->val);
    return 0;
}