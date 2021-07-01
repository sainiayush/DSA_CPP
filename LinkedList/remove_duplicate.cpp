Node *removeDuplicate(Node *head){
  if(!head or !head->next)
    return head;
  
  Node *curr=head;
  while(curr){
   if(curr->data==curr->next->data){
     Node *temp=curr->next;
     curr->next=curr->next->next;
     delete(temp);
   } else
      curr=curr->next;
  }
}
