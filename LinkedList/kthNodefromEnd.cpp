int kthNodefromEnd(Node *head,int k){
  
 Node *fast=head;
  
  for(int i=0;i<=k-1 &&fast;i++){
    fast=fast->next;
  }
  Node *slow=head;
  while(fast){
    slow=slow->next;
   fast=fast->next;
  }
  return slow->data;
}
