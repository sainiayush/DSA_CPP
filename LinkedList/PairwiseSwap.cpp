Node* pairWiseSwap(struct Node* head) {
        
        Node* dummy=new Node(0);
        dummy->next=head;
        
        Node* node=dummy;
        
        while(node){
            
            Node* first=node->next;
            
            Node* second=NULL;
            if(first)
                second=first->next;
                
                if(second){
                    Node* secondNext=second->next;
                    second->next=first;
                    node->next=second;
                    first->next=secondNext;
                    node=first;
                } else{
                    break;
                }
        }
        return dummy->next;
    }
