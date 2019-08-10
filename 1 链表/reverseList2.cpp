#include <stdio.h>
struct ListNode {
    int val;
    ListNode *next;//指针
    ListNode(int x) : val(x),next(NULL){};//构造函数
};
class Solution {
    public: 
        ListNode * reverseBetween(ListNode *head,int m ,int n){
            int change_len = n - m + 1 ; //计算需要逆置的节点个数
            ListNode *pre_head = NULL;//初始化开始逆置的节点的前驱
            ListNode *result = head;//最终转化后的链表的头节点
            while(head && --m){
                pre_head = head;
                head = head->next;//前进到需要逆置的开始位置
            }
            ListNode *modify_list_tail = head;//存储开始位置
            ListNode *new_head = NULL;//新的链表
            while(head && change_len){
                ListNode *next = head->next;
                head->next = new_head;
                new_head = head;
                head = next;
                change_len --;
            }
            //逆置完成后，modify_list_tail指向末尾,new_head指向开始
            modify_list_tail->next =head;//连接链表尾与逆置后的最后
            if(pre_head){
                pre_head->next = new_head;//连接链表前驱与逆置后的头节点
            }else{
                result = new_head;//如果pre_head为空，说明m == 1 
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
    ListNode *head = solve.reverseBetween(&a,2,4);
    while(head){
        printf("%d\n",head->val);
        head = head->next;
    }
    return 0;
}