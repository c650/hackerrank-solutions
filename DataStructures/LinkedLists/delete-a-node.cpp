/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position) {
    if (head == NULL) {
        return head;
    }
    
    if (position == 0) {
        Node* tmp = head;
        head = head->next;
        delete [] tmp;
        
        return head;
    }
    
    int counter = 0;
    Node* current = head;
    
    while (counter < position - 1 && current->next != NULL) {
        current = current->next;
        counter++;
    }
    
    Node* tmp = current->next->next;
    
    delete [] current->next;
    
    current->next = tmp;
    
    return head;
    
}

