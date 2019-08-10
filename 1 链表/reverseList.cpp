#include <stdio.h>
struct ListNode {
    int val;
    ListNode *next;//指针
    ListNode(int x) : val(x),next(NULL){};//构造函数
};
class Solution {
    public: 
        ListNode * reverseList(ListNode *head){
            ListNode *new_head = NULL; //创建一个新的链表
            while(head){
                ListNode *next = head->next; //备份head->next
                head->next = new_head; //第一个元素指向新链表
                new_head = head; //新链表的指针前移
                head = next; //遍历链表
            }
            return new_head;
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
    ListNode *head = &a;
    printf("before reverse:\n");
    while(head){
        printf("%d\n",head->val);
        head = head->next;
    }
    head = solve.reverseList(&a);
    printf("after reverse:\n");
    while(head){
        printf("%d\n",head->val);
        head = head->next;
    }
    return 0;
}