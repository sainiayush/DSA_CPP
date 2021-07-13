struct node *reverse (struct node *head, int k)
    { 
     node* prev = NULL;
    node* curr = head;
    node* temp = NULL;
    node* tail = NULL;
    node* newHead = NULL;
    node* join = NULL;
    int t = 0;
 
    // Traverse till the end of the linked list
    while (curr) {
        t = k;
        join = curr;
        prev = NULL;
 
        // Reverse group of k nodes of the linked list
        while (curr && t--) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
 
        // Sets the new head of the input list
        if (!newHead)
            newHead = prev;
 
        /* Tail pointer keeps track of the last node
        of the k-reversed linked list. We join the
        tail pointer with the head of the next
        k-reversed linked list's head */
        if (tail)
            tail->next = prev;
 
        /* The tail is then updated to the last node
        of the next k-reverse linked list */
        tail = join;
    }
 
    /* newHead is new head of the input list */
    return newHead;
    }
