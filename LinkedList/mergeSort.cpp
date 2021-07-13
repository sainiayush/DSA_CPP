 void Split(Node*head, Node** a,Node** b){
        Node*fast=head->next;
        Node* slow=head;
        
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        *a=head;
        *b=slow->next;
        slow->next=NULL;
    }
    
    Node* SortedMerge(Node* a, Node* b){
        if(!a)
        return b;
        
        if(!b)
        return a;
        
        Node* head=NULL, *tail=NULL;
        
        if(a->data<b->data){
            head=a;
            tail=a;
            a=a->next;
        } else{
            head=b;
            tail=b;
            b=b->next;
        }
        
        while(a && b){
            if(a->data<b->data){
                tail->next=a;
                tail=a;
                a=a->next;
            } else{
                tail->next=b;
                tail=b;
                b=b->next;
            }
        }
        
        if(!a)
        tail->next=b;
        
        if(!b)
        tail->next=a;
        
        return head;
    }
    void MergeSort(Node** head_ref){
        Node* head=*head_ref;
        
        if(!head or !head->next)
        return;
        
        Node *a, *b;
        Split(head,&a,&b);
        
        MergeSort(&a);
        MergeSort(&b);
        
        *head_ref = SortedMerge(a,b);
    }
    
    Node* mergeSort(Node* head) {
        
        MergeSort(&head);
    }
