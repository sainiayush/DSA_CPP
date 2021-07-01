Node* SortedList(Node *head,int x){
  Node *temp = new Node(x);
  
  if(!head)
    return temp;
  
  if(head->data>=temp->data){
   temp->next=head;
    return temp;
  }
  
  Node *curr=head;
  
  while(curr->next && curr->next->data > temp->data){
   curr=curr->next; 
  }
  
  temp->next=curr->next;
  curr->next=temp;
  return head;
}
