Node *intersectionList(Node *first, Node *second){
 
  Node *head=NULL, *tail=NULL;
  
  while(first && second){
   if(first->data==second->data){
    if(head==NULL){
     Node *temp=new Node(first->data);
     head=temp;
     tail=temp;
    } else{
      Node *temp = new Node(first->data);
      tail->next=temp;
      tail=temp;
    }
     first=first->next;
     second=second->next;
   } else if(first->data < second->data)
     first=first->next;
    else
      second=second->next;
  }
  return head;
}
