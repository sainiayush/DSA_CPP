void frontBackSplit(Node *source, Node **front_half, Node **back){
  if(!source or !source->next){
   *front_half =source;
    *back=NULL;
  }
  Node *slow=source, *fast=source;
  
  while(fast){
    fast=fast->next;
    if(fast){
      fast=fast->next;
      slow=slow->next;
    }
  }
  *front_half=source;
  *back = slow->next;
  slow->next=NULL;
}
