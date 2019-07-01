/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    var first = null,temp = null,carry = 0;
    while(l1||l2||carry){
        //先从低位开始，计算每个链表中的val的和,并和进位的数字相加
        var s = (l1?l1.val:0) + (l2?l2.val:0) + carry;
        //得出当前的进位
        carry = s > 9 ? 1 : 0;
        //创建一个新的链表,初始值为进位的数字
        var t = new ListNode(carry?(s-10):s);
        //第一次循环的时候
        if(!first){
            first = temp = t;
        }else{
            //第N次循环的时候
            temp.next = t;
            temp = t;
        }
        l1 = l1 ? l1.next : null;
        l2 = l2 ? l2.next : null;
    }
    return first;
};