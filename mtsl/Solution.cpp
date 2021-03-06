#include "Solution.h"

int add_node(ListNode **head, int val)
{
    if (*head == NULL)
    {
        *head = new ListNode(val);
        return 0;
    }
    ListNode *p = *head;
    while (p->next != NULL)
        p = p->next;
    p->next = new ListNode(val);
    return 0;
}

int print_node(ListNode *l)
{
    if (l == NULL)
        printf("list is empty\n");
    printf("%d", l->val);
    l = l->next;
    while (l != NULL)
    {
        printf("->%d", l->val);
        l = l->next;
    }
    printf("\n");
    return 0;
}

ListNode *mergeTwoLists_(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
    {
        return l2;
    }
    if (l2 == nullptr)
    {
        return l1;
    }
    if (l1->val <= l2->val)
    {
        l1->next = mergeTwoLists_(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists_(l1, l2->next);
        return l2;
    }
}

ListNode *Solution::mergeTwoLists(ListNode *l1, ListNode *l2)
{
    return mergeTwoLists_(l1, l2);
    ListNode head0(0);
    ListNode *l = &head0;
    while (l1 != NULL && l2 != NULL)
    {
        ListNode **nextNode = (l1->val <= l2->val) ? &l1 : &l2;
        l->next = *nextNode;
        *nextNode = (*nextNode)->next;
        l = l->next;
    }
    l->next = l1 ? l1 : l2;

    return head0.next;
}