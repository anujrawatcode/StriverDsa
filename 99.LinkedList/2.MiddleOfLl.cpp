// Middle of the Linked List

// Given a non-empty, singly linked list with head node head, return a middle node of linked list.

// If there are two middle nodes, return the second middle node.

ListNode *middleNode(ListNode *head)
{
    int n = count(head);
    ListNode *temp = head;
    for (int i = 0; i < n / 2; i++)
        temp = temp->next;
    return temp;
}

ListNode *middleNode(Listnode *head)
{
    node *slow = head;
    node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}