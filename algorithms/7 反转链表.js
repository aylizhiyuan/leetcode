/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    //设定两个指针，一个为cur它指向当前的头结点，另一个为pre指针
    var cur = head;
    var pre = null;
    // 1 ---> 2 ---> 3 ----> null
    // null <--- 1 <------ 2 <----- 3
    while(cur != null){
        //当前链表的后继元素
        var temp = cur.next;
        //交换位置
        cur.next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
};