    Node* segregate(Node *head) {
        
        if(!head or !head->next)
        return head;
        
        Node* zeroD=new Node(0);
        Node* oneD=new Node(0);
        Node* twoD=new Node(0);
        
        
        Node* zero=zeroD;
        Node* one=oneD;
        Node* two=twoD;
        
        Node*curr=head;
        
        while(curr){
            if(curr->data==0){
                zero->next=curr;
                zero=curr;
            } else if(curr->data==1){
                one->next=curr;
                one=curr;
            } else{
                two->next=curr;
                two=curr;
            }
            curr=curr->next;
        }
        
        zero->next=oneD->next?oneD->next:twoD->next;
        one->next=twoD->next;
        two->next=NULL;
        
        head=zeroD->next;
        
        delete zeroD;
        delete oneD;
        delete twoD;
        
        return head;
        
        
    }
