Node* addOneUtil(Node *h){
        int sum=0, carry=1;
        
        Node *curr=NULL, *res=h;
        
        while(h){
            sum=h->data+carry;
            
            carry=(sum>=10)?1:0;
            
            sum%=10;
            
            h->data=sum;
            curr=h;
            h = h->next;
        }
        if(carry>0){
            curr->next=new Node (carry);
        }
        return res;
    }
    Node *reverse(Node *h){
        Node *prev=NULL, *curr=h, *next=h->next;
        
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {   
        if(!head)
        return head;
        if(!head->next){
            int sum=0;
            head->data = head->data +1;
            if(head->data>9){
                sum = head->data %10;
                head->data/=10;
                Node *temp= new Node(sum);
                head->next=temp;
            }
            return head;
        }
        head=reverse(head);
        head=addOneUtil(head);
        return reverse(head);
        
    }
