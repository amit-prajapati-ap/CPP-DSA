
Node *merge2LL(Node *list1, Node *list2)
{
    Node *dHead = new Node(-1);
    Node *temp = dHead;

    while (list1 && list2)
    {
        if (list1->data < list2->data)
        {
            temp->child = list1;
            temp = list1;
            list1 = list1->child;
        }
        else
        {
            temp->child = list2;
            temp = list2;
            list2 = list2->child;
        }
        temp->next = nullptr;
    }

    temp->child = (list1) ? list1 : list2;
    if (dHead->child)
        dHead->child->next = nullptr;
    temp->child->next = nullptr; // add this extra line to ensure no RUNTIME error. It sets the child's next pointer of our temp NODE to nullptr.

    return dHead->child;
}

Node *flattenLinkedList(Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    Node *mergedHead = flattenLinkedList(head->next);
    head = merge2LL(head, mergedHead);

    return head;
}