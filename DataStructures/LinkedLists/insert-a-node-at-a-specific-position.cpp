/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position) {
    Node* _new = new Node;
    _new->data = data;
    
    if (head == NULL) return _new;
    
    if (position == 0) {
        _new->next = head;
        head->next = NULL;
        return _new;
    }
    
    int counter = 0;
    Node* current_node = head;
    
    while (counter < position - 1 && current_node->next != NULL) {
        current_node = current_node->next;
        counter++;
    }
    
    _new->next = current_node->next;
    current_node->next = _new;
    
    return head;
}

