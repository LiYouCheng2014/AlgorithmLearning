Given a linked list, swap every two adjacent nodes and return its head.

**Example:**

```
Given 1->2->3->4, you should return the list as 2->1->4->3.
```

**Note:**

- Your algorithm should use only constant extra space.
- You may **not** modify the values in the list's nodes, only nodes itself may be changed.



给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

**示例:**

```
给定 1->2->3->4, 你应该返回 2->1->4->3.
```

**说明:**

- 你的算法只能使用常数的额外空间。
- **你不能只是单纯的改变节点内部的值**，而是需要实际的进行节点交换。



实现

```c
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    //头节点
    struct ListNode *pre = dummy;
    pre->next = head;
    
    while (pre->next != NULL && pre->next->next != NULL) {
        struct ListNode *a = pre->next; 
        struct ListNode *b = a->next;
        
        struct ListNode *temp = b->next;
        pre->next = b;
        b->next = a;
        a->next = temp;
        pre = a;
    }
    
    return dummy->next;
}
```

[Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)

