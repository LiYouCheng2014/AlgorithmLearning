Reverse a singly linked list.

**Example:**

```
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
```



反转一个单链表。

**示例:**

```
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
```

实现

```c
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *cur;
    struct ListNode *prev;
    cur = head;
    prev = NULL;
    while(cur) {
        struct ListNode *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}
```



[Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/description/)