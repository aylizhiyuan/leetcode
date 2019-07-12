/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    // 先指针先走n-1步
    let fast = head;
    for(let i=1; i<=n-1; i++) {
      fast = fast.next;
    }
    let slow = head;
    // 缓存要删除结点的前一个结点
    let pre = null;
    while(fast.next) {
      pre = slow;
      fast = fast.next;
      slow = slow.next;
    }
    // 如果要删除的结点是第一个结点的话，则直接返回slow.next
    if(pre === null) {
      return slow.next;
    }
    else {
      pre.next = slow.next;
    }
    return head;
  }