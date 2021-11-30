bool identicaltree(Node*p, Node*q){
  if(!p || !q) return p==q;

  return ((p->data && q->data)
   && identicaltree(p->left, q->left) 
   && identicaltree(p->right, q->right));
}
