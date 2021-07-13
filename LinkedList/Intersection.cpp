ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL){
        return NULL;
    }
    ListNode* l1=new ListNode();
    l1=headA;
    ListNode* l2=new ListNode();
    l2=headB;
    
    while(l1!=l2){
        
        l1=l1==NULL?headA:l1->next;
        l2=l2==NULL?headB:l2->next;
    }
    
    return l1;
        
    }
