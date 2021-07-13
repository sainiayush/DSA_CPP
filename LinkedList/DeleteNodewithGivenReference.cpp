void deleteNode(Node* node_ptr){
  
    if (node_ptr->next == NULL)
    {
        free(node_ptr);
        return;
    }
     
    Node* temp = node_ptr->next;
    node_ptr->data = temp->data;
    node_ptr->next = temp->next;
    free(temp);
}
