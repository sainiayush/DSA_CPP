Node *reverse(Node *head){
       Node *curr=head;
       
       Node *prev=NULL, *next;
       
       while(curr){
           next=curr->next;
           curr->next=prev;
           prev=curr;
           curr=next;
       }
       return prev;
   }
bool isPalindrome(Node *head)
{
   Node *slow=head;
   Node *fast=head;
   
   while(fast and fast->next){
       slow=slow->next;
       fast=fast->next->next;
   }
   fast=head;
   slow=reverse(slow);
   
   while(slow){
       if(slow->data!=fast->data)
       return false;
       
       slow=slow->next;
       fast=fast->next;
   }
   return true;
}
