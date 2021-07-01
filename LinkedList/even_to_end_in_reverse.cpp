void rearrange(struct Node *odd){
        if(!odd || !odd->next || !odd->next->next)
        return;
        
        Node *curr=odd;
        Node *rev=curr->next;
        Node *revh=rev;
        
        while(curr && rev && rev->next){
            curr->next= curr->next->next;
            rev->next=curr->next->next;
            
            curr=curr->next;
            rev = rev->next;
        }
        
        Node *revnh=reverse(revh);
        curr->next=revnh;
        
    }
