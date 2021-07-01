Node *merge2Lists (Node *first, Node *second){
 if(!first)
   return second;
  if(!second)
    return first;
  
  Node *head1=first, *head2=second, *main_head=first;
  
  while(head1 and head2){
   Node *next=head1->next;
    head1->next=head2;
    head2->next=next;
    head1=head2->next;
    head2=next->next;
  }
  return main_head;
 
}
